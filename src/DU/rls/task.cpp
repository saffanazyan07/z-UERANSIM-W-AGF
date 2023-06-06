//
// Created by Hoonyong Park on 6/3/23.
//

#include "task.hpp"

//#include <DU/gtp/task.hpp>
#include <DU/rrc/task.hpp>
#include <utils/common.hpp>
#include <utils/random.hpp>

namespace nr::DU
{

DURlsTask::DURlsTask(TaskBase *base) : m_base{base}
{
    m_logger = m_base->logBase->makeUniqueLogger("rls");
    m_sti = Random::Mixed(base->config->name).nextUL();

    m_udpTask = new RlsUdpTask(base, m_sti, base->config->phyLocation);
    m_ctlTask = new RlsControlTask(base, m_sti);

    m_udpTask->initialize(m_ctlTask);
    m_ctlTask->initialize(this, m_udpTask);
}

void DURlsTask::onStart()
{
    m_udpTask->start();
    m_ctlTask->start();
}

void DURlsTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::DU_RLS_TO_RLS: {
        auto &w = dynamic_cast<NmDURlsToRls &>(*msg);
        switch (w.present)
        {
        case NmDURlsToRls::SIGNAL_DETECTED: {
            auto m = std::make_unique<NmDURlsToRrc>(NmDURlsToRrc::SIGNAL_DETECTED);
            m->ueId = w.ueId;
            m_base->rrcTask->push(std::move(m));
            break;
        }
        case NmDURlsToRls::SIGNAL_LOST: {
            m_logger->debug("UE[%d] signal lost", w.ueId);
            break;
        }
//        case NmDURlsToRls::UPLINK_DATA: {
//            auto m = std::make_unique<NmDURlsToGtp>(NmDURlsToGtp::DATA_PDU_DELIVERY);
//            m->ueId = w.ueId;
//            m->psi = w.psi;
//            m->pdu = std::move(w.data);
//            m_base->gtpTask->push(std::move(m));
//            break;
//        }
        case NmDURlsToRls::UPLINK_RRC: {
            auto m = std::make_unique<NmDURlsToRrc>(NmDURlsToRrc::UPLINK_RRC);
            m->ueId = w.ueId;
            m->rrcChannel = w.rrcChannel;
            m->data = std::move(w.data);
            m_base->rrcTask->push(std::move(m));
            break;
        }
        case NmDURlsToRls::RADIO_LINK_FAILURE: {
            m_logger->debug("radio link failure [%d]", (int)w.rlfCause);
            break;
        }
        case NmDURlsToRls::TRANSMISSION_FAILURE: {
            m_logger->debug("transmission failure [%s]", "");
            break;
        }
        default: {
            m_logger->unhandledNts(*msg);
            break;
        }
        }
        break;
    }
    case NtsMessageType::DU_RRC_TO_RLS: {
        auto &w = dynamic_cast<NmDURrcToRls &>(*msg);
        switch (w.present)
        {
        case NmDURrcToRls::RRC_PDU_DELIVERY: {
            auto m = std::make_unique<NmDURlsToRls>(NmDURlsToRls::DOWNLINK_RRC);
            m->ueId = w.ueId;
            m->rrcChannel = w.channel;
            m->pduId = 0;
            m->data = std::move(w.pdu);
            m_ctlTask->push(std::move(m));
            break;
        }
        }
        break;
    }
//    case NtsMessageType::DU_GTP_TO_RLS: {
//        auto &w = dynamic_cast<NmDUGtpToRls &>(*msg);
//        switch (w.present)
//        {
//        case NmDUGtpToRls::DATA_PDU_DELIVERY: {
//            auto m = std::make_unique<NmDURlsToRls>(NmDURlsToRls::DOWNLINK_DATA);
//            m->ueId = w.ueId;
//            m->psi = w.psi;
//            m->data = std::move(w.pdu);
//            m_ctlTask->push(std::move(m));
//            break;
//        }
//        }
//        break;
//    }
    default:
        m_logger->unhandledNts(*msg);
        break;
    }
}

void DURlsTask::onQuit()
{
    m_udpTask->quit();
    m_ctlTask->quit();
    delete m_udpTask;
    delete m_ctlTask;
}

} // namespace nr::DU