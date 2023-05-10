//
// Created by ubuntu on 5/10/23.
//

#ifndef UERANSIM_TYPES_HPP
#define UERANSIM_TYPES_HPP

#pragma once

#include <set>

#include <lib/app/monitor.hpp>
#include <lib/asn/utils.hpp>
#include <utils/common_types.hpp>
#include <utils/logger.hpp>
#include <utils/network.hpp>
#include <utils/nts.hpp>
#include <utils/octet_string.hpp>

#include <asn/ngap/ASN_NGAP_QosFlowSetupRequestList.h>
#include <asn/rrc/ASN_RRC_InitialUE-Identity.h>

namespace nr::CU
{

class CUAppTask;
class GtpTask;
class NgapTask;
class CURrcTask;
class SctpTask;

struct CUAmfConfig
{
    std::string address{};
    uint16_t port{};
};

struct CUConfig
{
    /* Read from config file */
    int64_t CU_ID{};     // 36-bit
    int CUIdLength{}; // 22..32 bit
    Plmn plmn{};
    int tac{};
    NetworkSlice nssai{};
    std::vector<CUAmfConfig> amfConfigs{};
    //std::string linkIp{};
    std::string ngapIp{};
    std::string gtpIp{};
    std::optional<std::string> gtpAdvertiseIp{};
    bool ignoreStreamIds{};

    /* Assigned by program */
    std::string name{};
    EPagingDrx pagingDrx{};
    Vector3 phyLocation{};

    [[nodiscard]] inline uint32_t getCUId() const
    {
        return static_cast<uint32_t>((CU_ID & 0xFFFFFFFFFLL) >> (36LL - static_cast<int64_t>(CUIdLength)));
    }
};

struct TaskBase
{
    CUConfig *config{};
    LogBase *logBase{};
    app::INodeListener *nodeListener{};
    NtsTask *cliCallbackTask{};

    CUAppTask *appTask{};
    GtpTask *gtpTask{};
    NgapTask *ngapTask{};
    CURrcTask *rrcTask{};
    SctpTask *sctpTask{};
    //GnbRlsTask *rlsTask{};
};

} // namespace nr::CU

#endif // UERANSIM_TYPES_HPP
