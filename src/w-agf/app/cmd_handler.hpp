//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include <DU/nts.hpp>
#include <DU/types.hpp>

namespace nr::DU
{

class DUCmdHandler
{
  private:
    TaskBase *m_base;

  public:
    explicit DUCmdHandler(TaskBase *base) : m_base(base)
    {
    }

    void handleCmd(NmDUCliCommand &msg);

  private:
    void pauseTasks();
    void unpauseTasks();
    bool isAllPaused();

  private:
    void handleCmdImpl(NmDUCliCommand &msg);

  private:
    void sendResult(const InetAddress &address, const std::string &output);
    void sendError(const InetAddress &address, const std::string &output);
};

} // namespace nr::DU
