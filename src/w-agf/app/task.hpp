//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>

#include <DU/types.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::DU
{

class DUAppTask : public NtsTask
{
  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;

    DUStatusInfo m_statusInfo;

    friend class DUCmdHandler;

  public:
    explicit DUAppTask(TaskBase *base);
    ~DUAppTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;
};

}
