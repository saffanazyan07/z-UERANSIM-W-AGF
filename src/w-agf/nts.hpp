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

namespace nr::w_agf
{

struct NmDURlsToRrc : NtsMessage
{
    enum PR
    {
        SIGNAL_DETECTED,
        UPLINK_RRC,
    } present;

    // SIGNAL_DETECTED
    // UPLINK_RRC
    int ueId{};

    // UPLINK_RRC
    OctetString data;
    rrc::RrcChannel rrcChannel{};

    explicit NmDURlsToRrc(PR present) : NtsMessage(NtsMessageType::DU_RLS_TO_RRC), present(present)
    {
    }
};

struct NmDURlsToRls : NtsMessage
{
    enum PR
    {
        SIGNAL_DETECTED,
        SIGNAL_LOST,
        RECEIVE_RLS_MESSAGE,
        DOWNLINK_RRC,
        DOWNLINK_DATA,
        UPLINK_RRC,
        UPLINK_DATA,
        RADIO_LINK_FAILURE,
        TRANSMISSION_FAILURE,
    } present;

    // SIGNAL_DETECTED
    // SIGNAL_LOST
    // DOWNLINK_RRC
    // DOWNLINK_DATA
    // UPLINK_DATA
    // UPLINK_RRC
    int ueId{};

    // RECEIVE_RLS_MESSAGE
    std::unique_ptr<rls::RlsMessage> msg{};

    // DOWNLINK_DATA
    // UPLINK_DATA
    int psi{};

    // DOWNLINK_DATA
    // DOWNLINK_RRC
    // UPLINK_DATA
    // UPLINK_RRC
    OctetString data;

    // DOWNLINK_RRC
    uint32_t pduId{};

    // DOWNLINK_RRC
    // UPLINK_RRC
    rrc::RrcChannel rrcChannel{};

    // RADIO_LINK_FAILURE
    rls::ERlfCause rlfCause{};

    // TRANSMISSION_FAILURE
    std::vector<rls::PduInfo> pduList;

    explicit NmDURlsToRls(PR present) : NtsMessage(NtsMessageType::DU_RLS_TO_RLS), present(present)
    {
    }
};

struct NmDURrcToRls : NtsMessage
{
    enum PR
    {
        RRC_PDU_DELIVERY,
    } present;

    // RRC_PDU_DELIVERY
    int ueId{};
    rrc::RrcChannel channel{};
    OctetString pdu{};

    explicit NmDURrcToRls(PR present) : NtsMessage(NtsMessageType::DU_RRC_TO_RLS), present(present)
    {
    }
};

struct NmDURrcToF1ap : NtsMessage
{
    enum PR
    {
        UL_RRC_TRANSFER,
        INITIAL_NAS_DELIVERY,

    } present;

    // RRC_PDU_DELIVERY
    int ueId{};
    std::string buffer{};
    rrc::RrcChannel rrcChannel{};

    // INITIAL_NAS_DELIVERY
    // UPLINK_NAS_DELIVERY
    OctetString pdu{};

    // INITIAL_NAS_DELIVERY
    int64_t rrcEstablishmentCause{};
    std::optional<GutiMobileIdentity> sTmsi{};

    explicit NmDURrcToF1ap(PR present) : NtsMessage(NtsMessageType::DU_RRC_TO_F1AP), present(present)
    {
    }
};

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
        SEND_MESSAGE2,
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
        DL_RRC_TRANSFER,
    } present;

    // NAS_DELIVERY
    // AN_RELEASE
    int ueId{};

    // NAS_DELIVERY
    OctetString pdu{};

    std::vector<std::string> buffer{};

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
