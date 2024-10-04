//
// Created by Hoonyong Park on 5/20/23.
//

#include "w-agf.hpp"
#include "app/task.hpp"
//#include "gtp/task.hpp"
#include "f1ap/task.hpp"
#include "rls/task.hpp"
#include "rrc/task.hpp"
#include "sctp/task.hpp"

#include <lib/app/cli_base.hpp>

namespace nr::w_agf
{

AccessGatewayFunction::AccessGatewayFunction(w_agfConfig *config, app::INodeListener *nodeListener, NtsTask *cliCallbackTask)
{
    auto *base = new TaskBase();
    base->config = config;
    base->logBase = new LogBase("logs/" + config->name + ".log");
    base->nodeListener = nodeListener;
    base->cliCallbackTask = cliCallbackTask;

    base->appTask = new DUAppTask(base);
    base->sctpTask = new SctpTask(base);
    base->f1apTask = new F1apTask(base);
    base->rrcTask = new DURrcTask(base);
//    base->gtpTask = new GtpTask(base);
    base->rlsTask = new DURlsTask(base);

    taskBase = base;
}

AccessGatewayFunction::~AccessGatewayFunction()
{
    taskBase->appTask->quit();
    taskBase->sctpTask->quit();
    taskBase->f1apTask->quit();
    taskBase->rrcTask->quit();
//    taskBase->gtpTask->quit();
    taskBase->rlsTask->quit();

    delete taskBase->appTask;
    delete taskBase->sctpTask;
    delete taskBase->f1apTask;
    delete taskBase->rrcTask;
//    delete taskBase->gtpTask;
    delete taskBase->rlsTask;

    delete taskBase->logBase;

    delete taskBase;
}

void AccessGatewayFunction::start()
{
    taskBase->appTask->start();
    taskBase->sctpTask->start();
    taskBase->f1apTask->start();
    taskBase->rrcTask->start();
    taskBase->rlsTask->start();
//    taskBase->gtpTask->start();
}

void AccessGatewayFunction::pushCommand(std::unique_ptr<app::DUCliCommand> cmd, const InetAddress &address)
{
    taskBase->appTask->push((std::make_unique<NmDUCliCommand>(std::move(cmd), address)));
}

} // namespace nr::w_agf