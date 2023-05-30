//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include "CU/sctpServer/sctp_task.hpp"

#include <CU/nts.hpp>
#include <CU/types.hpp>
#include <lib/app/monitor.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::CU
{

class F1apTask : public NtsTask
{
  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;


    SctpServerTask *m_sctpServer;

    friend class CUCmdHandler;

  public:
    explicit F1apTask(TaskBase *base);
    ~F1apTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;

  private:



};
}