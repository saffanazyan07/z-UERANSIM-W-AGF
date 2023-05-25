//
// Created by Hoonyong Park on 5/10/23.
//

#include "CU.hpp"
#include "app/task.hpp"
#include "gtp/task.hpp"
#include "ngap/task.hpp"
#include "f1ap/task.hpp"
//#include "rls/task.hpp"
#include "rrc/task.hpp"
#include "sctp/task.hpp"

#include <lib/app/cli_base.hpp>

namespace nr::CU
{

CentralUnit::CentralUnit(CUConfig *config, app::INodeListener *nodeListener, NtsTask *cliCallbackTask)
{
    auto *base = new TaskBase();
    base->config = config;
    base->logBase = new LogBase("logs/" + config->name + ".log");
    base->nodeListener = nodeListener;
    base->cliCallbackTask = cliCallbackTask;

    base->appTask = new CUAppTask(base);
    base->sctpTask = new SctpTask(base);
    base->ngapTask = new NgapTask(base);
    base->rrcTask = new CURrcTask(base);
    base->gtpTask = new GtpTask(base);
    base->f1apTask = new F1apTask(base);
//    base->rlsTask = new CURlsTask(base);

    taskBase = base;
}

CentralUnit::~CentralUnit()
{
    taskBase->appTask->quit();
    taskBase->sctpTask->quit();
    taskBase->ngapTask->quit();
    taskBase->rrcTask->quit();
    taskBase->gtpTask->quit();
    taskBase->f1apTask->quit();
//    taskBase->rlsTask->quit();

    delete taskBase->appTask;
    delete taskBase->sctpTask;
    delete taskBase->ngapTask;
    delete taskBase->rrcTask;
    delete taskBase->gtpTask;
    delete taskBase->f1apTask;
//    delete taskBase->rlsTask;

    delete taskBase->logBase;

    delete taskBase;
}

void CentralUnit::start()
{
    taskBase->appTask->start();
    taskBase->sctpTask->start();
    taskBase->ngapTask->start();
    taskBase->rrcTask->start();
//    taskBase->rlsTask->start();
    taskBase->gtpTask->start();
    taskBase->f1apTask->start();
}

void CentralUnit::pushCommand(std::unique_ptr<app::CUCliCommand> cmd, const InetAddress &address)
{
    taskBase->appTask->push(std::make_unique<NmCUCliCommand>(std::move(cmd), address));
}

} // namespace nr::CU