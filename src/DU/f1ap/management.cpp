//
// Created by ubuntu on 5/30/23.
//

#include <DU/f1ap/task.hpp>

#include <utils/common.hpp>

namespace nr::DU
{

void F1apTask::createCUContext(const DUCUConfig &conf)
{
    auto *ctx = new F1apCUContext();
    ctx->state = ECUState::NOT_CONNECTED;
    ctx->address = conf.address;
    ctx->port = conf.port;
    m_cuCtx = ctx;
}

void F1apTask::deleteCUContext()
{
    delete m_cuCtx;
}

}