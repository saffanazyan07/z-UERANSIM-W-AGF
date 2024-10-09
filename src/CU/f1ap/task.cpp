//
// Created by Hoonyong Park on 5/20/23.
//

#include "task.hpp"

#include <typeinfo>
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
    std::unique_ptr<NtsMessage> msg = nullptr;
    msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::CU_RRC_TO_F1AP: {
        auto &w = dynamic_cast<NmCURrcToF1ap &>(*msg);
        switch (w.present)
        {
        case NmCURrcToF1ap::SEND_MESSAGE2:
            sendDLRrcMessageTransfer(w.duId, w.rrcChannel, w.data);
            break;
        }
    }
    case NtsMessageType::CU_SCTP: {
        if (typeid(*msg) == typeid(NmCUSctp))
        {
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