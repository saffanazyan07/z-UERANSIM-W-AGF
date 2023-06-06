//
// Created by Hoonyong Park on 5/11/23.
//

#include "task.hpp"

#include <CU/nts.hpp>
//#include <CU/rls/task.hpp>
#include <lib/rrc/encode.hpp>

#include <asn/rrc/ASN_RRC_DLInformationTransfer-IEs.h>
#include <asn/rrc/ASN_RRC_DLInformationTransfer.h>

static constexpr const int TIMER_ID_SI_BROADCAST = 1;
static constexpr const int TIMER_PERIOD_SI_BROADCAST = 10'000;

namespace nr::CU
{

CURrcTask::CURrcTask(TaskBase *base) : m_base{base}, m_ueCtx{}, m_tidCounter{}
{
    m_logger = base->logBase->makeUniqueLogger("rrc");
    m_config = m_base->config;
}

void CURrcTask::onStart()
{
    setTimer(TIMER_ID_SI_BROADCAST, TIMER_PERIOD_SI_BROADCAST);
}

void CURrcTask::onQuit()
{
    // todo
}

void CURrcTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::CU_F1AP_TO_RRC: {
        auto &w = dynamic_cast<NmCUF1apToRrc &>(*msg);
        switch (w.present)
        {
        case NmCUF1apToRrc::RECEIVE_CCCH_Message: {
            handleUplinkRrcCCCH(w.duId, w.gNB_DU_ID, w.data);
            break;
        }
        case NmCUF1apToRrc::RECEIVE_DCCH_Message: {
            break;
        }
        }
        //handleRlsSapMessage(dynamic_cast<NmCURlsToRrc &>(*msg));
        break;
    }
    case NtsMessageType::CU_NGAP_TO_RRC: {
        auto &w = dynamic_cast<NmCUNgapToRrc &>(*msg);
        switch (w.present)
        {
        case NmCUNgapToRrc::RADIO_POWER_ON: {
            m_isBarred = false;
            triggerSysInfoBroadcast();
            break;
        }
        case NmCUNgapToRrc::NAS_DELIVERY: {
            handleDownlinkNasDelivery(w.ueId, w.pdu);
            break;
        }
        case NmCUNgapToRrc::AN_RELEASE: {
            releaseConnection(w.ueId);
            break;
        }
        case NmCUNgapToRrc::PAGING:
            handlePaging(w.uePagingTmsi, w.taiListForPaging);
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

} // namespace nr::CU
