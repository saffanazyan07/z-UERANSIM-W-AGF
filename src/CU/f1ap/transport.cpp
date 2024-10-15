//
// Created by Hoonyong Park on 6/3/23.
// Edited by Zyzy on 1/10/24
//

#include "encode.hpp"
#include "task.hpp"
#include "utils.hpp"

#include <CU/app/task.hpp>
#include <CU/nts.hpp>
#include <CU/sctpServer/sctp_task.hpp>
#include <lib/asn/f1ap.hpp>
#include <lib/asn/utils.hpp>

#include <asn/f1ap/GNB-CU-UE-F1AP-ID.h>
#include <asn/f1ap/InitiatingMessage.h>
#include <asn/f1ap/F1AP-PDU.h>
#include <asn/f1ap/ProtocolIE-Field.h>
#include <asn/f1ap/GNB-DU-UE-F1AP-ID.h>
#include <asn/f1ap/SuccessfulOutcome.h>
#include <asn/f1ap/UnsuccessfulOutcome.h>


static e_Criticality FindCriticalityOfUserIe(F1AP_PDU *pdu, ProtocolIE_ID_t ieId)
{
    auto procedureCode =
        pdu->present == F1AP_PDU_PR_initiatingMessage   ? pdu->choice.initiatingMessage->procedureCode
        : pdu->present == F1AP_PDU_PR_successfulOutcome ? pdu->choice.successfulOutcome->procedureCode
                                                                 : pdu->choice.unsuccessfulOutcome->procedureCode;

    if (ieId == ProtocolIE_ID_id_UserLocationInformation)
    {
        return procedureCode == ASN_F1AP_ProcedureCode_id_InitialULRRCMessageTransfer ? Criticality_reject
                                                                           : Criticality_ignore;
    }

    if (ieId == ProtocolIE_ID_id_gNB_DU_UE_F1AP_ID || ieId == ProtocolIE_ID_id_gNB_CU_UE_F1AP_ID)
    {
        if (procedureCode == ProcedureCode_id_RerouteNASRequest)
        {
            return ieId == ProtocolIE_ID_id_gNB_DU_UE_F1AP_ID ? Criticality_reject
                                                                    : Criticality_ignore;
        }

        if (pdu->present == F1AP_PDU_PR_initiatingMessage)
        {
            if (procedureCode == ProcedureCode_id_UEContextReleaseRequest ||
                procedureCode == ProcedureCode_id_HandoverPreparation)
                return Criticality_reject;
        }

        if (procedureCode == ProcedureCode_id_PDUSessionResourceNotify ||
            procedureCode == ProcedureCode_id_PDUSessionResourceModifyIndication ||
            procedureCode == ProcedureCode_id_RRCInactiveTransitionReport ||
            procedureCode == ProcedureCode_id_HandoverNotification ||
            procedureCode == ProcedureCode_id_PathSwitchRequest ||
            procedureCode == ProcedureCode_id_HandoverCancel ||
            procedureCode == ProcedureCode_id_UplinkRANStatusTransfer ||
            procedureCode == ProcedureCode_id_InitialUEMessage ||
            procedureCode == ProcedureCode_id_DownlinkNASTransport ||
            procedureCode == ProcedureCode_id_UplinkNASTransport ||
            procedureCode == ProcedureCode_id_NASNonDeliveryIndication ||
            procedureCode == ProcedureCode_id_UplinkUEAssociatedNRPPaTransport ||
            procedureCode == ProcedureCode_id_UplinkNonUEAssociatedNRPPaTransport ||
            procedureCode == ProcedureCode_id_CellTrafficTrace ||
            procedureCode == ProcedureCode_id_TraceStart ||
            procedureCode == ProcedureCode_id_DeactivateTrace ||
            procedureCode == ProcedureCode_id_TraceFailureIndication ||
            procedureCode == ProcedureCode_id_LocationReport ||
            procedureCode == ProcedureCode_id_LocationReportingControl ||
            procedureCode == ProcedureCode_id_LocationReportingFailureIndication ||
            procedureCode == ProcedureCode_id_UERadioCapabilityInfoIndication)
            return Criticality_reject;
    }

    return Criticality_ignore;
}

