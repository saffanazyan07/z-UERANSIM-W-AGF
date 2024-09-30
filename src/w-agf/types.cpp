//
// Created by Hoonyong Park on 5/20/23.
//

#include <sstream>

#include <DU/types.hpp>
#include <utils/common.hpp>

namespace nr::DU
{

Json ToJson(const DUStatusInfo &v)
{
    return Json::Obj({{"is-f1ap-up", v.isF1apUp}});
}

Json ToJson(const DUConfig &v)
{
    return Json::Obj({
        {"name", v.name},
        {"nci", v.nci},
        {"plmn", ToJson(v.plmn)},
        {"tac", v.tac},
        {"nssai", ToJson(v.nssai)},
        {"ngap-ip", v.f1apIp},
        {"gtp-ip", v.gtpIp},
        {"paging-drx", ToJson(v.pagingDrx)},
        {"ignore-sctp-id", v.ignoreStreamIds},
    });
}

Json ToJson(const F1apCUContext &v)
{
    return Json::Obj({
        {"name", v.CUName},
        {"address", ((utils::GetIpVersion(v.address) == 6) ? "[" + v.address + "]" : v.address) + ":" + std::to_string(v.port)},
        //{"state", ToJson(v.state).str()},
        {"capacity", v.relativeCapacity},
        {"association", ToJson(v.association)},
        //{"served-guami", ::ToJson(v.servedGuamiList)},
        //{"served-plmn", ::ToJson(v.plmnSupportList)},
    });
}

Json ToJson(const EPagingDrx &v)
{
    switch (v)
    {
    case EPagingDrx::V32:
        return "v32";
    case EPagingDrx::V64:
        return "v64";
    case EPagingDrx::V128:
        return "v128";
    case EPagingDrx::V256:
        return "v256";
    default:
        return "?";
    }
}

Json ToJson(const SctpAssociation &v)
{
    return Json::Obj({{"id", v.associationId}, {"rx-num", v.inStreams}, {"tx-num", v.outStreams}});
}

}
