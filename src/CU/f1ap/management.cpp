//
// Created by Hoonyong Park on 6/2/23.
//

#include "task.hpp"



namespace nr::CU
{

F1apDuContext* F1apTask::findDuContext(int ctxId)
{
    F1apDuContext *ctx = nullptr;
    if (m_duCtx.count(ctxId))
        ctx = m_duCtx[ctxId];
    if (ctx == nullptr)
        m_logger->err("DU context not found with id: %d", ctxId);
    return ctx;
}

void F1apTask::createDuContext(int ctxId, int duId/*, int cellId */)
{
    auto *ctx = new F1apDuContext();
    ctx->ctxId = ctxId;
    ctx->gNB_DU_ID = duId;
    //ctx->cellID = cellId;
    m_duCtx[ctx->ctxId] = ctx;
    m_logger->info("DU context created with id: %d", ctxId);
}

void F1apTask::deleteDuContext(int duId)
{
    auto *du = m_duCtx[duId];
    if (du)
    {
        delete du;
        m_duCtx.erase(duId);
    }
}





}