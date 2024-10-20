//
// Created by Zyzy on 1/10/24
//
#include "task.hpp"
#include "utils.hpp"

#include <algorithm>

#include <w-agf/app/task.hpp>
#include <w-agf/rrc/task.hpp>
#include <w-agf/sctp/task.hpp>

#include <asn/f1ap/GNBCUConfigurationUpdate.h>
#include <asn/f1ap/GNBCUConfigurationUpdateFailure.h>
#include <asn/f1ap/GNB-CU-Name.h>
#include <asn/f1ap/BPLMN-ID-Info-Item.h>
#include <asn/f1ap/ErrorIndication.h>
#include <asn/f1ap/InitiatingMessage.h>
#include <asn/f1ap/F1AP-PDU.h>
#include <asn/f1ap/F1SetupRequest.h>
#include <asn/f1ap/ProtocolIE-Field.h>
#include <asn/f1ap/SliceSupportItem.h>


namespace nr::w_agf
{

template <typename T>
static void AssignDefaultCUConfigs(F1apCUContext *cu, T *msg)
{
    auto *ie = asn::f1ap::GetProtocolIe(msg, ProtocolIE_ID_id_gNB_CU_Name);
    if (ie)
        cu->cuName = asn::GetPrintableString(ie->AMFName);

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_RelativeAMFCapacity);
    if (ie)
        cu->relativeCapacity = ie->RelativeAMFCapacity;

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_ServedGUAMIList);
    if (ie)
    {
        utils::ClearAndDelete(cu->servedGuamiList);

        asn::ForeachItem(ie->ServedGUAMIList, [cu](ASN_NGAP_ServedGUAMIItem &item) {
            auto servedGuami = new ServedGuami();
            if (item.backupAMFName)
                servedGuami->backupCuName = asn::GetPrintableString(*item.backupAMFName);
            ngap_utils::GuamiFromAsn_Ref(item.gUAMI, servedGuami->guami);
            cu->servedGuamiList.push_back(servedGuami);
        });
    }

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_PLMNSupportList);
    if (ie)
    {
        utils::ClearAndDelete(cu->plmnSupportList);

        asn::ForeachItem(ie->PLMNSupportList, [cu](ASN_NGAP_PLMNSupportItem &item) {
            auto plmnSupport = new PlmnSupport();
            ngap_utils::PlmnFromAsn_Ref(item.pLMNIdentity, plmnSupport->plmn);
            asn::ForeachItem(item.sliceSupportList, [plmnSupport](ASN_NGAP_SliceSupportItem &ssItem) {
                plmnSupport->sliceSupportList.slices.push_back(ngap_utils::SliceSupportFromAsn(ssItem));
            });
            cu->plmnSupportList.push_back(plmnSupport);
        });
    }
}

void F1apTask::handleAssociationSetup(int cuId, int ascId, int inCount, int outCount)
{
    auto *cu = findCuContext(cuId);
    if (cu != nullptr)
    {
        cu->association.associationId = cuId;
        cu->association.inStreams = inCount;
        cu->association.outStreams = outCount;

        sendF1SetupRequest(cu->ctxId);
    }
}

void F1apTask::handleAssociationShutdown(int cuId)
{
    auto *cu = findCuContext(cuId);
    if (cu == nullptr)
        return;

    m_logger->err("Association terminated for CU[%d]", cuId);
    m_logger->debug("Removing CU context[%d]", cuId);

    cu->state = ECuState::NOT_CONNECTED;

    auto w = std::make_unique<NmCUSctp>(NmCUSctp::CONNECTION_CLOSE);
    w->clientId = cuId;
    m_base->sctpTask->push(std::move(w));

    deleteCuContext(cuId);
}

