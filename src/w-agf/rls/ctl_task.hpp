//
// Created by Hoonyong Park on 6/3/23.
//

#pragma once

#include "udp_task.hpp"

#include <w_agf/nts.hpp>
#include <w_agf/types.hpp>
#include <utils/nts.hpp>

namespace nr::w_agf
{

class RlsControlTask : public NtsTask
{
  private:
    std::unique_ptr<Logger> m_logger;
    uint64_t m_sti;
    NtsTask *m_mainTask;
    RlsUdpTask *m_udpTask;
    std::unordered_map<uint32_t, rls::PduInfo> m_pduMap;
    std::unordered_map<int, std::vector<uint32_t>> m_pendingAck;

  public:
    explicit RlsControlTask(TaskBase *base, uint64_t sti);
    ~RlsControlTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;

  public:
    void initialize(NtsTask *mainTask, RlsUdpTask *udpTask);

  private:
    void handleSignalDetected(int ueId);
    void handleSignalLost(int ueId);
    void handleRlsMessage(int ueId, rls::RlsMessage &msg);
    void handleDownlinkRrcDelivery(int ueId, uint32_t pduId, rrc::RrcChannel channel, OctetString &&data);
    void handleDownlinkDataDelivery(int ueId, int psi, OctetString &&data);
    void onAckControlTimerExpired();
    void onAckSendTimerExpired();
};

} // namespace nr::w_agf