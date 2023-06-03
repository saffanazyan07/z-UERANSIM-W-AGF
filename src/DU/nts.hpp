//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include "types.hpp"

#include <utility>

#include <lib/app/cli_base.hpp>
#include <lib/app/cli_cmd.hpp>
#include <lib/asn/utils.hpp>
#include <lib/rls/rls_base.hpp>
#include <lib/rrc/rrc.hpp>
#include <lib/sctp/sctp.hpp>
#include <utils/network.hpp>
#include <utils/nts.hpp>
#include <utils/octet_string.hpp>
#include <utils/unique_buffer.hpp>

namespace nr::DU
{

struct NmDUSctp : NtsMessage
{
    enum PR
    {
        CONNECTION_REQUEST,
        CONNECTION_CLOSE,
        ASSOCIATION_SETUP,
        ASSOCIATION_SHUTDOWN,
        RECEIVE_MESSAGE,
        SEND_MESSAGE,
        UNHANDLED_NOTIFICATION,
    } present;

    // CONNECTION_REQUEST
    // CONNECTION_CLOSE
    // ASSOCIATION_SETUP
    // ASSOCIATION_SHUTDOWN
    // RECEIVE_MESSAGE
    // SEND_MESSAGE
    // UNHANDLED_NOTIFICATION
    int clientId{};

    // CONNECTION_REQUEST
    std::string localAddress{};
    uint16_t localPort{};
    std::string remoteAddress{};
    uint16_t remotePort{};
    sctp::PayloadProtocolId ppid{};
    NtsTask *associatedTask{};

    // ASSOCIATION_SETUP
    int associationId{};
    int inStreams{};
    int outStreams{};

    // RECEIVE_MESSAGE
    // SEND_MESSAGE
    UniqueBuffer buffer{};
    uint16_t stream{};

    explicit NmDUSctp(PR present) : NtsMessage(NtsMessageType::DU_SCTP), present(present)
    {
    }
};

struct NmDUF1apToRrc : NtsMessage
{
    enum PR
    {
        RADIO_POWER_ON,
        NAS_DELIVERY,
        AN_RELEASE,
        PAGING,
    } present;

    // NAS_DELIVERY
    // AN_RELEASE
    int ueId{};

    // NAS_DELIVERY
    OctetString pdu{};

    // PAGING
    //asn::Unique<ASN_NGAP_FiveG_S_TMSI> uePagingTmsi{};
    //asn::Unique<ASN_NGAP_TAIListForPaging> taiListForPaging{};

    explicit NmDUF1apToRrc(PR present) : NtsMessage(NtsMessageType::DU_F1AP_TO_RRC), present(present)
    {
    }
};

struct NmDUStatusUpdate : NtsMessage
{
    static constexpr const int F1AP_IS_UP = 1;

    const int what;

    // F1AP_IS_UP
    bool isF1apUp{};

    explicit NmDUStatusUpdate(const int what) : NtsMessage(NtsMessageType::DU_STATUS_UPDATE), what(what)
    {
    }
};

struct NmDUCliCommand : NtsMessage
{
    std::unique_ptr<app::DUCliCommand> cmd;
    InetAddress address;

    NmDUCliCommand(std::unique_ptr<app::DUCliCommand> cmd, InetAddress address)
        : NtsMessage(NtsMessageType::DU_CLI_COMMAND), cmd(std::move(cmd)), address(address)
    {
    }
};

}
