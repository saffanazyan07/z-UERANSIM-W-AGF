//
// Created by Hoonyong Park on 6/3/23.
//

#include "task.hpp"

#include <w_agf/nts.hpp>
#include <lib/rrc/encode.hpp>

#include <asn/rrc/ASN_RRC_DLInformationTransfer-IEs.h>
#include <asn/rrc/ASN_RRC_DLInformationTransfer.h>

static constexpr const int TIMER_ID_SI_BROADCAST = 1;
static constexpr const int TIMER_PERIOD_SI_BROADCAST = 10'000;

namespace nr::w_agf
{

DURrcTask::DURrcTask(TaskBase *base) : m_base{base}, m_ueCtx{}
{
    m_logger = base->logBase->makeUniqueLogger("rrc");
    m_config = m_base->config;
}

void DURrcTask::onStart()
{
    setTimer(TIMER_ID_SI_BROADCAST, TIMER_PERIOD_SI_BROADCAST);
}

void DURrcTask::onQuit()
{
    // todo
}

void DURrcTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::DU_RLS_TO_RRC: {
        handleRlsSapMessage(dynamic_cast<NmDURlsToRrc &>(*msg));
        break;
    }
    case NtsMessageType::DU_F1AP_TO_RRC: {
        auto &w = dynamic_cast<NmDUF1apToRrc &>(*msg);
        switch (w.present)
        {
        case NmDUF1apToRrc::RADIO_POWER_ON: {
            m_isBarred = false;
            triggerSysInfoBroadcast();
            break;
        }
        case NmDUF1apToRrc::DL_RRC_TRANSFER: {
            handleDownlinkRrcTransfer(w.buffer);
            break;
        }
//        case NmDUF1apToRrc::NAS_DELIVERY: {
//            handleDownlinkNasDelivery(w.ueId, w.pdu);
//            break;
//        }
        case NmDUF1apToRrc::AN_RELEASE: {
            releaseConnection(w.ueId);
            break;
        }
//        case NmDUF1apToRrc::PAGING:
//            handlePaging(w.uePagingTmsi, w.taiListForPaging);
//            break;
        default:
            break;
        }

        break;
    }
    case NtsMessageType::TIMER_EXPIRED: {
        auto w = dynamic_cast<NmTimerExpired &>(*msg);
        if (w.timerId == TIMER_ID_SI_BROADCAST)
        {
            setTimer(TIMER_ID_SI_BROADCAST, TIMER_PERIOD_SI_BROADCAST);
            onBroadcastTimerExpired();
        }
        break;
    }
    default:
        m_logger->unhandledNts(*msg);
        break;
    }
}

}
