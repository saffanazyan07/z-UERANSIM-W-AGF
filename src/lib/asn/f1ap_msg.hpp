//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#pragma once

#include <type_traits>

extern "C"
{
    struct F1AP_PDU;
    struct InitiatingMessage;
    struct SuccessfulOutcome;
    struct UnsuccessfulOutcome;

    struct ASN_NGAP_AMFConfigurationUpdate;
    struct ASN_NGAP_AMFConfigurationUpdateAcknowledge;
    struct ASN_NGAP_AMFConfigurationUpdateFailure;
    struct ASN_NGAP_AMFStatusIndication;
    struct ASN_NGAP_CellTrafficTrace;
    struct ASN_NGAP_DeactivateTrace;
    struct ASN_NGAP_DownlinkNASTransport;
    struct ASN_NGAP_DownlinkNonUEAssociatedNRPPaTransport;
    struct ASN_NGAP_DownlinkRANConfigurationTransfer;
    struct ASN_NGAP_DownlinkRANStatusTransfer;
    struct ASN_NGAP_DownlinkUEAssociatedNRPPaTransport;
    struct ASN_NGAP_ErrorIndication;
    struct ASN_NGAP_HandoverCancel;
    struct ASN_NGAP_HandoverCancelAcknowledge;
    struct ASN_NGAP_HandoverCommand;
    struct ASN_NGAP_HandoverFailure;
    struct ASN_NGAP_HandoverNotify;
    struct ASN_NGAP_HandoverPreparationFailure;
    struct ASN_NGAP_HandoverRequest;
    struct ASN_NGAP_HandoverRequestAcknowledge;
    struct ASN_NGAP_HandoverRequired;
    struct ASN_NGAP_InitialContextSetupFailure;
    struct ASN_NGAP_InitialContextSetupRequest;
    struct ASN_NGAP_InitialContextSetupResponse;
    struct ASN_NGAP_InitialUEMessage;
    struct ASN_NGAP_LocationReport;
    struct ASN_NGAP_LocationReportingControl;
    struct ASN_NGAP_LocationReportingFailureIndication;
    struct ASN_NGAP_NASNonDeliveryIndication;
    struct ASN_NGAP_NGReset;
    struct ASN_NGAP_NGResetAcknowledge;
    struct ASN_NGAP_NGSetupFailure;
    struct ASN_NGAP_NGSetupRequest;
    struct ASN_NGAP_NGSetupResponse;
    struct ASN_NGAP_OverloadStart;
    struct ASN_NGAP_OverloadStop;
    struct ASN_NGAP_Paging;
    struct ASN_NGAP_PathSwitchRequest;
    struct ASN_NGAP_PathSwitchRequestAcknowledge;
    struct ASN_NGAP_PathSwitchRequestFailure;
    struct ASN_NGAP_PDUSessionResourceModifyConfirm;
    struct ASN_NGAP_PDUSessionResourceModifyIndication;
    struct ASN_NGAP_PDUSessionResourceModifyRequest;
    struct ASN_NGAP_PDUSessionResourceModifyResponse;
    struct ASN_NGAP_PDUSessionResourceNotify;
    struct ASN_NGAP_PDUSessionResourceReleaseCommand;
    struct ASN_NGAP_PDUSessionResourceReleaseResponse;
    struct ASN_NGAP_PDUSessionResourceSetupRequest;
    struct ASN_NGAP_PDUSessionResourceSetupResponse;
    struct ASN_NGAP_PrivateMessage;
    struct ASN_NGAP_PWSCancelRequest;
    struct ASN_NGAP_PWSCancelResponse;
    struct ASN_NGAP_PWSFailureIndication;
    struct ASN_NGAP_PWSRestartIndication;
    struct ASN_NGAP_RANConfigurationUpdate;
    struct ASN_NGAP_RANConfigurationUpdateAcknowledge;
    struct ASN_NGAP_RANConfigurationUpdateFailure;
    struct ASN_NGAP_RerouteNASRequest;
    struct ASN_NGAP_RRCInactiveTransitionReport;
    struct ASN_NGAP_SecondaryRATDataUsageReport;
    struct ASN_NGAP_TraceFailureIndication;
    struct ASN_NGAP_TraceStart;
    struct ASN_NGAP_UEContextModificationFailure;
    struct ASN_NGAP_UEContextModificationRequest;
    struct ASN_NGAP_UEContextModificationResponse;
    struct ASN_NGAP_UEContextReleaseCommand;
    struct ASN_NGAP_UEContextReleaseComplete;
    struct ASN_NGAP_UEContextReleaseRequest;
    struct ASN_NGAP_UERadioCapabilityCheckRequest;
    struct ASN_NGAP_UERadioCapabilityCheckResponse;
    struct ASN_NGAP_UERadioCapabilityInfoIndication;
    struct ASN_NGAP_UETNLABindingReleaseRequest;
    struct ASN_NGAP_UplinkNASTransport;
    struct ASN_NGAP_UplinkNonUEAssociatedNRPPaTransport;
    struct ASN_NGAP_UplinkRANConfigurationTransfer;
    struct ASN_NGAP_UplinkRANStatusTransfer;
    struct ASN_NGAP_UplinkUEAssociatedNRPPaTransport;
    struct ASN_NGAP_WriteReplaceWarningRequest;
    struct ASN_NGAP_WriteReplaceWarningResponse;
}

