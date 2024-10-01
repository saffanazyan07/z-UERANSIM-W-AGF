//
// Created by Hoonyong Park on 6/3/23.
//

#include "task.hpp"

#include <DU/f1ap/task.hpp>
#include <lib/rrc/encode.hpp>

namespace nr::w_agf
{

void DURrcTask::handleRlsSapMessage(NmDURlsToRrc &msg)
{
    switch (msg.present)
    {
    case NmDURlsToRrc::SIGNAL_DETECTED: {
        m_logger->debug("UE[%d] new signal detected", msg.ueId);
        triggerSysInfoBroadcast();
        break;
    }
    case NmDURlsToRrc::UPLINK_RRC: {
        handleUplinkRrc(msg.ueId, msg.rrcChannel, msg.data);
        break;
    }
    }
}

} // namespace nr::w_agf
