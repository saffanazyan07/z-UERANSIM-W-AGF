
//
// Created by Saffana Zyan Dini on 5/10/24.
//

#include "task.hpp"
#include "utils.hpp"

#include <algorithm>

#include <CU/app/task.hpp>
#include <CU/rrc/task.hpp>
#include <CU/sctpServer/sctp_task.hpp>

#include <asn/f1ap/GNBDUConfigurationUpdate.h>
#include <asn/f1ap/GNBDUConfigurationUpdateFailure.h>
#include <asn/f1ap/GNB-DU-Name.h>
#include <asn/f1ap/BPLMN-ID-Info-Item.h>
#include <asn/f1ap/ErrorIndication.h>
#include <asn/f1ap/InitiatingMessage.h>
#include <asn/f1ap/F1AP-PDU.h>
#include <asn/f1ap/F1SetupRequest.h>
#include <asn/f1ap/ProtocolIE-Field.h>
#include <asn/f1ap/SliceSupportItem.h>

namespace nr::CU
{

template <typename T>
static void AssignDefaultAmfConfigs(NgapAmfContext *du, T *msg)
{
    auto *ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_AMFName);
    if (ie)
        du->amfName = asn::GetPrintableString(ie->AMFName);

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_RelativeAMFCapacity);
    if (ie)
        du->relativeCapacity = ie->RelativeAMFCapacity;

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_ServedGUAMIList);
    if (ie)
    {
        utils::ClearAndDelete(du->servedGuamiList);

        asn::ForeachItem(ie->ServedGUAMIList, [du](ASN_NGAP_ServedGUAMIItem &item) {
            auto servedGuami = new ServedGuami();
            if (item.backupAMFName)
                servedGuami->backupAmfName = asn::GetPrintableString(*item.backupAMFName);
            ngap_utils::GuamiFromAsn_Ref(item.gUAMI, servedGuami->guami);
            du->servedGuamiList.push_back(servedGuami);
        });
    }

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_PLMNSupportList);
    if (ie)
    {
        utils::ClearAndDelete(du->plmnSupportList);

        asn::ForeachItem(ie->PLMNSupportList, [du](ASN_NGAP_PLMNSupportItem &item) {
            auto plmnSupport = new PlmnSupport();
            ngap_utils::PlmnFromAsn_Ref(item.pLMNIdentity, plmnSupport->plmn);
            asn::ForeachItem(item.sliceSupportList, [plmnSupport](ASN_NGAP_SliceSupportItem &ssItem) {
                plmnSupport->sliceSupportList.slices.push_back(ngap_utils::SliceSupportFromAsn(ssItem));
            });
            du->plmnSupportList.push_back(plmnSupport);
        });
    }
}

void F1apTask::handleAssociationSetup(int cuId, int ascId, int inCount, int outCount)
{
    auto *du =  findDuContext(cuId);
    if (du != nullptr)
    {
        du->association.associationId = cuId;
        du->association.inStreams = inCount;
        du->association.outStreams = outCount;

        sendNgSetupRequest(du->ctxId);
    }
}

void F1apTask::handleAssociationShutdown(int cuId)
{
    auto *du =  findDuContext(cuId);
    if (du == nullptr)
        return;

    m_logger->err("Association terminated for AMF[%d]", cuId);
    m_logger->debug("Removing AMF context[%d]", cuId);

    du->state = EAmfState::NOT_CONNECTED;

    auto w = std::make_unique<NmCUSctp>(NmCUSctp::CONNECTION_CLOSE);
    w->clientId = cuId;
    m_base->sctpTask->push(std::move(w));

    deleteAmfContext(cuId);
}

void F1apTask::sendNgSetupRequest(int cuId)
{
    m_logger->debug("Sending NG Setup Request");

    auto *du =  findDuContext(cuId);
    if (du == nullptr)
        return;

    du->state = EAmfState::WAITING_NG_SETUP;

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

    recvF1apNonUe(cuId, pdu);
}

