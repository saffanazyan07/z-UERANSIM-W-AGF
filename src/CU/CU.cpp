//
// Created by Hoonyong Park on 5/10/23.
//

#include "CU.hpp"
#include <iostream>

namespace nr::CU
{

void CentralUnit::pushCommand(std::unique_ptr<app::GnbCliCommand> cmd, const InetAddress &address)
{
    std::cout << "pushCommand" << std::endl;
}
CentralUnit::CentralUnit(CUConfig *config, app::INodeListener *nodeListener, NtsTask *cliCallbackTask)
{
    std::cout << "CentralUnit" << std::endl;
}
void CentralUnit::start()
{
    std::cout << "start" << std::endl;
}
CentralUnit::~CentralUnit()
{
    std::cout << "~CentralUnit" << std::endl;
}

}

