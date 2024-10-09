//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "task.hpp"

#include <CU/ngap/task.hpp>
#include <lib/rrc/encode.hpp>

namespace nr::CU
{

//void CURrcTask::handleRlsSapMessage(NmCURlsToRrc &msg)
//{
//    switch (msg.present)
//    {
//    case NmCURlsToRrc::SIGNAL_DETECTED: {
//        m_logger->debug("UE[%d] new signal detected", msg.ueId);
//        triggerSysInfoBroadcast();
//        break;
//    }
//    case NmCURlsToRrc::UPLINK_RRC: {
//        handleUplinkRrc(msg.ueId, msg.rrcChannel, msg.data);
//        break;
//    }
//    }
//}

} // namespace nr::CU