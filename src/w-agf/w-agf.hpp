//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include "types.hpp"

#include <lib/app/cli_cmd.hpp>
#include <lib/app/monitor.hpp>
#include <utils/logger.hpp>
#include <utils/network.hpp>
#include <utils/nts.hpp>

namespace nr::DU
{

class DistributedUnit
{
  private:
    TaskBase *taskBase;

  public:
    DistributedUnit(DUConfig *config, app::INodeListener *nodeListener, NtsTask *cliCallbackTask);
    virtual ~DistributedUnit();

  public:
    void start();
    void pushCommand(std::unique_ptr<app::DUCliCommand> cmd, const InetAddress &address);
};

} // namespace nr::DU