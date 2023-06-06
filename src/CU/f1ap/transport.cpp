//
// Created by Hoonyong Park on 6/3/23.
//

#include "task.hpp"

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
        //sendErrorIndication(amfId, NgapCause::Protocol_transfer_syntax_error);
        return;
    }
    else
        m_logger->debug("Received From Id %d :%s", duId, pdu.c_str());

    vector<string> msg = split(pdu, '|');

    if (msg.front() == "F1SetupReqeust")
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

//    if (!handleSctpStreamId(du->ctxId, stream, pdu))
//    {
//        asn::Free(asn_DEF_ASN_NGAP_NGAP_PDU, pdu);
//        return;
//    }
//
//    if (pdu->present == ASN_NGAP_NGAP_PDU_PR_initiatingMessage)
//    {
//        auto value = pdu->choice.initiatingMessage->value;
//        switch (value.present)
//        {
//        case ASN_NGAP_InitiatingMessage__value_PR_ErrorIndication:
//            receiveErrorIndication(amf->ctxId, &value.choice.ErrorIndication);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_InitialContextSetupRequest:
//            receiveInitialContextSetup(amf->ctxId, &value.choice.InitialContextSetupRequest);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_RerouteNASRequest:
//            receiveRerouteNasRequest(amf->ctxId, &value.choice.RerouteNASRequest);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_UEContextReleaseCommand:
//            receiveContextRelease(amf->ctxId, &value.choice.UEContextReleaseCommand);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_UEContextModificationRequest:
//            receiveContextModification(amf->ctxId, &value.choice.UEContextModificationRequest);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_PDUSessionResourceSetupRequest:
//            receiveSessionResourceSetupRequest(amf->ctxId, &value.choice.PDUSessionResourceSetupRequest);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_DownlinkNASTransport:
//            receiveDownlinkNasTransport(amf->ctxId, &value.choice.DownlinkNASTransport);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_AMFConfigurationUpdate:
//            receiveAmfConfigurationUpdate(amf->ctxId, &value.choice.AMFConfigurationUpdate);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_OverloadStart:
//            receiveOverloadStart(amf->ctxId, &value.choice.OverloadStart);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_OverloadStop:
//            receiveOverloadStop(amf->ctxId, &value.choice.OverloadStop);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_PDUSessionResourceReleaseCommand:
//            receiveSessionResourceReleaseCommand(amf->ctxId, &value.choice.PDUSessionResourceReleaseCommand);
//            break;
//        case ASN_NGAP_InitiatingMessage__value_PR_Paging:
//            receivePaging(amf->ctxId, &value.choice.Paging);
//            break;
//        default:
//            m_logger->err("Unhandled NGAP initiating-message received (%d)", value.present);
//            break;
//        }
//    }
//    else if (pdu->present == ASN_NGAP_NGAP_PDU_PR_successfulOutcome)
//    {
//        auto value = pdu->choice.successfulOutcome->value;
//        switch (value.present)
//        {
//        case ASN_NGAP_SuccessfulOutcome__value_PR_NGSetupResponse:
//            receiveNgSetupResponse(amf->ctxId, &value.choice.NGSetupResponse);
//            break;
//        default:
//            m_logger->err("Unhandled NGAP successful-outcome received (%d)", value.present);
//            break;
//        }
//    }
//    else if (pdu->present == ASN_NGAP_NGAP_PDU_PR_unsuccessfulOutcome)
//    {
//        auto value = pdu->choice.unsuccessfulOutcome->value;
//        switch (value.present)
//        {
//        case ASN_NGAP_UnsuccessfulOutcome__value_PR_NGSetupFailure:
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
}

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