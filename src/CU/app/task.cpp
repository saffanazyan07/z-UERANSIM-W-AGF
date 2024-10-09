//
// Created by Hoonyong Park on 5/11/23.
//

#include "task.hpp"
#include "cmd_handler.hpp"

#include <CU/nts.hpp>

namespace nr::CU
{

CUAppTask::CUAppTask(TaskBase *base) : m_base{base}, m_statusInfo{}
{
    m_logger = m_base->logBase->makeUniqueLogger("app");
}

void CUAppTask::onStart()
{
}

void CUAppTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::CU_STATUS_UPDATE: {
        auto &w = dynamic_cast<NmCUStatusUpdate &>(*msg);
        switch (w.what)
        {
        case NmCUStatusUpdate::NGAP_IS_UP:
            m_statusInfo.isNgapUp = w.isNgapUp;
            break;
        }
        break;
    }
    case NtsMessageType::CU_CLI_COMMAND: {
        auto &w = dynamic_cast<NmCUCliCommand &>(*msg);
        CUCmdHandler handler{m_base};
        handler.handleCmd(w);
        break;
    }
    default:
        m_logger->unhandledNts(*msg);
        break;
    }
}

void CUAppTask::onQuit()
{
}
}