void F1apTask::receiveNgSetupResponse(int cuId, ASN_NGAP_NGSetupResponse *msg)
{
    m_logger->debug("NG Setup Response received");

    auto *du =  findDuContext(cuId);
    if (du == nullptr)
        return;

    AssignDefaultAmfConfigs(du, msg);

    du->state = EAmfState::CONNECTED;
    m_logger->info("NG Setup procedure is successful");

    if (!m_isInitialized && std::all_of(m_amfCtx.begin(), m_amfCtx.end(),
                                        [](auto &amfCtx) { return amfCtx.second->state == EAmfState::CONNECTED; }))
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
    auto *du =  findDuContext(cuId);
    if (du == nullptr)
        return;

    du->state = EAmfState::WAITING_NG_SETUP;

    auto *ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_Cause);
    if (ie)
        m_logger->err("NG Setup procedure is failed. Cause: %s", ngap_utils::CauseToString(ie->Cause).c_str());
    else
        m_logger->err("NG Setup procedure is failed.");
}

void F1apTask::receiveErrorIndication(int cuId, ASN_NGAP_ErrorIndication *msg)
{
    auto *du =  findDuContext(cuId);
    if (du == nullptr)
    {
        m_logger->err("Error indication received with not found AMF context");
        return;
    }

    auto *ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_Cause);
    if (ie)
        m_logger->err("Error indication received. Cause: %s", ngap_utils::CauseToString(ie->Cause).c_str());
    else
        m_logger->err("Error indication received.");
}

void F1apTask::sendErrorIndication(int cuId, NgapCause cause, int ueId)
{
    auto ieCause = asn::New<ASN_NGAP_ErrorIndicationIEs>();
    ieCause->id = ASN_NGAP_ProtocolIE_ID_id_Cause;
    ieCause->criticality = Criticality_ignore;
    ieCause->value.present = ASN_NGAP_ErrorIndicationIEs__value_PR_Cause;
    ngap_utils::ToCauseAsn_Ref(cause, ieCause->value.choice.Cause);

    m_logger->warn("Sending an error indication with cause: %s",
                   ngap_utils::CauseToString(ieCause->value.choice.Cause).c_str());

    auto *pdu = asn::f1ap::NewMessagePdu<ASN_NGAP_ErrorIndication>({ieCause});

    if (ueId > 0)
        recvF1apUeAssociated(ueId, pdu);
    else
        recvF1apNonUe(cuId, pdu);
}

void F1apTask::receiveAmfConfigurationUpdate(int cuId, ASN_NGAP_AMFConfigurationUpdate *msg)
{
    m_logger->debug("AMF configuration update received");

    auto *du =  findDuContext(cuId);
    if (du == nullptr)
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

    // TODO: AMF TNL modification is not supported
    if (tnlModified)
    {
        m_logger->err("TNL modification is not supported, rejecting AMF configuration update");

        auto *ieCause = asn::New<ASN_NGAP_AMFConfigurationUpdateFailureIEs>();
        ieCause->id = ASN_NGAP_ProtocolIE_ID_id_Cause;
        ieCause->criticality = Criticality_ignore;
        ieCause->value.present = ASN_NGAP_AMFConfigurationUpdateFailureIEs__value_PR_Cause;
        ngap_utils::ToCauseAsn_Ref(NgapCause::Transport_unspecified, ieCause->value.choice.Cause);

        auto *pdu = asn::f1ap::NewMessagePdu<ASN_NGAP_AMFConfigurationUpdateFailure>({ieCause});
        recvF1apNonUe(cuId, pdu);
    }
    else
    {
        AssignDefaultAmfConfigs(du, msg);

        auto *ieList = asn::New<ASN_NGAP_AMFConfigurationUpdateAcknowledgeIEs>();
        ieList->id = ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationSetupList;
        ieList->criticality = Criticality_ignore;
        ieList->value.present = ASN_NGAP_AMFConfigurationUpdateAcknowledgeIEs__value_PR_AMF_TNLAssociationSetupList;

        auto *pdu = asn::f1ap::NewMessagePdu<ASN_NGAP_AMFConfigurationUpdateAcknowledge>({ieList});
        recvF1apNonUe(cuId, pdu);
    }
}