namespace asn::ngap
{

enum class F1apMessageType
{
    AMFConfigurationUpdate,
    AMFConfigurationUpdateAcknowledge,
    AMFConfigurationUpdateFailure,
    AMFStatusIndication,
    CellTrafficTrace,
    DeactivateTrace,
    DownlinkNASTransport,
    DownlinkNonUEAssociatedNRPPaTransport,
    DownlinkRANConfigurationTransfer,
    DownlinkRANStatusTransfer,
    DownlinkUEAssociatedNRPPaTransport,
    ErrorIndication,
    HandoverCancel,
    HandoverCancelAcknowledge,
    HandoverCommand,
    HandoverFailure,
    HandoverNotify,
    HandoverPreparationFailure,
    HandoverRequest,
    HandoverRequestAcknowledge,
    HandoverRequired,
    InitialContextSetupFailure,
    InitialContextSetupRequest,
    InitialContextSetupResponse,
    InitialUEMessage,
    LocationReport,
    LocationReportingControl,
    LocationReportingFailureIndication,
    NASNonDeliveryIndication,
    NGReset,
    NGResetAcknowledge,
    NGSetupFailure,
    NGSetupRequest,
    NGSetupResponse,
    OverloadStart,
    OverloadStop,
    Paging,
    PathSwitchRequest,
    PathSwitchRequestAcknowledge,
    PathSwitchRequestFailure,
    PDUSessionResourceModifyConfirm,
    PDUSessionResourceModifyIndication,
    PDUSessionResourceModifyRequest,
    PDUSessionResourceModifyResponse,
    PDUSessionResourceNotify,
    PDUSessionResourceReleaseCommand,
    PDUSessionResourceReleaseResponse,
    PDUSessionResourceSetupRequest,
    PDUSessionResourceSetupResponse,
    PrivateMessage,
    PWSCancelRequest,
    PWSCancelResponse,
    PWSFailureIndication,
    PWSRestartIndication,
    RANConfigurationUpdate,
    RANConfigurationUpdateAcknowledge,
    RANConfigurationUpdateFailure,
    RerouteNASRequest,
    RRCInactiveTransitionReport,
    SecondaryRATDataUsageReport,
    TraceFailureIndication,
    TraceStart,
    UEContextModificationFailure,
    UEContextModificationRequest,
    UEContextModificationResponse,
    UEContextReleaseCommand,
    UEContextReleaseComplete,
    UEContextReleaseRequest,
    UERadioCapabilityCheckRequest,
    UERadioCapabilityCheckResponse,
    UERadioCapabilityInfoIndication,
    UETNLABindingReleaseRequest,
    UplinkNASTransport,
    UplinkNonUEAssociatedNRPPaTransport,
    UplinkRANConfigurationTransfer,
    UplinkRANStatusTransfer,
    UplinkUEAssociatedNRPPaTransport,
    WriteReplaceWarningRequest,
    WriteReplaceWarningResponse
};

template <F1apMessageType T>
struct NgapMessageEnumToType
{
};

template <>
struct NgapMessageEnumToType<F1apMessageType::AMFConfigurationUpdate>
{
    typedef ASN_NGAP_AMFConfigurationUpdate T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::AMFConfigurationUpdateAcknowledge>
{
    typedef ASN_NGAP_AMFConfigurationUpdateAcknowledge T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::AMFConfigurationUpdateFailure>
{
    typedef ASN_NGAP_AMFConfigurationUpdateFailure T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::AMFStatusIndication>
{
    typedef ASN_NGAP_AMFStatusIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::CellTrafficTrace>
{
    typedef ASN_NGAP_CellTrafficTrace T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::DeactivateTrace>
{
    typedef ASN_NGAP_DeactivateTrace T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::DownlinkNASTransport>
{
    typedef ASN_NGAP_DownlinkNASTransport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::DownlinkNonUEAssociatedNRPPaTransport>
{
    typedef ASN_NGAP_DownlinkNonUEAssociatedNRPPaTransport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::DownlinkRANConfigurationTransfer>
{
    typedef ASN_NGAP_DownlinkRANConfigurationTransfer T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::DownlinkRANStatusTransfer>
{
    typedef ASN_NGAP_DownlinkRANStatusTransfer T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::DownlinkUEAssociatedNRPPaTransport>
{
    typedef ASN_NGAP_DownlinkUEAssociatedNRPPaTransport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::ErrorIndication>
{
    typedef ASN_NGAP_ErrorIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverCancel>
{
    typedef ASN_NGAP_HandoverCancel T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverCancelAcknowledge>
{
    typedef ASN_NGAP_HandoverCancelAcknowledge T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverCommand>
{
    typedef ASN_NGAP_HandoverCommand T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverFailure>
{
    typedef ASN_NGAP_HandoverFailure T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverNotify>
{
    typedef ASN_NGAP_HandoverNotify T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverPreparationFailure>
{
    typedef ASN_NGAP_HandoverPreparationFailure T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverRequest>
{
    typedef ASN_NGAP_HandoverRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverRequestAcknowledge>
{
    typedef ASN_NGAP_HandoverRequestAcknowledge T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::HandoverRequired>
{
    typedef ASN_NGAP_HandoverRequired T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::InitialContextSetupFailure>
{
    typedef ASN_NGAP_InitialContextSetupFailure T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::InitialContextSetupRequest>
{
    typedef ASN_NGAP_InitialContextSetupRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::InitialContextSetupResponse>
{
    typedef ASN_NGAP_InitialContextSetupResponse T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::InitialUEMessage>
{
    typedef ASN_NGAP_InitialUEMessage T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::LocationReport>
{
    typedef ASN_NGAP_LocationReport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::LocationReportingControl>
{
    typedef ASN_NGAP_LocationReportingControl T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::LocationReportingFailureIndication>
{
    typedef ASN_NGAP_LocationReportingFailureIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::NASNonDeliveryIndication>
{
    typedef ASN_NGAP_NASNonDeliveryIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::NGReset>
{
    typedef ASN_NGAP_NGReset T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::NGResetAcknowledge>
{
    typedef ASN_NGAP_NGResetAcknowledge T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::NGSetupFailure>
{
    typedef ASN_NGAP_NGSetupFailure T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::NGSetupRequest>
{
    typedef ASN_NGAP_NGSetupRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::NGSetupResponse>
{
    typedef ASN_NGAP_NGSetupResponse T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::OverloadStart>
{
    typedef ASN_NGAP_OverloadStart T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::OverloadStop>
{
    typedef ASN_NGAP_OverloadStop T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::Paging>
{
    typedef ASN_NGAP_Paging T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PathSwitchRequest>
{
    typedef ASN_NGAP_PathSwitchRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PathSwitchRequestAcknowledge>
{
    typedef ASN_NGAP_PathSwitchRequestAcknowledge T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PathSwitchRequestFailure>
{
    typedef ASN_NGAP_PathSwitchRequestFailure T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceModifyConfirm>
{
    typedef ASN_NGAP_PDUSessionResourceModifyConfirm T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceModifyIndication>
{
    typedef ASN_NGAP_PDUSessionResourceModifyIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceModifyRequest>
{
    typedef ASN_NGAP_PDUSessionResourceModifyRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceModifyResponse>
{
    typedef ASN_NGAP_PDUSessionResourceModifyResponse T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceNotify>
{
    typedef ASN_NGAP_PDUSessionResourceNotify T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceReleaseCommand>
{
    typedef ASN_NGAP_PDUSessionResourceReleaseCommand T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceReleaseResponse>
{
    typedef ASN_NGAP_PDUSessionResourceReleaseResponse T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceSetupRequest>
{
    typedef ASN_NGAP_PDUSessionResourceSetupRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PDUSessionResourceSetupResponse>
{
    typedef ASN_NGAP_PDUSessionResourceSetupResponse T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PrivateMessage>
{
    typedef ASN_NGAP_PrivateMessage T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PWSCancelRequest>
{
    typedef ASN_NGAP_PWSCancelRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PWSCancelResponse>
{
    typedef ASN_NGAP_PWSCancelResponse T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PWSFailureIndication>
{
    typedef ASN_NGAP_PWSFailureIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::PWSRestartIndication>
{
    typedef ASN_NGAP_PWSRestartIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::RANConfigurationUpdate>
{
    typedef ASN_NGAP_RANConfigurationUpdate T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::RANConfigurationUpdateAcknowledge>
{
    typedef ASN_NGAP_RANConfigurationUpdateAcknowledge T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::RANConfigurationUpdateFailure>
{
    typedef ASN_NGAP_RANConfigurationUpdateFailure T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::RerouteNASRequest>
{
    typedef ASN_NGAP_RerouteNASRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::RRCInactiveTransitionReport>
{
    typedef ASN_NGAP_RRCInactiveTransitionReport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::SecondaryRATDataUsageReport>
{
    typedef ASN_NGAP_SecondaryRATDataUsageReport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::TraceFailureIndication>
{
    typedef ASN_NGAP_TraceFailureIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::TraceStart>
{
    typedef ASN_NGAP_TraceStart T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UEContextModificationFailure>
{
    typedef ASN_NGAP_UEContextModificationFailure T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UEContextModificationRequest>
{
    typedef ASN_NGAP_UEContextModificationRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UEContextModificationResponse>
{
    typedef ASN_NGAP_UEContextModificationResponse T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UEContextReleaseCommand>
{
    typedef ASN_NGAP_UEContextReleaseCommand T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UEContextReleaseComplete>
{
    typedef ASN_NGAP_UEContextReleaseComplete T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UEContextReleaseRequest>
{
    typedef ASN_NGAP_UEContextReleaseRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UERadioCapabilityCheckRequest>
{
    typedef ASN_NGAP_UERadioCapabilityCheckRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UERadioCapabilityCheckResponse>
{
    typedef ASN_NGAP_UERadioCapabilityCheckResponse T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UERadioCapabilityInfoIndication>
{
    typedef ASN_NGAP_UERadioCapabilityInfoIndication T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UETNLABindingReleaseRequest>
{
    typedef ASN_NGAP_UETNLABindingReleaseRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UplinkNASTransport>
{
    typedef ASN_NGAP_UplinkNASTransport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UplinkNonUEAssociatedNRPPaTransport>
{
    typedef ASN_NGAP_UplinkNonUEAssociatedNRPPaTransport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UplinkRANConfigurationTransfer>
{
    typedef ASN_NGAP_UplinkRANConfigurationTransfer T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UplinkRANStatusTransfer>
{
    typedef ASN_NGAP_UplinkRANStatusTransfer T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::UplinkUEAssociatedNRPPaTransport>
{
    typedef ASN_NGAP_UplinkUEAssociatedNRPPaTransport T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::WriteReplaceWarningRequest>
{
    typedef ASN_NGAP_WriteReplaceWarningRequest T;
};
template <>
struct NgapMessageEnumToType<F1apMessageType::WriteReplaceWarningResponse>
{
    typedef ASN_NGAP_WriteReplaceWarningResponse T;
};

template <typename T>
struct F1apMessageTypeToEnum;

template <>
struct F1apMessageTypeToEnum<ASN_NGAP_AMFConfigurationUpdate>
{
    enum
    {
        V = (int)F1apMessageType::AMFConfigurationUpdate
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_AMFConfigurationUpdateAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::AMFConfigurationUpdateAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_AMFConfigurationUpdateFailure>
{
    enum
    {
        V = (int)F1apMessageType::AMFConfigurationUpdateFailure
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_AMFStatusIndication>
{
    enum
    {
        V = (int)F1apMessageType::AMFStatusIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_CellTrafficTrace>
{
    enum
    {
        V = (int)F1apMessageType::CellTrafficTrace
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_DeactivateTrace>
{
    enum
    {
        V = (int)F1apMessageType::DeactivateTrace
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_DownlinkNASTransport>
{
    enum
    {
        V = (int)F1apMessageType::DownlinkNASTransport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_DownlinkNonUEAssociatedNRPPaTransport>
{
    enum
    {
        V = (int)F1apMessageType::DownlinkNonUEAssociatedNRPPaTransport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_DownlinkRANConfigurationTransfer>
{
    enum
    {
        V = (int)F1apMessageType::DownlinkRANConfigurationTransfer
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_DownlinkRANStatusTransfer>
{
    enum
    {
        V = (int)F1apMessageType::DownlinkRANStatusTransfer
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_DownlinkUEAssociatedNRPPaTransport>
{
    enum
    {
        V = (int)F1apMessageType::DownlinkUEAssociatedNRPPaTransport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_ErrorIndication>
{
    enum
    {
        V = (int)F1apMessageType::ErrorIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverCancel>
{
    enum
    {
        V = (int)F1apMessageType::HandoverCancel
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverCancelAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::HandoverCancelAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverCommand>
{
    enum
    {
        V = (int)F1apMessageType::HandoverCommand
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverFailure>
{
    enum
    {
        V = (int)F1apMessageType::HandoverFailure
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverNotify>
{
    enum
    {
        V = (int)F1apMessageType::HandoverNotify
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverPreparationFailure>
{
    enum
    {
        V = (int)F1apMessageType::HandoverPreparationFailure
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverRequest>
{
    enum
    {
        V = (int)F1apMessageType::HandoverRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverRequestAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::HandoverRequestAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_HandoverRequired>
{
    enum
    {
        V = (int)F1apMessageType::HandoverRequired
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_InitialContextSetupFailure>
{
    enum
    {
        V = (int)F1apMessageType::InitialContextSetupFailure
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_InitialContextSetupRequest>
{
    enum
    {
        V = (int)F1apMessageType::InitialContextSetupRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_InitialContextSetupResponse>
{
    enum
    {
        V = (int)F1apMessageType::InitialContextSetupResponse
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_InitialUEMessage>
{
    enum
    {
        V = (int)F1apMessageType::InitialUEMessage
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_LocationReport>
{
    enum
    {
        V = (int)F1apMessageType::LocationReport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_LocationReportingControl>
{
    enum
    {
        V = (int)F1apMessageType::LocationReportingControl
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_LocationReportingFailureIndication>
{
    enum
    {
        V = (int)F1apMessageType::LocationReportingFailureIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_NASNonDeliveryIndication>
{
    enum
    {
        V = (int)F1apMessageType::NASNonDeliveryIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_NGReset>
{
    enum
    {
        V = (int)F1apMessageType::NGReset
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_NGResetAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::NGResetAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_NGSetupFailure>
{
    enum
    {
        V = (int)F1apMessageType::NGSetupFailure
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_NGSetupRequest>
{
    enum
    {
        V = (int)F1apMessageType::NGSetupRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_NGSetupResponse>
{
    enum
    {
        V = (int)F1apMessageType::NGSetupResponse
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_OverloadStart>
{
    enum
    {
        V = (int)F1apMessageType::OverloadStart
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_OverloadStop>
{
    enum
    {
        V = (int)F1apMessageType::OverloadStop
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_Paging>
{
    enum
    {
        V = (int)F1apMessageType::Paging
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PathSwitchRequest>
{
    enum
    {
        V = (int)F1apMessageType::PathSwitchRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PathSwitchRequestAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::PathSwitchRequestAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PathSwitchRequestFailure>
{
    enum
    {
        V = (int)F1apMessageType::PathSwitchRequestFailure
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceModifyConfirm>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceModifyConfirm
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceModifyIndication>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceModifyIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceModifyRequest>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceModifyRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceModifyResponse>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceModifyResponse
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceNotify>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceNotify
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceReleaseCommand>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceReleaseCommand
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceReleaseResponse>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceReleaseResponse
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceSetupRequest>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceSetupRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PDUSessionResourceSetupResponse>
{
    enum
    {
        V = (int)F1apMessageType::PDUSessionResourceSetupResponse
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PrivateMessage>
{
    enum
    {
        V = (int)F1apMessageType::PrivateMessage
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PWSCancelRequest>
{
    enum
    {
        V = (int)F1apMessageType::PWSCancelRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PWSCancelResponse>
{
    enum
    {
        V = (int)F1apMessageType::PWSCancelResponse
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PWSFailureIndication>
{
    enum
    {
        V = (int)F1apMessageType::PWSFailureIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_PWSRestartIndication>
{
    enum
    {
        V = (int)F1apMessageType::PWSRestartIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_RANConfigurationUpdate>
{
    enum
    {
        V = (int)F1apMessageType::RANConfigurationUpdate
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_RANConfigurationUpdateAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::RANConfigurationUpdateAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_RANConfigurationUpdateFailure>
{
    enum
    {
        V = (int)F1apMessageType::RANConfigurationUpdateFailure
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_RerouteNASRequest>
{
    enum
    {
        V = (int)F1apMessageType::RerouteNASRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_RRCInactiveTransitionReport>
{
    enum
    {
        V = (int)F1apMessageType::RRCInactiveTransitionReport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_SecondaryRATDataUsageReport>
{
    enum
    {
        V = (int)F1apMessageType::SecondaryRATDataUsageReport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_TraceFailureIndication>
{
    enum
    {
        V = (int)F1apMessageType::TraceFailureIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_TraceStart>
{
    enum
    {
        V = (int)F1apMessageType::TraceStart
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UEContextModificationFailure>
{
    enum
    {
        V = (int)F1apMessageType::UEContextModificationFailure
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UEContextModificationRequest>
{
    enum
    {
        V = (int)F1apMessageType::UEContextModificationRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UEContextModificationResponse>
{
    enum
    {
        V = (int)F1apMessageType::UEContextModificationResponse
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UEContextReleaseCommand>
{
    enum
    {
        V = (int)F1apMessageType::UEContextReleaseCommand
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UEContextReleaseComplete>
{
    enum
    {
        V = (int)F1apMessageType::UEContextReleaseComplete
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UEContextReleaseRequest>
{
    enum
    {
        V = (int)F1apMessageType::UEContextReleaseRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UERadioCapabilityCheckRequest>
{
    enum
    {
        V = (int)F1apMessageType::UERadioCapabilityCheckRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UERadioCapabilityCheckResponse>
{
    enum
    {
        V = (int)F1apMessageType::UERadioCapabilityCheckResponse
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UERadioCapabilityInfoIndication>
{
    enum
    {
        V = (int)F1apMessageType::UERadioCapabilityInfoIndication
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UETNLABindingReleaseRequest>
{
    enum
    {
        V = (int)F1apMessageType::UETNLABindingReleaseRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UplinkNASTransport>
{
    enum
    {
        V = (int)F1apMessageType::UplinkNASTransport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UplinkNonUEAssociatedNRPPaTransport>
{
    enum
    {
        V = (int)F1apMessageType::UplinkNonUEAssociatedNRPPaTransport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UplinkRANConfigurationTransfer>
{
    enum
    {
        V = (int)F1apMessageType::UplinkRANConfigurationTransfer
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UplinkRANStatusTransfer>
{
    enum
    {
        V = (int)F1apMessageType::UplinkRANStatusTransfer
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_UplinkUEAssociatedNRPPaTransport>
{
    enum
    {
        V = (int)F1apMessageType::UplinkUEAssociatedNRPPaTransport
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_WriteReplaceWarningRequest>
{
    enum
    {
        V = (int)F1apMessageType::WriteReplaceWarningRequest
    };
};
template <>
struct F1apMessageTypeToEnum<ASN_NGAP_WriteReplaceWarningResponse>
{
    enum
    {
        V = (int)F1apMessageType::WriteReplaceWarningResponse
    };
};

struct NgapMessageToDescription_InitiatingMessage
{
    typedef InitiatingMessage T;
};

struct NgapMessageToDescription_SuccessfulOutcome
{
    typedef SuccessfulOutcome T;
};

struct NgapMessageToDescription_UnsuccessfulOutcome
{
    typedef UnsuccessfulOutcome T;
};

template <typename T>
struct NgapMessageToDescription;

template <>
struct NgapMessageToDescription<ASN_NGAP_AMFConfigurationUpdate> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_AMFStatusIndication> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_CellTrafficTrace> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_DeactivateTrace> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_DownlinkNASTransport> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_DownlinkNonUEAssociatedNRPPaTransport>
    : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_DownlinkRANConfigurationTransfer> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_DownlinkRANStatusTransfer> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_DownlinkUEAssociatedNRPPaTransport>
    : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_ErrorIndication> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverCancel> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverNotify> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverRequired> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_InitialContextSetupRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_InitialUEMessage> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_LocationReport> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_LocationReportingControl> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_LocationReportingFailureIndication>
    : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_NASNonDeliveryIndication> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_NGReset> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_NGSetupRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_OverloadStart> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_OverloadStop> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_Paging> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PathSwitchRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceModifyIndication>
    : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceModifyRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceNotify> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceReleaseCommand> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceSetupRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PrivateMessage> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PWSCancelRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PWSFailureIndication> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PWSRestartIndication> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_RANConfigurationUpdate> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_RerouteNASRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_RRCInactiveTransitionReport> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_SecondaryRATDataUsageReport> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_TraceFailureIndication> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_TraceStart> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UEContextModificationRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UEContextReleaseCommand> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UEContextReleaseRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UERadioCapabilityCheckRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UERadioCapabilityInfoIndication> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UETNLABindingReleaseRequest> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UplinkNASTransport> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UplinkNonUEAssociatedNRPPaTransport>
    : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UplinkRANConfigurationTransfer> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UplinkRANStatusTransfer> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UplinkUEAssociatedNRPPaTransport> : NgapMessageToDescription_InitiatingMessage
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_WriteReplaceWarningRequest> : NgapMessageToDescription_InitiatingMessage
{
};

template <>
struct NgapMessageToDescription<ASN_NGAP_AMFConfigurationUpdateAcknowledge> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverCancelAcknowledge> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverCommand> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverRequestAcknowledge> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_InitialContextSetupResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_NGResetAcknowledge> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_NGSetupResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PathSwitchRequestAcknowledge> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceModifyConfirm> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceModifyResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceReleaseResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PDUSessionResourceSetupResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PWSCancelResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_RANConfigurationUpdateAcknowledge> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UEContextModificationResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UEContextReleaseComplete> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UERadioCapabilityCheckResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_WriteReplaceWarningResponse> : NgapMessageToDescription_SuccessfulOutcome
{
};

template <>
struct NgapMessageToDescription<ASN_NGAP_AMFConfigurationUpdateFailure> : NgapMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverFailure> : NgapMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_HandoverPreparationFailure> : NgapMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_InitialContextSetupFailure> : NgapMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_NGSetupFailure> : NgapMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_PathSwitchRequestFailure> : NgapMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_RANConfigurationUpdateFailure> : NgapMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct NgapMessageToDescription<ASN_NGAP_UEContextModificationFailure> : NgapMessageToDescription_UnsuccessfulOutcome
{
};

template <typename T>
struct NgapMessageToIeType
{
    typedef typename std::remove_reference<decltype(*T{}.protocolIEs.list.array[0])>::type value;
};

template <typename T>
struct NgapMessageToIeUnionType
{
    typedef decltype(typename NgapMessageToIeType<T>::value{}.value.choice) value;
};

} // namespace asn::ngap