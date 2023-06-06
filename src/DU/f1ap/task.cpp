//
// Created by Hoonyong Park on 5/25/23.
//

#include "task.hpp"

#include <DU/sctp/task.hpp>

namespace nr::DU
{

F1apTask::F1apTask(TaskBase *base) : m_base{base}, m_logger{}, m_cuCtx{}
{
    m_logger = m_base->logBase->makeUniqueLogger("f1ap");
}

void F1apTask::onStart()
{
    for (auto &cuConfig : m_base->config->cuConfigs)
        createCUContext(cuConfig);
    if (m_cuCtx == nullptr)
        m_logger->warn("No CU configuration is provided");

    auto msg = std::make_unique<NmDUSctp>(NmDUSctp::CONNECTION_REQUEST);
    msg->clientId = 0;
    msg->localAddress = m_base->config->f1apIp;
    msg->localPort = 0;
    msg->remoteAddress = m_cuCtx->address;
    msg->remotePort = m_cuCtx->port;
    msg->ppid = sctp::PayloadProtocolId::F1AP;
    msg->associatedTask = this;
    m_base->sctpTask->push(std::move(msg));
}

void F1apTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::DU_RRC_TO_F1AP: {
        auto &w = dynamic_cast<NmDURrcToF1ap &>(*msg);
        switch (w.present)
        {
        case NmDURrcToF1ap::UL_RRC_TRANSFER: {
            handleULRrcTransfer(w.rrcChannel, w.buffer);
            break;
        }
        }
        break;
    }
    case NtsMessageType::DU_SCTP: {
        auto &w = dynamic_cast<NmDUSctp &>(*msg);
        switch (w.present)
        {
        case NmDUSctp::ASSOCIATION_SETUP:
            handleAssociationSetup(w.associationId, w.inStreams, w.outStreams);
            break;
        case NmDUSctp::RECEIVE_MESSAGE:
            handleSctpMessage(w.stream, w.buffer);
            break;
        case NmDUSctp::ASSOCIATION_SHUTDOWN:
            handleAssociationShutdown();
            break;
        default:
            m_logger->unhandledNts(*msg);
            break;
        }
        break;
    }
    default: {
        m_logger->unhandledNts(*msg);
        break;
    }
    }
}

void F1apTask::onQuit()
{
    delete m_cuCtx;
}



}