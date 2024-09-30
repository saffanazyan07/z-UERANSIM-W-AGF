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

#include <DU/nts.hpp>
#include <DU/types.hpp>
#include <lib/rls/rls_pdu.hpp>
#include <lib/udp/server_task.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::DU
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

} // namespace nr::DU