void F1apTask::sendF1SetupRequest(int cuId)
{
    m_logger->debug("Sending NG Setup Request");

    auto *cu = findCuContext(cuId);
    if (cu == nullptr)
        return;

    cu->state = ECuState::WAITING_NG_SETUP;

    // TODO: this procedure also re-initialises the NGAP UE-related contexts (if any)
    //  and erases all related signalling connections in the two nodes like an NG Reset procedure would do.
    //  More on 38.413 8.7.1.1

    auto *globalCUId = asn::New<ASN_NGAP_GlobalGNB_ID>();
    globalCUId->gNB_ID.present = ASN_NGAP_GNB_ID_PR_gNB_ID;
    asn::SetBitString(globalCUId->gNB_ID.choice.gNB_ID,
                      octet4{m_base->config->getCUId() << (32 - m_base->config->CUIdLength)},
                      static_cast<size_t>(m_base->config->CUIdLength));
    asn::SetOctetString3(globalCUId->pLMNIdentity, ngap_utils::PlmnToOctet3(m_base->config->plmn));

    auto *ieGlobalCUId = asn::New<ASN_NGAP_NGSetupRequestIEs>();
    ieGlobalCUId->id = ASN_NGAP_ProtocolIE_ID_id_GlobalRANNodeID;
    ieGlobalCUId->criticality = ASN_NGAP_Criticality_reject;
    ieGlobalCUId->value.present = ASN_NGAP_NGSetupRequestIEs__value_PR_GlobalRANNodeID;
    ieGlobalCUId->value.choice.GlobalRANNodeID.present = ASN_NGAP_GlobalRANNodeID_PR_globalGNB_ID;
    ieGlobalCUId->value.choice.GlobalRANNodeID.choice.globalGNB_ID = globalCUId;

    auto *ieRanNodeName = asn::New<ASN_NGAP_NGSetupRequestIEs>();
    ieRanNodeName->id = ASN_NGAP_ProtocolIE_ID_id_RANNodeName;
    ieRanNodeName->criticality = Criticality_ignore;
    ieRanNodeName->value.present = ASN_NGAP_NGSetupRequestIEs__value_PR_RANNodeName;
    asn::SetPrintableString(ieRanNodeName->value.choice.RANNodeName, m_base->config->name);

    auto *broadcastPlmn = asn::New<ASN_NGAP_BroadcastPLMNItem>();
    asn::SetOctetString3(broadcastPlmn->pLMNIdentity, ngap_utils::PlmnToOctet3(m_base->config->plmn));
    for (auto &nssai : m_base->config->nssai.slices)
    {
        auto *item = asn::New<ASN_NGAP_SliceSupportItem>();
        asn::SetOctetString1(item->s_NSSAI.sST, static_cast<uint8_t>(nssai.sst));
        if (nssai.sd.has_value())
        {
            item->s_NSSAI.sD = asn::New<ASN_NGAP_SD_t>();
            asn::SetOctetString3(*item->s_NSSAI.sD, octet3{nssai.sd.value()});
        }
        asn::SequenceAdd(broadcastPlmn->tAISliceSupportList, item);
    }

    auto *supportedTa = asn::New<ASN_NGAP_SupportedTAItem>();
    asn::SetOctetString3(supportedTa->tAC, octet3{m_base->config->tac});
    asn::SequenceAdd(supportedTa->broadcastPLMNList, broadcastPlmn);

    auto *ieSupportedTaList = asn::New<ASN_NGAP_NGSetupRequestIEs>();
    ieSupportedTaList->id = ASN_NGAP_ProtocolIE_ID_id_SupportedTAList;
    ieSupportedTaList->criticality = ASN_NGAP_Criticality_reject;
    ieSupportedTaList->value.present = ASN_NGAP_NGSetupRequestIEs__value_PR_SupportedTAList;
    asn::SequenceAdd(ieSupportedTaList->value.choice.SupportedTAList, supportedTa);

    auto *iePagingDrx = asn::New<ASN_NGAP_NGSetupRequestIEs>();
    iePagingDrx->id = ASN_NGAP_ProtocolIE_ID_id_DefaultPagingDRX;
    iePagingDrx->criticality = Criticality_ignore;
    iePagingDrx->value.present = ASN_NGAP_NGSetupRequestIEs__value_PR_PagingDRX;
    iePagingDrx->value.choice.PagingDRX = ngap_utils::PagingDrxToAsn(m_base->config->pagingDrx);

    auto *pdu = asn::f1ap::NewMessagePdu<ASN_NGAP_NGSetupRequest>(
        {ieGlobalCUId, ieRanNodeName, ieSupportedTaList, iePagingDrx});

    sendNgapNonUe(cuId, pdu);
}

void F1apTask::receiveNgSetupResponse(int cuId, ASN_NGAP_NGSetupResponse *msg)
{
    m_logger->debug("NG Setup Response received");

    auto *cu = findCuContext(cuId);
    if (cu == nullptr)
        return;

    AssignDefaultCuConfigs(cu, msg);

    cu->state = ECuState::CONNECTED;
    m_logger->info("NG Setup procedure is successful");

    if (!m_isInitialized && std::all_of(m_amfCtx.begin(), m_amfCtx.end(),
                                        [](auto &amfCtx) { return amfCtx.second->state == ECuState::CONNECTED; }))
    {
        m_isInitialized = true;

        auto update = std::make_unique<NmCUStatusUpdate>(NmCUStatusUpdate::NGAP_IS_UP);
        update->isNgapUp = true;
        m_base->appTask->push(std::move(update));

        m_base->rrcTask->push(std::make_unique<NmCUNgapToRrc>(NmCUNgapToRrc::RADIO_POWER_ON));
    }
}

