//
// Created by Hoonyong Park on 6/3/23.
//

#include "task.hpp"

namespace nr::DU
{

RrcUeContext *DURrcTask::createUe(int id)
{
    auto *ctx = new RrcUeContext(id);
    m_ueCtx[id] = ctx;
    return ctx;
}

RrcUeContext *DURrcTask::tryFindUe(int id)
{
    if (m_ueCtx.count(id))
        return m_ueCtx[id];
    return nullptr;
}

RrcUeContext *DURrcTask::findUe(int id)
{
    auto *ue = tryFindUe(id);
    if (ue == nullptr)
    {
        m_logger->err("UE context with ID[%d] not found", id);
        return ue;
    }
    return ue;
}

}
