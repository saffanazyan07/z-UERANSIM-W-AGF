//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include <w_agf/nts.hpp>
#include <w_agf/types.hpp>

namespace nr::w_agf
{

class WagfCmdHandler
{
  private:
    TaskBase *m_base;

  public:
    explicit WagfCmdHandler(TaskBase *base) : m_base(base)
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

} // namespace nr::w_agf
