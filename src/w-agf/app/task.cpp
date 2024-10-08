//
// Created by Hoonyong Park on 5/20/23.
// Edited by Zyzy on 1/10/2024
//

#include "task.hpp"
#include "task.hpp"
#include "cmd_handler.hpp"

#include <w_agf/nts.hpp>

namespace nr::w_agf
{

DUAppTask::DUAppTask(TaskBase *base) : m_base{base}, m_statusInfo{}
{
    m_logger = m_base->logBase->makeUniqueLogger("app");
}

void DUAppTask::onStart()
{
}

void DUAppTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::DU_STATUS_UPDATE: {
        auto &w = dynamic_cast<NmDUStatusUpdate &>(*msg);
        switch (w.what)
        {
        case NmDUStatusUpdate::F1AP_IS_UP:
            m_statusInfo.isF1apUp = w.isF1apUp;
            break;
        }
        break;
    }
    case NtsMessageType::DU_CLI_COMMAND: {
        auto &w = dynamic_cast<NmDUCliCommand &>(*msg);
        WagfCmdHandler handler{m_base};
        handler.handleCmd(w);
        break;
    }
    default:
        m_logger->unhandledNts(*msg);
        break;
    }
}

void DUAppTask::onQuit()
{
}
}