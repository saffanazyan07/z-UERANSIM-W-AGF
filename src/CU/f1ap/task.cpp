//
// Created by Hoonyong Park on 5/20/23.
//

#include "task.hpp"

#include <utils/libc_error.hpp>

namespace nr::CU
{

F1apTask::F1apTask(TaskBase *base) : m_base{base}, m_logger{}, m_duCtx{}
{
    m_logger = m_base->logBase->makeUniqueLogger("f1ap");
}

void F1apTask::onStart()
{

}

void F1apTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::CU_SCTP: {
        auto &w = dynamic_cast<NmCUSctp &>(*msg);
        switch (w.present)
        {
        case NmCUSctp::ASSOCIATION_SETUP:
            handleAssociationSetup(w.clientId, w.inStreams, w.outStreams);
            break;
        case NmCUSctp::RECEIVE_MESSAGE:
            handleSctpMessage(w.clientId, w.stream, w.buffer);
            break;
        case NmCUSctp::ASSOCIATION_SHUTDOWN:
            handleAssociationShutdown(w.clientId);
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

}


}