void F1apTask::receiveNgSetupFailure(int cuId, ASN_NGAP_NGSetupFailure *msg)
{
    auto *cu = findCuContext(cuId);
    if (cu == nullptr)
        return;

    cu->state = ECuState::WAITING_NG_SETUP;

    auto *ie = asn::f1ap::GetProtocolIe(msg, ProtocolIE_ID_id_Cause);
    if (ie)
        m_logger->err("NG Setup procedure is failed. Cause: %s", ngap_utils::CauseToString(ie->Cause).c_str());
    else
        m_logger->err("NG Setup procedure is failed.");
}

void F1apTask::receiveErrorIndication(int cuId, ASN_NGAP_ErrorIndication *msg)
{
    auto *cu = findCuContext(cuId);
    if (cu == nullptr)
    {
        m_logger->err("Error indication received with not found CU context");
        return;
    }

    auto *ie = asn::f1ap::GetProtocolIe(msg, ProtocolIE_ID_id_Cause);
    if (ie)
        m_logger->err("Error indication received. Cause: %s", ngap_utils::CauseToString(ie->Cause).c_str());
    else
        m_logger->err("Error indication received.");
}

void F1apTask::sendErrorIndication(int cuId, NgapCause cause, int ueId)
{
    auto ieCause = asn::New<ASN_NGAP_ErrorIndicationIEs>();
    ieCause->id = ProtocolIE_ID_id_Cause;
    ieCause->criticality = Criticality_ignore;
    ieCause->value.present = ASN_NGAP_ErrorIndicationIEs__value_PR_Cause;
    ngap_utils::ToCauseAsn_Ref(cause, ieCause->value.choice.Cause);

    m_logger->warn("Sending an error indication with cause: %s",
                   ngap_utils::CauseToString(ieCause->value.choice.Cause).c_str());

    auto *pdu = asn::f1ap::NewMessagePdu<ASN_NGAP_ErrorIndication>({ieCause});

    if (ueId > 0)
        sendNgapUeAssociated(ueId, pdu);
    else
        sendNgapNonUe(cuId, pdu);
}

void F1apTask::receiveCuConfigurationUpdate(int cuId, ASN_NGAP_AMFConfigurationUpdate *msg)
{
    m_logger->debug("CU configuration update received");

    auto *cu = findCuContext(cuId);
    if (cu == nullptr)
        return;

    bool tnlModified = false;

    auto *ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationToAddList);
    if (ie && ie->AMF_TNLAssociationToAddList.list.count > 0)
        tnlModified = true;

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationToRemoveList);
    if (ie && ie->AMF_TNLAssociationToRemoveList.list.count > 0)
        tnlModified = true;

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationToUpdateList);
    if (ie && ie->AMF_TNLAssociationToUpdateList.list.count > 0)
        tnlModified = true;

    // TODO: CU TNL modification is not supported
    if (tnlModified)
    {
        m_logger->err("TNL modification is not supported, rejecting CU configuration update");

        auto *ieCause = asn::New<ASN_NGAP_AMFConfigurationUpdateFailureIEs>();
        ieCause->id = ProtocolIE_ID_id_Cause;
        ieCause->criticality = Criticality_ignore;
        ieCause->value.present = ASN_NGAP_AMFConfigurationUpdateFailureIEs__value_PR_Cause;
        ngap_utils::ToCauseAsn_Ref(NgapCause::Transport_unspecified, ieCause->value.choice.Cause);

        auto *pdu = asn::f1ap::NewMessagePdu<ASN_NGAP_AMFConfigurationUpdateFailure>({ieCause});
        sendNgapNonUe(cuId, pdu);
    }
    else
    {
        AssignDefaultCuConfigs(cu, msg);

        auto *ieList = asn::New<ASN_NGAP_AMFConfigurationUpdateAcknowledgeIEs>();
        ieList->id = ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationSetupList;
        ieList->criticality = Criticality_ignore;
        ieList->value.present = ASN_NGAP_AMFConfigurationUpdateAcknowledgeIEs__value_PR_AMF_TNLAssociationSetupList;

        auto *pdu = asn::f1ap::NewMessagePdu<ASN_NGAP_AMFConfigurationUpdateAcknowledge>({ieList});
        sendNgapNonUe(cuId, pdu);
    }
}

