//
// Created by Hoonyong Park on 6/2/23.
//
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

void F1apTask::receiveF1SetupRequest(int duId, int gNB_DU_ID /*, int cellId*/)
{
    createDuContext(duId, gNB_DU_ID /*, cellId*/);

    sendF1SetupResponse(duId);
}

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