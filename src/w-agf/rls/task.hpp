//
// Created by Hoonyong Park on 6/3/23.
//

#pragma once

#include "ctl_task.hpp"
#include "udp_task.hpp"

#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>

#include <w_agf/nts.hpp>
#include <w_agf/types.hpp>
#include <lib/rls/rls_pdu.hpp>
#include <lib/udp/server_task.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::w_agf
{

class DURlsTask : public NtsTask
{
  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;

    RlsUdpTask *m_udpTask;
    RlsControlTask *m_ctlTask;

    uint64_t m_sti;

    friend class GnbCmdHandler;

  public:
    explicit DURlsTask(TaskBase *base);
    ~DURlsTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;
};

} // namespace nr::w_agf