void F1apTask::receiveOverloadStart(int cuId, ASN_NGAP_OverloadStart *msg)
{
    m_logger->debug("AMF overload start received");

    auto *du =  findDuContext(cuId);
    if (du == nullptr)
        return;

    du->overloadInfo = {};
    du->overloadInfo.status = EOverloadStatus::OVERLOADED;

    auto *ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_AMFOverloadResponse);
    if (ie && ie->OverloadResponse.present == ASN_NGAP_OverloadResponse_PR_overloadAction)
    {
        switch (ie->OverloadResponse.choice.overloadAction)
        {
        case ASN_NGAP_OverloadAction_reject_non_emergency_mo_dt:
            du->overloadInfo.indication.action = EOverloadAction::REJECT_NON_EMERGENCY_MO_DATA;
            break;
        case ASN_NGAP_OverloadAction_reject_rrc_cr_signalling:
            du->overloadInfo.indication.action = EOverloadAction::REJECT_SIGNALLING;
            break;
        case ASN_NGAP_OverloadAction_permit_emergency_sessions_and_mobile_terminated_services_only:
            du->overloadInfo.indication.action = EOverloadAction::ONLY_EMERGENCY_AND_MT;
            break;
        case ASN_NGAP_OverloadAction_permit_high_priority_sessions_and_mobile_terminated_services_only:
            du->overloadInfo.indication.action = EOverloadAction::ONLY_HIGH_PRI_AND_MT;
            break;
        default:
            m_logger->warn("AMF overload action [%d] could not understand",
                           (int)ie->OverloadResponse.choice.overloadAction);
            break;
        }
    }

    ie = asn::f1ap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_AMFTrafficLoadReductionIndication);
    if (ie)
        du->overloadInfo.indication.loadReductionPerc = static_cast<int>(ie->TrafficLoadReductionIndication);

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
    m_logger->debug("AMF overload stop received");

    // TODO
}

} // namespace nr::CU


//
// Created by Hoonyong Park on 6/2/23.
//
/*
#include "task.hpp"

#include <CU/sctpServer/sctp_task.hpp>

namespace nr::CU
{

void F1apTask::handleAssociationSetup(int duId, int inCount, int outCount)
{

}

void F1apTask::handleAssociationShutdown(int duId)
{
    auto *du = findDuContext(duId);
    if (du == nullptr)
        return;

    m_logger->err("Association terminated for DU[%d]", duId);
    m_logger->debug("Removing DU context[%d]", duId);

    auto w = std::make_unique<NmCUSctp>(NmCUSctp::CONNECTION_CLOSE);
    w->clientId = duId;
    m_base->sctpServerTask->push(std::move(w));

    deleteDuContext(duId);
}
// void F1apTask::receiveF1SetupRequest(int duId, int gNB_DU_ID /*, int cellId*/)

//{
//    createDuContext(duId, gNB_DU_ID /*, cellId*/);

 //   sendF1SetupResponse(duId);
//}
/*
void F1apTask::sendF1SetupResponse(int duId)
{
    m_logger->debug("Sending F1 Setup Response To %d", duId);

    auto *du = findDuContext(duId);
    if (du == nullptr)
        return;

    std::string *pdu = new std::string();

    *pdu = "F1SetupResponse|" + std::to_string(m_base->config->getCUId());

    //        auto *pdu = asn::f1ap::NewMessagePdu<F1SetupRequest>(
    //            {ieGlobalCUId, ieRanNodeName, ieSupportedTaList, iePagingDrx});

    sendF1ap(duId, pdu);
}

void F1apTask::sendDLRrcMessageTransfer(int duId, rrc::RrcChannel rrcChannel, std::string msg)
{
    auto *du = findDuContext(duId);
    if (du == nullptr)
        return;

    m_logger->debug("Sending DLRrcMessageTransfer To %d", duId);

    std::string *pdu = new std::string();

    *pdu = "DLRrcMessageTransfer|";

    switch (rrcChannel)
    {
    case rrc::RrcChannel::DL_CCCH: {
        *pdu = *pdu + "DL_CCCH|";
        break;
    }
    case rrc::RrcChannel::DL_DCCH: {
        *pdu = *pdu + "DL_DCCH|";
        break;
    }
    default:
        break;
    }

    *pdu = *pdu + msg;

    sendF1ap(duId, pdu);
}


}
*/
