//
// Created by Hoonyong Park on 5/25/23.
//

#pragma once

#include <DU/nts.hpp>
#include <DU/types.hpp>

namespace nr::DU
{

class F1apTask : public NtsTask
{

  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;

    F1apCUContext *m_cuCtx;

    friend class CUCmdHandler;

  public:
    explicit F1apTask(TaskBase *base);
    ~F1apTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;

  private:
    void createCUContext(const DUCUConfig &config);

};

}
