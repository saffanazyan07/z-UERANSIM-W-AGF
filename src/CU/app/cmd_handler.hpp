//
// Created by ubuntu on 5/11/23.
//

#ifndef UERANSIM_CMD_HANDLER_HPP
#define UERANSIM_CMD_HANDLER_HPP

#include <CU/nts.hpp>
#include <CU/types.hpp>

namespace nr::CU
{

class CUCmdHandler
{
  private:
    TaskBase *m_base;

  public:
    explicit CUCmdHandler(TaskBase *base) : m_base(base)
    {
    }

    void handleCmd(NmCUCliCommand &msg);

  private:
    void pauseTasks();
    void unpauseTasks();
    bool isAllPaused();

  private:
    void handleCmdImpl(NmCUCliCommand &msg);

  private:
    void sendResult(const InetAddress &address, const std::string &output);
    void sendError(const InetAddress &address, const std::string &output);
};

} // namespace nr::CU

#endif // UERANSIM_CMD_HANDLER_HPP
