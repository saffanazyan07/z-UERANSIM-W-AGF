//
// Created by Hoonyong Park on 5/20/23.
//

#include "cmd_handler.hpp"

#include <DU/app/task.hpp>
//#include <DU/gtp/task.hpp>
#include <DU/f1ap/task.hpp>
//#include <DU/rrc/task.hpp>
#include <DU/sctp/task.hpp>
#include <utils/common.hpp>
#include <utils/printer.hpp>

#define PAUSE_CONFIRM_TIMEOUT 3000
#define PAUSE_POLLING 10

namespace nr::DU
{

void DUCmdHandler::sendResult(const InetAddress &address, const std::string &output)
{
    m_base->cliCallbackTask->push(std::make_unique<app::NwCliSendResponse>(address, output, false));
}

void DUCmdHandler::sendError(const InetAddress &address, const std::string &output)
{
    m_base->cliCallbackTask->push(std::make_unique<app::NwCliSendResponse>(address, output, true));
}

void DUCmdHandler::pauseTasks()
{
//    m_base->gtpTask->requestPause();
//    m_base->rlsTask->requestPause();
    m_base->f1apTask->requestPause();
//    m_base->rrcTask->requestPause();
    m_base->sctpTask->requestPause();
}

void DUCmdHandler::unpauseTasks()
{
//    m_base->gtpTask->requestUnpause();
//    m_base->rlsTask->requestUnpause();
    m_base->f1apTask->requestUnpause();
//    m_base->rrcTask->requestUnpause();
    m_base->sctpTask->requestUnpause();
}

bool DUCmdHandler::isAllPaused()
{
//    if (!m_base->gtpTask->isPauseConfirmed())
//        return false;
//    //    if (!m_base->rlsTask->isPauseConfirmed())
//    //        return false;
    if (!m_base->f1apTask->isPauseConfirmed())
        return false;
//    if (!m_base->rrcTask->isPauseConfirmed())
//        return false;
    if (!m_base->sctpTask->isPauseConfirmed())
        return false;
    return true;
}

void DUCmdHandler::handleCmd(NmDUCliCommand &msg)
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
        sendError(msg.address, "DU is unable process command due to pausing timeout");
    }
    else
    {
        handleCmdImpl(msg);
    }

    unpauseTasks();
}

void DUCmdHandler::handleCmdImpl(NmDUCliCommand &msg)
{
    switch (msg.cmd->present)
    {
    case app::DUCliCommand::STATUS: {
        sendResult(msg.address, ToJson(m_base->appTask->m_statusInfo).dumpYaml());
        break;
    }
    case app::DUCliCommand::INFO: {
        sendResult(msg.address, ToJson(*m_base->config).dumpYaml());
        break;
    }
//    case app::CUCliCommand::AMF_LIST: {
//        Json json = Json::Arr({});
//        for (auto &amf : m_base->ngapTask->m_amfCtx)
//            json.push(Json::Obj({{"id", amf.first}}));
//        sendResult(msg.address, json.dumpYaml());
//        break;
//    }
//    case app::CUCliCommand::AMF_INFO: {
//        if (m_base->ngapTask->m_amfCtx.count(msg.cmd->amfId) == 0)
//            sendError(msg.address, "AMF not found with given ID");
//        else
//        {
//            auto amf = m_base->ngapTask->m_amfCtx[msg.cmd->amfId];
//            sendResult(msg.address, ToJson(*amf).dumpYaml());
//        }
//        break;
//    }
//    case app::CUCliCommand::UE_LIST: {
//        Json json = Json::Arr({});
//        for (auto &ue : m_base->ngapTask->m_ueCtx)
//        {
//            json.push(Json::Obj({
//                {"ue-id", ue.first},
//                {"ran-ngap-id", ue.second->ranUeNgapId},
//                {"amf-ngap-id", ue.second->amfUeNgapId},
//            }));
//        }
//        sendResult(msg.address, json.dumpYaml());
//        break;
//    }
//    case app::CUCliCommand::UE_COUNT: {
//        sendResult(msg.address, std::to_string(m_base->ngapTask->m_ueCtx.size()));
//        break;
//    }
//    case app::CUCliCommand::UE_RELEASE_REQ: {
//        if (m_base->ngapTask->m_ueCtx.count(msg.cmd->ueId) == 0)
//            sendError(msg.address, "UE not found with given ID");
//        else
//        {
//            auto ue = m_base->ngapTask->m_ueCtx[msg.cmd->ueId];
//            m_base->ngapTask->sendContextRelease(ue->ctxId, NgapCause::RadioNetwork_unspecified);
//            sendResult(msg.address, "Requesting UE context release");
//        }
//        break;
    //}
    }
}

}
