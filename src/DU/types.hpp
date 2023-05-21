//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include <set>

#include <lib/app/monitor.hpp>
#include <lib/asn/utils.hpp>
#include <utils/common_types.hpp>
#include <utils/logger.hpp>
#include <utils/network.hpp>
#include <utils/nts.hpp>
#include <utils/octet_string.hpp>

//#include <asn/ngap/ASN_NGAP_QosFlowSetupRequestList.h>
//#include <asn/rrc/ASN_RRC_InitialUE-Identity.h>

namespace nr::DU
{

class DUAppTask;
class GtpTask;
class F1apTask;
class DURrcTask;
class DURlsTask;
class SctpTask;

struct SctpAssociation
{
    int associationId{};
    int inStreams{};
    int outStreams{};
};

struct DUStatusInfo
{
    bool isF1apUp{};
};

struct F1apCUContext
{
    int ctxId{};
    SctpAssociation association{};
    int nextStream{}; // next available SCTP stream for uplink
    std::string address{};
    uint16_t port{};
    std::string CUName{};
    int64_t relativeCapacity{};
    //EAmfState state{};
    //OverloadInfo overloadInfo{};
    //std::vector<ServedGuami *> servedGuamiList{};
    std::vector<PlmnSupport *> plmnSupportList{};
};

struct DUCUConfig
{
    std::string address{};
    uint16_t port{};
};

struct DUConfig
{
    /* Read from config file */
    int64_t nci{};     // 36-bit
    int DUIdLength{}; // 22..32 bit
    Plmn plmn{};
    int tac{};
    NetworkSlice nssai{};
    std::vector<DUCUConfig> cuConfigs{};
    std::string linkIp{};
    std::string f1apIp{};
    std::string gtpIp{};
    std::optional<std::string> gtpAdvertiseIp{};
    bool ignoreStreamIds{};

    /* Assigned by program */
    std::string name{};
    EPagingDrx pagingDrx{};
    Vector3 phyLocation{};

    [[nodiscard]] inline uint32_t getDUId() const
    {
        return static_cast<uint32_t>((nci & 0xFFFFFFFFFLL) >> (36LL - static_cast<int64_t>(DUIdLength)));
    }

    [[nodiscard]] inline int getCellId() const
    {
        return static_cast<int>(nci & static_cast<uint64_t>((1 << (36 - DUIdLength)) - 1));
    }
};

struct TaskBase
{
    DUConfig *config{};
    LogBase *logBase{};
    app::INodeListener *nodeListener{};
    NtsTask *cliCallbackTask{};

    DUAppTask *appTask{};
    GtpTask *gtpTask{};
    F1apTask *f1apTask{};
    DURrcTask *rrcTask{};
    SctpTask *sctpTask{};
    DURlsTask *rlsTask{};
};

Json ToJson(const DUStatusInfo &v);
Json ToJson(const DUConfig &v);
Json ToJson(const F1apCUContext &v);
//Json ToJson(const EAmfState &v);
Json ToJson(const EPagingDrx &v);
Json ToJson(const SctpAssociation &v);
//Json ToJson(const ServedGuami &v);
//Json ToJson(const Guami &v);

}