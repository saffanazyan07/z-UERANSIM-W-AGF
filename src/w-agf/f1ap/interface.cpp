//
// Created by Hoonyong Park on 5/30/23.
//

#include "task.hpp"
#include "utils.hpp"

#include <DU/app/task.hpp>
#include <DU/rrc/task.hpp>
#include <DU/sctp/task.hpp>

namespace nr::DU
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

    *pdu = "F1SetupReqeust|" + std::to_string(m_base->config->getDUId());

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