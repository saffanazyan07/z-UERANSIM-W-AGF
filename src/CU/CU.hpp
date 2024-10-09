//
// Created by Hoonyong Park on 5/10/23.
//

#ifndef UERANSIM_CU_HPP
#define UERANSIM_CU_HPP

#include "types.hpp"

#include <lib/app/cli_cmd.hpp>
#include <lib/app/monitor.hpp>
#include <utils/logger.hpp>
#include <utils/network.hpp>
#include <utils/nts.hpp>

namespace nr::CU
{

class CentralUnit
{
  private:
    TaskBase *taskBase;

  public:
    CentralUnit(CUConfig *config, app::INodeListener *nodeListener, NtsTask *cliCallbackTask);
    virtual ~CentralUnit();

  public:
    void start();
    void pushCommand(std::unique_ptr<app::CUCliCommand> cmd, const InetAddress &address);
};

} // namespace nr::CU

#endif // UERANSIM_CU_HPP
