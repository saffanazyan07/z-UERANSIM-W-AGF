//
// Created by Hoonyong Park on 5/11/23.
//

#ifndef UERANSIM_TASK_HPP
#define UERANSIM_TASK_HPP

#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>

#include <CU/types.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::CU
{

class CUAppTask : public NtsTask
{
  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;

    CUStatusInfo m_statusInfo;

    friend class CUCmdHandler;

  public:
    explicit CUAppTask(TaskBase *base);
    ~CUAppTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;
};

}

#endif // UERANSIM_TASK_HPP