void F1apTask::receiveOverloadStart(int cuId, ASN_NGAP_OverloadStart *msg)
{
    m_logger->debug("CU overload start received");

    auto *cu = findCuContext(cuId);
    if (cu == nullptr)
        return;

    cu->overloadInfo = {};
    cu->overloadInfo.status = EOverloadStatus::OVERLOADED;

    auto *ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_AMFOverloadResponse);
    if (ie && ie->OverloadResponse.present == ASN_NGAP_OverloadResponse_PR_overloadAction)
    {
        switch (ie->OverloadResponse.choice.overloadAction)
        {
        case ASN_NGAP_OverloadAction_reject_non_emergency_mo_dt:
            cu->overloadInfo.indication.action = EOverloadAction::REJECT_NON_EMERGENCY_MO_DATA;
            break;
        case ASN_NGAP_OverloadAction_reject_rrc_cr_signalling:
            cu->overloadInfo.indication.action = EOverloadAction::REJECT_SIGNALLING;
            break;
        case ASN_NGAP_OverloadAction_permit_emergency_sessions_and_mobile_terminated_services_only:
            cu->overloadInfo.indication.action = EOverloadAction::ONLY_EMERGENCY_AND_MT;
            break;
        case ASN_NGAP_OverloadAction_permit_high_priority_sessions_and_mobile_terminated_services_only:
            cu->overloadInfo.indication.action = EOverloadAction::ONLY_HIGH_PRI_AND_MT;
            break;
        default:
            m_logger->warn("CU overload action [%d] could not understand",
                           (int)ie->OverloadResponse.choice.overloadAction);
            break;
        }
    }

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_AMFTrafficLoadReductionIndication);
    if (ie)
        cu->overloadInfo.indication.loadReductionPerc = static_cast<int>(ie->TrafficLoadReductionIndication);

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_OverloadStartNSSAIList);
    if (ie)
    {
        // TODO
        /*asn::ForeachItem(ie->OverloadStartNSSAIList, [](auto &item) {
            item.sliceOverloadList;
        });*/
    }
}

void F1apTask::receiveOverloadStop(int cuId, ASN_NGAP_OverloadStop *msg)
{
    m_logger->debug("CU overload stop received");

    // TODO
}

} // namespace nr::CU



//
// Created by Hoonyong Park on 5/30/23.
/*
#include "task.hpp"
#include "utils.hpp"

#include <w_agf/app/task.hpp>
#include <w_agf/rrc/task.hpp>
#include <w_agf/sctp/task.hpp>

namespace nr::w_agf
{

void F1apTask::handleAssociationSetup(int ascId, int inCount, int outCount)
{
    auto *cu = m_cuCtx;
    if (cu != nullptr)
    {
        cu->association.associationId = 0;
        cu->association.inStreams = inCount;
        cu->association.outStreams = outCount;

        sendF1SetupRequest();
    }
}

void F1apTask::handleAssociationShutdown()
{
    auto *cu = m_cuCtx;
    if (cu == nullptr)
        return;

    m_logger->err("Association terminated for CU[%d]", 0);
    m_logger->debug("Removing CU context[%d]", 0);

    cu->state = ECUState::NOT_CONNECTED;

    auto w = std::make_unique<NmDUSctp>(NmDUSctp::CONNECTION_CLOSE);
    w->clientId = 0;
    m_base->sctpTask->push(std::move(w));

    deleteCUContext();
}

void F1apTask::sendF1SetupRequest()
{
    m_logger->debug("Sending F1 Setup Request");

    auto *cu = m_cuCtx;
    if (cu == nullptr)
        return;

    cu->state = ECUState::WAITING_F1_SETUP;

    std::string *pdu = new std::string();

    *pdu = "F1SetupRequest|" + std::to_string(m_base->config->getDUId());

//        auto *pdu = asn::f1ap::NewMessagePdu<F1SetupRequest>(
//            {ieGlobalCUId, ieRanNodeName, ieSupportedTaList, iePagingDrx});

    sendF1ap(pdu);
}

void F1apTask::receiveF1SetupResponse()
{
    auto *cu = m_cuCtx;

    cu->state = ECUState::CONNECTED;

    m_logger->info("F1 Setup procedure is successful");

    auto update = std::make_unique<NmDUStatusUpdate>(NmDUStatusUpdate::F1AP_IS_UP);
    update->isF1apUp = true;
    m_base->appTask->push(std::move(update));

    m_base->rrcTask->push(std::make_unique<NmDUF1apToRrc>(NmDUF1apToRrc::RADIO_POWER_ON));
}

void F1apTask::receiveDLRrcMessageTransfer(std::vector<std::string> msg)
{
    auto w = std::make_unique<NmDUF1apToRrc>(NmDUF1apToRrc::DL_RRC_TRANSFER);
    w->buffer = msg;
    m_base->rrcTask->push(std::move(w));
}



}
*/