namespace nr::CU
{

void F1apTask::recvF1apNonUe(int associatedAmf, F1AP_PDU *pdu)
{
    auto *amf = findAmfContext(associatedAmf);
    if (amf == nullptr)
    {
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        return;
    }

    char errorBuffer[1024];
    size_t len;

    if (asn_check_constraints(&asn_DEF_F1AP_PDU, pdu, errorBuffer, &len) != 0)
    {
        m_logger->err("F1AP PDU ASN constraint validation failed");
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        return;
    }

    ssize_t encoded;
    uint8_t *buffer;
    if (!ngap_encode::Encode(asn_DEF_F1AP_PDU, pdu, encoded, buffer))
        m_logger->err("F1AP APER encoding failed");
    else
    {
        auto msg = std::make_unique<NmCUSctp>(NmCUSctp::SEND_MESSAGE);
        msg->clientId = amf->ctxId;
        msg->stream = 0;
        msg->buffer = UniqueBuffer{buffer, static_cast<size_t>(encoded)};
        m_base->sctpTask->push(std::move(msg));

        if (m_base->nodeListener)
        {
            std::string xer = ngap_encode::EncodeXer(asn_DEF_F1AP_PDU, pdu);
            if (xer.length() > 0)
            {
                m_base->nodeListener->onSend(app::NodeType::CU, m_base->config->name, app::NodeType::AMF, amf->amfName,
                                             app::ConnectionType::NGAP, xer);
            }
        }
    }

    asn::Free(asn_DEF_F1AP_PDU, pdu);
}

void F1apTask::recvF1apUeAssociated(int ueId, F1AP_PDU *pdu)
{
    /* Find UE and AMF contexts */

    auto *ue = findUeContext(ueId);
    if (ue == nullptr)
    {
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        return;
    }

    auto *amf = findAmfContext(ue->associatedcuId);
    if (amf == nullptr)
    {
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        return;
    }

    /* Insert UE-related information elements */
    {
        if (ue->amfUeNgapId > 0)
        {
            asn::f1ap::AddProtocolIeIfUsable(
                *pdu, asn_DEF_ASN_NGAP_AMF_UE_NGAP_ID, ProtocolIE_ID_id_CU_UE_F1AP_ID,
                FindCriticalityOfUserIe(pdu, ProtocolIE_ID_id_CU_UE_F1AP_ID), [ue](void *mem) {
                    auto &id = *reinterpret_cast<ASN_NGAP_AMF_UE_NGAP_ID_t *>(mem);
                    asn::SetSigned64(ue->amfUeNgapId, id);
                });
        }

        asn::f1ap::AddProtocolIeIfUsable(
            *pdu, asn_DEF_GNB_DU_UE_F1AP_ID, ProtocolIE_ID_id_DU_UE_F1AP_ID,
            FindCriticalityOfUserIe(pdu, ProtocolIE_ID_id_DU_UE_F1AP_ID),
            [ue](void *mem) { *reinterpret_cast<ASN_NGAP_RAN_UE_NGAP_ID_t *>(mem) = ue->ranUeNgapId; });

        asn::f1ap::AddProtocolIeIfUsable(
            *pdu, asn_DEF_ASN_NGAP_UserLocationInformation, ProtocolIE_ID_id_UserLocationInformation,
            FindCriticalityOfUserIe(pdu, ProtocolIE_ID_id_UserLocationInformation), [this](void *mem) {
                auto *loc = reinterpret_cast<ASN_NGAP_UserLocationInformation *>(mem);
                loc->present = ASN_NGAP_UserLocationInformation_PR_userLocationInformationNR;
                loc->choice.userLocationInformationNR = asn::New<ASN_NGAP_UserLocationInformationNR>();

                auto &nr = loc->choice.userLocationInformationNR;
                nr->timeStamp = asn::New<ASN_NGAP_TimeStamp_t>();

                ngap_utils::ToPlmnAsn_Ref(m_base->config->plmn, nr->nR_CGI.pLMNIdentity);
                asn::SetBitStringLong<36>(m_base->config->nci, nr->nR_CGI.nRCellIdentity);
                ngap_utils::ToPlmnAsn_Ref(m_base->config->plmn, nr->tAI.pLMNIdentity);
                asn::SetOctetString3(nr->tAI.tAC, octet3{m_base->config->tac});
                asn::SetOctetString4(*nr->timeStamp, octet4{utils::CurrentTimeStamp().seconds32()});
            });
    }

    /* Encode and send the PDU */

    char errorBuffer[1024];
    size_t len;

    if (asn_check_constraints(&asn_DEF_F1AP_PDU, pdu, errorBuffer, &len) != 0)
    {
        m_logger->err("NGAP PDU ASN constraint validation failed");
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        return;
    }

    ssize_t encoded;
    uint8_t *buffer;
    if (!ngap_encode::Encode(asn_DEF_F1AP_PDU, pdu, encoded, buffer))
        m_logger->err("NGAP APER encoding failed");
    else
    {
        auto msg = std::make_unique<NmCUSctp>(NmCUSctp::SEND_MESSAGE);
        msg->clientId = amf->ctxId;
        msg->stream = ue->uplinkStream;
        msg->buffer = UniqueBuffer{buffer, static_cast<size_t>(encoded)};
        m_base->sctpTask->push(std::move(msg));

        if (m_base->nodeListener)
        {
            std::string xer = ngap_encode::EncodeXer(asn_DEF_F1AP_PDU, pdu);
            if (xer.length() > 0)
            {
                m_base->nodeListener->onSend(app::NodeType::CU, m_base->config->name, app::NodeType::AMF, amf->amfName,
                                             app::ConnectionType::NGAP, xer);
            }
        }
    }

    asn::Free(asn_DEF_F1AP_PDU, pdu);
}

void F1apTask::handleSctpMessage(int cuId, uint16_t stream, const UniqueBuffer &buffer)
{
    auto *amf = findAmfContext(cuId);
    if (amf == nullptr)
        return;

    auto *pdu = ngap_encode::Decode<F1AP_PDU>(asn_DEF_F1AP_PDU, buffer.data(), buffer.size());
    if (pdu == nullptr)
    {
        m_logger->err("APER decoding failed for SCTP message");
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        sendErrorIndication(cuId, NgapCause::Protocol_transfer_syntax_error);
        return;
    }

    if (m_base->nodeListener)
    {
        std::string xer = ngap_encode::EncodeXer(asn_DEF_F1AP_PDU, pdu);
        if (xer.length() > 0)
        {
            m_base->nodeListener->onReceive(app::NodeType::CU, m_base->config->name, app::NodeType::AMF, amf->amfName,
                                            app::ConnectionType::NGAP, xer);
        }
    }

    if (!handleSctpStreamId(amf->ctxId, stream, *pdu))
    {
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        return;
    }

    if (pdu->present == F1AP_PDU_PR_initiatingMessage)
    {
        auto value = pdu->choice.initiatingMessage->value;
        switch (value.present)
        {
        case InitiatingMessage__value_PR_ErrorIndication:
            receiveErrorIndication(amf->ctxId, &value.choice.ErrorIndication);
            break;
        case InitiatingMessage__value_PR_UEContextSetupRequest:
            receiveInitialContextSetup(amf->ctxId, &value.choice.InitialContextSetupRequest);
            break;
        case InitiatingMessage__value_PR_UEContextReleaseCommand:
            receiveContextRelease(amf->ctxId, &value.choice.UEContextReleaseCommand);
            break;
        case InitiatingMessage__value_PR_UEContextModificationRequest:
            receiveContextModification(amf->ctxId, &value.choice.UEContextModificationRequest);
            break;
        case InitiatingMessage__value_PR_F1SetupRequest:
            receiveSessionResourceSetupRequest(amf->ctxId, &value.choice.F1SetupRequest);
            break;
        case InitiatingMessage__value_PR_DLRRCMessageTransfer:
            receiveDownlinkNasTransport(amf->ctxId, &value.choice.DLRRCMessageTransfer);
            break;
        case InitiatingMessage__value_PR_GNBCUConfigurationUpdate:
            receiveAmfConfigurationUpdate(amf->ctxId, &value.choice.GNBCUConfigurationUpdate);
            break;
        case InitiatingMessage__value_PR_Paging:
            receivePaging(amf->ctxId, &value.choice.Paging);
            break;
        default:
            m_logger->err("Unhandled F1AP initiating-message received (%d)", value.present);
            break;
        }
    }
    else if (pdu->present == F1AP_PDU_PR_successfulOutcome)
    {
        auto value = pdu->choice.successfulOutcome->value;
        switch (value.present)
        {
        case SuccessfulOutcome__value_PR_F1SetupResponse:
            receiveNgSetupResponse(amf->ctxId, &value.choice.F1SetupResponse);
            break;
        default:
            m_logger->err("Unhandled F1AP successful-outcome received (%d)", value.present);
            break;
        }
    }
    else if (pdu->present == F1AP_PDU_PR_unsuccessfulOutcome)
    {
        auto value = pdu->choice.unsuccessfulOutcome->value;
        switch (value.present)
        {
        case UnsuccessfulOutcome__value_PR_F1SetupFailure:
            receiveNgSetupFailure(amf->ctxId, &value.choice.F1SetupFailure);
            break;
        default:
            m_logger->err("Unhandled F1AP unsuccessful-outcome received (%d)", value.present);
            break;
        }
    }
    else
    {
        m_logger->warn("Empty F1AP PDU ignored");
    }

    asn::Free(asn_DEF_F1AP_PDU, pdu);
}

bool F1apTask::handleSctpStreamId(int cuId, int stream, const F1AP_PDU &pdu)
{
    if (m_base->config->ignoreStreamIds)
        return true;

    auto *ptr =
        asn::f1ap::FindProtocolIeInPdu(pdu, asn_DEF_ASN_NGAP_UE_NGAP_IDs, ProtocolIE_ID_id_UE_NGAP_IDs);
    if (ptr != nullptr)
    {
        if (stream == 0)
        {
            m_logger->err("Received stream number == 0 in UE-associated signalling");
            sendErrorIndication(cuId, NgapCause::Protocol_unspecified);
            return false;
        }

        auto &ids = *reinterpret_cast<ASN_NGAP_UE_NGAP_IDs *>(ptr);
        auto *ue = findUeByNgapIdPair(cuId, ngap_utils::FindNgapIdPairFromAsnNgapIds(ids));
        if (ue == nullptr)
            return false;

        if (ue->downlinkStream == 0)
            ue->downlinkStream = stream;
        else if (ue->downlinkStream != stream)
        {
            m_logger->err("received stream number is inconsistent. received %d, expected :%d", stream,
                          ue->downlinkStream);
            sendErrorIndication(cuId, NgapCause::Protocol_unspecified);
            return false;
        }
    }
    else
    {
        ptr = asn::f1ap::FindProtocolIeInPdu(pdu, asn_DEF_GNB_DU_UE_F1AP_ID,
                                             ProtocolIE_ID_id_DU_UE_F1AP_ID);
        if (ptr != nullptr)
        {
            if (stream == 0)
            {
                m_logger->err("Received stream number == 0 in UE-associated signalling");
                sendErrorIndication(cuId, NgapCause::Protocol_unspecified);
                return false;
            }

            auto id = static_cast<int64_t>(*reinterpret_cast<GNB_DU_UE_F1AP_ID_t *>(ptr));
            auto *ue = findUeByDUId(id);
            if (ue == nullptr)
                return false;

            if (ue->downlinkStream == 0)
                ue->downlinkStream = stream;
            else if (ue->downlinkStream != stream)
            {
                m_logger->err("received stream number is inconsistent. received %d, expected :%d", stream,
                              ue->downlinkStream);
                sendErrorIndication(cuId, NgapCause::Protocol_unspecified);
                return false;
            }
        }
        else
        {
            if (stream != 0)
            {
                m_logger->err("Received stream number != 0 in non-UE-associated signalling");
                sendErrorIndication(cuId, NgapCause::Protocol_unspecified);
                return false;
            }
        }
    }

    return true;
}

} // namespace nr::CU




