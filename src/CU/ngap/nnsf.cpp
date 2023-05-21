//
// Created by Hoonyong Park on 5/12/23.
//

#include "task.hpp"

namespace nr::CU
{

NgapAmfContext *NgapTask::selectAmf(int ueId)
{
    // todo:
    for (auto &amf : m_amfCtx)
        return amf.second; // return the first one
    return nullptr;
}

NgapAmfContext *NgapTask::selectNewAmfForReAllocation(int ueId, int initiatedAmfId, int amfSetId)
{
    // TODO an arbitrary AMF is selected for now
    return findAmfContext(initiatedAmfId);
}

} // namespace nr::CU