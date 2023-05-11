//
// Created by Hoonyong Park on 5/11/23.
//

#include "cmd_handler.hpp"

#include <CU/app/task.hpp>
#include <CU/gtp/task.hpp>
#include <CU/ngap/task.hpp>
#include <CU/rrc/task.hpp>
#include <CU/sctp/task.hpp>
#include <utils/common.hpp>
#include <utils/printer.hpp>

#define PAUSE_CONFIRM_TIMEOUT 3000
#define PAUSE_POLLING 10

namespace nr::CU
{

void CUCmdHandler::sendResult(const InetAddress &address, const std::string &output)
{
    m_base->cliCallbackTask->push(std::make_unique<app::NwCliSendResponse>(address, output, false));
}

void CUCmdHandler::sendError(const InetAddress &address, const std::string &output)
{
    m_base->cliCallbackTask->push(std::make_unique<app::NwCliSendResponse>(address, output, true));
}

void CUCmdHandler::pauseTasks()
{
    m_base->gtpTask->requestPause();
    //m_base->rlsTask->requestPause();
    m_base->ngapTask->requestPause();
    m_base->rrcTask->requestPause();
    m_base->sctpTask->requestPause();
}

void CUCmdHandler::unpauseTasks()
{
    m_base->gtpTask->requestUnpause();
    //m_base->rlsTask->requestUnpause();
    m_base->ngapTask->requestUnpause();
    m_base->rrcTask->requestUnpause();
    m_base->sctpTask->requestUnpause();
}

bool CUCmdHandler::isAllPaused()
{
    if (!m_base->gtpTask->isPauseConfirmed())
        return false;
//    if (!m_base->rlsTask->isPauseConfirmed())
//        return false;
    if (!m_base->ngapTask->isPauseConfirmed())
        return false;
    if (!m_base->rrcTask->isPauseConfirmed())
        return false;
    if (!m_base->sctpTask->isPauseConfirmed())
        return false;
    return true;
}

void CUCmdHandler::handleCmd(NmCUCliCommand &msg)
{
    pauseTasks();

    uint64_t currentTime = utils::CurrentTimeMillis();
    uint64_t endTime = currentTime + PAUSE_CONFIRM_TIMEOUT;

    bool isPaused = false;
    while (currentTime < endTime)
    {
        currentTime = utils::CurrentTimeMillis();
        if (isAllPaused())
        {
            isPaused = true;
            break;
        }
        utils::Sleep(PAUSE_POLLING);
    }

    if (!isPaused)
    {
        sendError(msg.address, "CU is unable process command due to pausing timeout");
    }
    else
    {
        handleCmdImpl(msg);
    }

    unpauseTasks();
}

void CUCmdHandler::handleCmdImpl(NmCUCliCommand &msg)
{
    switch (msg.cmd->present)
    {
    case app::CUCliCommand::STATUS: {
        sendResult(msg.address, ToJson(m_base->appTask->m_statusInfo).dumpYaml());
        break;
    }
    case app::CUCliCommand::INFO: {
        sendResult(msg.address, ToJson(*m_base->config).dumpYaml());
        break;
    }
    case app::CUCliCommand::AMF_LIST: {
        Json json = Json::Arr({});
        for (auto &amf : m_base->ngapTask->m_amfCtx)
            json.push(Json::Obj({{"id", amf.first}}));
        sendResult(msg.address, json.dumpYaml());
        break;
    }
    case app::CUCliCommand::AMF_INFO: {
        if (m_base->ngapTask->m_amfCtx.count(msg.cmd->amfId) == 0)
            sendError(msg.address, "AMF not found with given ID");
        else
        {
            auto amf = m_base->ngapTask->m_amfCtx[msg.cmd->amfId];
            sendResult(msg.address, ToJson(*amf).dumpYaml());
        }
        break;
    }
    case app::CUCliCommand::UE_LIST: {
        Json json = Json::Arr({});
        for (auto &ue : m_base->ngapTask->m_ueCtx)
        {
            json.push(Json::Obj({
                {"ue-id", ue.first},
                {"ran-ngap-id", ue.second->ranUeNgapId},
                {"amf-ngap-id", ue.second->amfUeNgapId},
            }));
        }
        sendResult(msg.address, json.dumpYaml());
        break;
    }
    case app::CUCliCommand::UE_COUNT: {
        sendResult(msg.address, std::to_string(m_base->ngapTask->m_ueCtx.size()));
        break;
    }
    case app::CUCliCommand::UE_RELEASE_REQ: {
        if (m_base->ngapTask->m_ueCtx.count(msg.cmd->ueId) == 0)
            sendError(msg.address, "UE not found with given ID");
        else
        {
            auto ue = m_base->ngapTask->m_ueCtx[msg.cmd->ueId];
            m_base->ngapTask->sendContextRelease(ue->ctxId, NgapCause::RadioNetwork_unspecified);
            sendResult(msg.address, "Requesting UE context release");
        }
        break;
    }
    }
}

} // namespace nr::CU