/*#include "task.hpp"

#include <vector>
#include <sstream>

using namespace std;

namespace nr::CU
{

vector<string> F1apTask::split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}

string F1apTask::Merge(vector<string> vec)
{
    string result = "";

    for (string &s : vec)
    {
        result = result + s + "|";
    }

    result = result.substr(0, result.length() - 1);

    return result;
}

void F1apTask::handleSctpMessage(int duId, uint16_t stream, const UniqueBuffer &buffer)
{
//    auto *du = findDuContext(duId);
//    if (du == nullptr)
//        return;

    auto pdu = decode(buffer);
    if (pdu == "")
    {
        m_logger->err("Decoding failed for SCTP message");
        //sendErrorIndication(cuId, NgapCause::Protocol_transfer_syntax_error);
        return;
    }
    else
        m_logger->debug("Received From Id %d :%s", duId, pdu.c_str());

    vector<string> msg = split(pdu, '|');

    if (msg.front() == "F1SetupRequest")
    {
        receiveF1SetupRequest(duId, stoi(msg.at(1)));
        m_logger->debug("F1 Setup Request received From %s", msg.at(1).c_str());
    }
    else if (msg.front() == "ULRrcMessageTransfer") //RRC Message
    {
        auto *du = findDuContext(duId);
        if (du == nullptr)
            return;

        if (msg.at(1) == "UL_CCCH")
        {
            string rrcMsg = Merge(vector<string>(msg.begin() + 2, msg.begin() + msg.size() + 1));
            receiveRrc_UL_CCCH_Message(duId, rrcMsg);
        }
        else if (msg.at(1) == "UL_DCCH")
        {
            string rrcMsg = Merge(vector<string>(msg.begin() + 2, msg.begin() + msg.size() + 1));
            receiveRrc_UL_DCCH_Message(duId, rrcMsg);
        }
        else
        {
            m_logger->err("Unknown RRC Channel");
        }
    }
*/
//    if (!handleSctpStreamId(du->ctxId, stream, pdu))
//    {
//        asn::Free(asn_DEF_F1AP_PDU, pdu);
//        return;
//    }
//
//    if (pdu->present == F1AP_PDU_PR_initiatingMessage)
//    {
//        auto value = pdu->choice.initiatingMessage->value;
//        switch (value.present)
//        {
//        case InitiatingMessage__value_PR_ErrorIndication:
//            receiveErrorIndication(amf->ctxId, &value.choice.ErrorIndication);
//            break;
//        case InitiatingMessage__value_PR_InitialContextSetupRequest:
//            receiveInitialContextSetup(amf->ctxId, &value.choice.InitialContextSetupRequest);
//            break;
//        case InitiatingMessage__value_PR_RerouteNASRequest:
//            receiveRerouteNasRequest(amf->ctxId, &value.choice.RerouteNASRequest);
//            break;
//        case InitiatingMessage__value_PR_UEContextReleaseCommand:
//            receiveContextRelease(amf->ctxId, &value.choice.UEContextReleaseCommand);
//            break;
//        case InitiatingMessage__value_PR_UEContextModificationRequest:
//            receiveContextModification(amf->ctxId, &value.choice.UEContextModificationRequest);
//            break;
//        case InitiatingMessage__value_PR_PDUSessionResourceSetupRequest:
//            receiveSessionResourceSetupRequest(amf->ctxId, &value.choice.PDUSessionResourceSetupRequest);
//            break;
//        case InitiatingMessage__value_PR_DownlinkNASTransport:
//            receiveDownlinkNasTransport(amf->ctxId, &value.choice.DownlinkNASTransport);
//            break;
//        case InitiatingMessage__value_PR_AMFConfigurationUpdate:
//            receiveAmfConfigurationUpdate(amf->ctxId, &value.choice.AMFConfigurationUpdate);
//            break;
//        case InitiatingMessage__value_PR_OverloadStart:
//            receiveOverloadStart(amf->ctxId, &value.choice.OverloadStart);
//            break;
//        case InitiatingMessage__value_PR_OverloadStop:
//            receiveOverloadStop(amf->ctxId, &value.choice.OverloadStop);
//            break;
//        case InitiatingMessage__value_PR_PDUSessionResourceReleaseCommand:
//            receiveSessionResourceReleaseCommand(amf->ctxId, &value.choice.PDUSessionResourceReleaseCommand);
//            break;
//        case InitiatingMessage__value_PR_Paging:
//            receivePaging(amf->ctxId, &value.choice.Paging);
//            break;
//        default:
//            m_logger->err("Unhandled NGAP initiating-message received (%d)", value.present);
//            break;
//        }
//    }
//    else if (pdu->present == F1AP_PDU_PR_successfulOutcome)
//    {
//        auto value = pdu->choice.successfulOutcome->value;
//        switch (value.present)
//        {
//        case SuccessfulOutcome__value_PR_NGSetupResponse:
//            receiveNgSetupResponse(amf->ctxId, &value.choice.NGSetupResponse);
//            break;
//        default:
//            m_logger->err("Unhandled NGAP successful-outcome received (%d)", value.present);
//            break;
//        }
//    }
//    else if (pdu->present == F1AP_PDU_PR_unsuccessfulOutcome)
//    {
//        auto value = pdu->choice.unsuccessfulOutcome->value;
//        switch (value.present)
//        {
//        case UnsuccessfulOutcome__value_PR_NGSetupFailure:
//            receiveNgSetupFailure(amf->ctxId, &value.choice.NGSetupFailure);
//            break;
//        default:
//            m_logger->err("Unhandled NGAP unsuccessful-outcome received (%d)", value.present);
//            break;
//        }
//    }
//    else
//    {
//        m_logger->warn("Empty NGAP PDU ignored");
//    }
/*}

void F1apTask::sendF1ap(int duId, std::string *pdu)
{
    auto *du = findDuContext(duId);
    if (du == nullptr)
    {
        delete pdu;
        return;
    }

    auto buffer = pdu->c_str();
    auto msg = std::make_unique<NmCUSctp>(NmCUSctp::SEND_MESSAGE);
    msg->clientId = du->ctxId;
    msg->stream = 0;
    msg->buffer = UniqueBuffer{(uint8_t *)buffer, pdu->length()};
    m_base->sctpServerTask->push(std::move(msg));
}

};
*/