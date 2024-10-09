//
// created by zyzy on 7/10/2024
// 


#pragma once

#include <type_traits>

extern "C"
{
    struct F1AP_PDU;
    struct InitiatingMessage;
    struct SuccessfulOutcome;
    struct UnsuccessfulOutcome;

    struct GNBCUConfigurationUpdate;
    struct GNBCUConfigurationUpdateAcknowledge;
    struct GNBCUConfigurationUpdateFailure;
    // struct ASN_NGAP_AMFStatusIndication;
    // struct ASN_NGAP_CellTrafficTrace;
    // struct ASN_NGAP_DeactivateTrace;
    struct DLRRCMessageTransfer;
    //struct ASN_NGAP_DownlinkNonUEAssociatedNRPPaTransport;
    //struct ASN_NGAP_DownlinkRANConfigurationTransfer;
    //struct ASN_NGAP_DownlinkRANStatusTransfer;
    //struct ASN_NGAP_DownlinkUEAssociatedNRPPaTransport;
    struct ErrorIndication;
    //struct ASN_NGAP_HandoverCancel;
    //struct ASN_NGAP_HandoverCancelAcknowledge;
    //struct ASN_NGAP_HandoverCommand;
    //struct ASN_NGAP_HandoverFailure;
    //struct ASN_NGAP_HandoverNotify;
    //struct ASN_NGAP_HandoverPreparationFailure;
    //struct ASN_NGAP_HandoverRequest;
    //struct ASN_NGAP_HandoverRequestAcknowledge;
    //struct ASN_NGAP_HandoverRequired;
    struct UEContextSetupFailure;
    struct UEContextSetupRequest;
    struct UEContextSetupResponse;
    struct InitialULRRCMessageTransfer;
    //struct ASN_NGAP_LocationReport;
    struct ASN_NGAP_LocationReportingControl;
    struct ASN_NGAP_LocationReportingFailureIndication;
    struct ASN_NGAP_NASNonDeliveryIndication;
    struct Reset;
    struct ResetAcknowledge;
    struct F1SetupFailure;
    struct F1SetupRequest;
    struct F1SetupResponse;
    //struct ASN_NGAP_OverloadStart;
    //struct ASN_NGAP_OverloadStop;
    struct Paging;
    //struct ASN_NGAP_PathSwitchRequest;
    //struct ASN_NGAP_PathSwitchRequestAcknowledge;
    //struct ASN_NGAP_PathSwitchRequestFailure;
    //struct ASN_NGAP_PDUSessionResourceModifyConfirm;
    //struct ASN_NGAP_PDUSessionResourceModifyIndication;
    //struct ASN_NGAP_PDUSessionResourceModifyRequest;
    //struct ASN_NGAP_PDUSessionResourceModifyResponse;
    //struct ASN_NGAP_PDUSessionResourceNotify;
    //struct ASN_NGAP_PDUSessionResourceReleaseCommand;
    //struct ASN_NGAP_PDUSessionResourceReleaseResponse;
    //struct ASN_NGAP_PDUSessionResourceSetupRequest;
    //struct ASN_NGAP_PDUSessionResourceSetupResponse;
    struct PrivateMessage;
    struct PWSCancelRequest;
    struct PWSCancelResponse;
    struct PWSFailureIndication;
    struct PWSRestartIndication;
    struct GNBDUConfigurationUpdate;
    struct GNBDUConfigurationUpdateAcknowledge;
    struct GNBDUConfigurationUpdateFailure;
    //struct ASN_NGAP_RerouteNASRequest;
    //struct ASN_NGAP_RRCInactiveTransitionReport;
    //struct ASN_NGAP_SecondaryRATDataUsageReport;
    //struct ASN_NGAP_TraceFailureIndication;
    //struct ASN_NGAP_TraceStart;
    struct UEContextModificationFailure;
    struct UEContextModificationRequest;
    struct UEContextModificationResponse;
    struct UEContextReleaseCommand;
    struct UEContextReleaseComplete;
    struct UEContextReleaseRequest;
    //struct ASN_NGAP_UERadioCapabilityCheckRequest;
    //struct ASN_NGAP_UERadioCapabilityCheckResponse;
    //struct ASN_NGAP_UERadioCapabilityInfoIndication;
    //struct ASN_NGAP_UETNLABindingReleaseRequest;
    struct ULRRCMessageTransfer;
    //struct ASN_NGAP_UplinkNonUEAssociatedNRPPaTransport;
    //struct ASN_NGAP_UplinkRANConfigurationTransfer;
    //struct ASN_NGAP_UplinkRANStatusTransfer;
    //struct ASN_NGAP_UplinkUEAssociatedNRPPaTransport;
    //struct ASN_NGAP_WriteReplaceWarningRequest;
    //struct ASN_NGAP_WriteReplaceWarningResponse;
}

namespace asn::f1ap
{

enum class F1apMessageType
{
    GNBCUConfigurationUpdate,
    GNBCUConfigurationUpdateAcknowledge,
    GNBCUConfigurationUpdateFailure,
    /*
    AMFStatusIndication,
    CellTrafficTrace,
    DeactivateTrace,
    */
    DLRRCMessageTransfer,
    /*
    DownlinkNonUEAssociatedNRPPaTransport,
    DownlinkRANConfigurationTransfer,
    DownlinkRANStatusTransfer,
    DownlinkUEAssociatedNRPPaTransport,
    */
    ErrorIndication,
    /*
    HandoverCancel,
    HandoverCancelAcknowledge,
    HandoverCommand,
    HandoverFailure,
    HandoverNotify,
    HandoverPreparationFailure,
    HandoverRequest,
    HandoverRequestAcknowledge,
    HandoverRequired,
    */
    UEContextSetupFailure,
    UEContextSetupRequest,
    UEContextSetupResponse,
    InitialULRRCMessageTransfer,
    /*
    LocationReport,
    LocationReportingControl,
    LocationReportingFailureIndication,
    NASNonDeliveryIndication,
    */
    Reset,
    ResetAcknowledge,
    F1SetupFailure,
    F1SetupRequest,
    F1SetupResponse,
    /*
    OverloadStart,
    OverloadStop,
    */
    Paging,
    /*
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
    */
    PrivateMessage,
    PWSCancelRequest,
    PWSCancelResponse,
    PWSFailureIndication,
    PWSRestartIndication,
    GNBDUConfigurationUpdate,
    GNBDUConfigurationUpdateAcknowledge,
    GNBDUConfigurationUpdateFailure,
    /*
    RerouteNASRequest,
    RRCInactiveTransitionReport,
    SecondaryRATDataUsageReport,
    TraceFailureIndication,
    TraceStart,
    */
    UEContextModificationFailure,
    UEContextModificationRequest,
    UEContextModificationResponse,
    UEContextReleaseCommand,
    UEContextReleaseComplete,
    UEContextReleaseRequest,
    /*
    UERadioCapabilityCheckRequest,
    UERadioCapabilityCheckResponse,
    UERadioCapabilityInfoIndication,
    UETNLABindingReleaseRequest,
    */
    ULRRCMessageTransfer,
    /*
    UplinkNonUEAssociatedNRPPaTransport,
    UplinkRANConfigurationTransfer,
    UplinkRANStatusTransfer,
    UplinkUEAssociatedNRPPaTransport,
    WriteReplaceWarningRequest,
    WriteReplaceWarningResponse
    */

};

template <F1apMessageType T>
struct F1apMessageEnumToType
{
};

template <>
struct F1apMessageEnumToType<F1apMessageType::GNBCUConfigurationUpdate>
{
    typedef GNBCUConfigurationUpdate T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::GNBCUConfigurationUpdateAcknowledge>
{
    typedef GNBCUConfigurationUpdateAcknowledge T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::GNBCUConfigurationUpdateFailure>
{
    typedef GNBCUConfigurationUpdateFailure T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::DLRRCMessageTransfer>
{
    typedef DLRRCMessageTransfer T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::ErrorIndication>
{
    typedef ErrorIndication T;
};
/*template <>
struct F1apMessageEnumToType<F1apMessageType::AMFStatusIndication>
{
    typedef ASN_NGAP_AMFStatusIndication T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::CellTrafficTrace>
{
    typedef ASN_NGAP_CellTrafficTrace T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::DeactivateTrace>
{
    typedef ASN_NGAP_DeactivateTrace T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::DownlinkNonUEAssociatedNRPPaTransport>
{
    typedef ASN_NGAP_DownlinkNonUEAssociatedNRPPaTransport T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::DownlinkRANConfigurationTransfer>
{
    typedef ASN_NGAP_DownlinkRANConfigurationTransfer T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::DownlinkRANStatusTransfer>
{
    typedef ASN_NGAP_DownlinkRANStatusTransfer T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::DownlinkUEAssociatedNRPPaTransport>
{
    typedef ASN_NGAP_DownlinkUEAssociatedNRPPaTransport T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverCancel>
{
    typedef ASN_NGAP_HandoverCancel T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverCancelAcknowledge>
{
    typedef ASN_NGAP_HandoverCancelAcknowledge T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverCommand>
{
    typedef ASN_NGAP_HandoverCommand T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverFailure>
{
    typedef ASN_NGAP_HandoverFailure T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverNotify>
{
    typedef ASN_NGAP_HandoverNotify T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverPreparationFailure>
{
    typedef ASN_NGAP_HandoverPreparationFailure T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverRequest>
{
    typedef ASN_NGAP_HandoverRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverRequestAcknowledge>
{
    typedef ASN_NGAP_HandoverRequestAcknowledge T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::HandoverRequired>
{
    typedef ASN_NGAP_HandoverRequired T;
};
*/
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextSetupFailure>
{
    typedef UEContextSetupFailure T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextSetupRequest>
{
    typedef UEContextSetupRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextSetupResponse>
{
    typedef UEContextSetupResponse T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::InitialULRRCMessageTransfer>
{
    typedef InitialULRRCMessageTransfer T;
};
/*
template <>
struct F1apMessageEnumToType<F1apMessageType::LocationReport>
{
    typedef ASN_NGAP_LocationReport T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::LocationReportingControl>
{
    typedef ASN_NGAP_LocationReportingControl T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::LocationReportingFailureIndication>
{
    typedef ASN_NGAP_LocationReportingFailureIndication T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::NASNonDeliveryIndication>
{
    typedef ASN_NGAP_NASNonDeliveryIndication T;
};
*/
template <>
struct F1apMessageEnumToType<F1apMessageType::Reset>
{
    typedef Reset T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::ResetAcknowledge>
{
    typedef ResetAcknowledge T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::F1SetupFailure>
{
    typedef F1SetupFailure T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::F1SetupRequest>
{
    typedef F1SetupRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::F1SetupResponse>
{
    typedef F1SetupResponse T;
};
/*
template <>
struct F1apMessageEnumToType<F1apMessageType::OverloadStart>
{
    typedef ASN_NGAP_OverloadStart T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::OverloadStop>
{
    typedef ASN_NGAP_OverloadStop T;
};*/
template <>
struct F1apMessageEnumToType<F1apMessageType::Paging>
{
    typedef Paging T;
};
/*
template <>
struct F1apMessageEnumToType<F1apMessageType::PathSwitchRequest>
{
    typedef ASN_NGAP_PathSwitchRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PathSwitchRequestAcknowledge>
{
    typedef ASN_NGAP_PathSwitchRequestAcknowledge T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PathSwitchRequestFailure>
{
    typedef ASN_NGAP_PathSwitchRequestFailure T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceModifyConfirm>
{
    typedef ASN_NGAP_PDUSessionResourceModifyConfirm T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceModifyIndication>
{
    typedef ASN_NGAP_PDUSessionResourceModifyIndication T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceModifyRequest>
{
    typedef ASN_NGAP_PDUSessionResourceModifyRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceModifyResponse>
{
    typedef ASN_NGAP_PDUSessionResourceModifyResponse T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceNotify>
{
    typedef ASN_NGAP_PDUSessionResourceNotify T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceReleaseCommand>
{
    typedef ASN_NGAP_PDUSessionResourceReleaseCommand T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceReleaseResponse>
{
    typedef ASN_NGAP_PDUSessionResourceReleaseResponse T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceSetupRequest>
{
    typedef ASN_NGAP_PDUSessionResourceSetupRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PDUSessionResourceSetupResponse>
{
    typedef ASN_NGAP_PDUSessionResourceSetupResponse T;
};*/
template <>
struct F1apMessageEnumToType<F1apMessageType::PrivateMessage>
{
    typedef PrivateMessage T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PWSCancelRequest>
{
    typedef PWSCancelRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PWSCancelResponse>
{
    typedef PWSCancelResponse T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PWSFailureIndication>
{
    typedef PWSFailureIndication T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::PWSRestartIndication>
{
    typedef PWSRestartIndication T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::GNBDUConfigurationUpdate>
{
    typedef GNBDUConfigurationUpdate T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::GNBDUConfigurationUpdateAcknowledge>
{
    typedef GNBDUConfigurationUpdateAcknowledge T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::GNBDUConfigurationUpdateFailure>
{
    typedef GNBDUConfigurationUpdateFailure T;
};
/*
template <>
struct F1apMessageEnumToType<F1apMessageType::RerouteNASRequest>
{
    typedef ASN_NGAP_RerouteNASRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::RRCInactiveTransitionReport>
{
    typedef ASN_NGAP_RRCInactiveTransitionReport T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::SecondaryRATDataUsageReport>
{
    typedef ASN_NGAP_SecondaryRATDataUsageReport T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::TraceFailureIndication>
{
    typedef ASN_NGAP_TraceFailureIndication T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::TraceStart>
{
    typedef ASN_NGAP_TraceStart T;
};
*/
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextModificationFailure>
{
    typedef UEContextModificationFailure T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextModificationRequest>
{
    typedef UEContextModificationRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextModificationResponse>
{
    typedef UEContextModificationResponse T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextReleaseCommand>
{
    typedef UEContextReleaseCommand T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextReleaseComplete>
{
    typedef UEContextReleaseComplete T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UEContextReleaseRequest>
{
    typedef UEContextReleaseRequest T;
};
/*
template <>
struct F1apMessageEnumToType<F1apMessageType::UERadioCapabilityCheckRequest>
{
    typedef ASN_NGAP_UERadioCapabilityCheckRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UERadioCapabilityCheckResponse>
{
    typedef ASN_NGAP_UERadioCapabilityCheckResponse T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UERadioCapabilityInfoIndication>
{
    typedef ASN_NGAP_UERadioCapabilityInfoIndication T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UETNLABindingReleaseRequest>
{
    typedef ASN_NGAP_UETNLABindingReleaseRequest T;
};
*/
template <>
struct F1apMessageEnumToType<F1apMessageType::ULRRCMessageTransfer>
{
    typedef ULRRCMessageTransfer T;
};
/*
template <>
struct F1apMessageEnumToType<F1apMessageType::UplinkNonUEAssociatedNRPPaTransport>
{
    typedef ASN_NGAP_UplinkNonUEAssociatedNRPPaTransport T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UplinkRANConfigurationTransfer>
{
    typedef ASN_NGAP_UplinkRANConfigurationTransfer T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UplinkRANStatusTransfer>
{
    typedef ASN_NGAP_UplinkRANStatusTransfer T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::UplinkUEAssociatedNRPPaTransport>
{
    typedef ASN_NGAP_UplinkUEAssociatedNRPPaTransport T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::WriteReplaceWarningRequest>
{
    typedef ASN_NGAP_WriteReplaceWarningRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::WriteReplaceWarningResponse>
{
    typedef ASN_NGAP_WriteReplaceWarningResponse T;
};
*/
template <typename T>
struct F1apMessageTypeToEnum;

template <>
struct F1apMessageTypeToEnum<GNBCUConfigurationUpdate>
{
    enum
    {
        V = (int)F1apMessageType::GNBCUConfigurationUpdate
    };
};
template <>
struct F1apMessageTypeToEnum<GNBCUConfigurationUpdateAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::GNBCUConfigurationUpdateAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<GNBCUConfigurationUpdateFailure>
{
    enum
    {
        V = (int)F1apMessageType::GNBCUConfigurationUpdateFailure
    };
};
/*
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
*/
template <>
struct F1apMessageTypeToEnum<DLRRCMessageTransfer>
{
    enum
    {
        V = (int)F1apMessageType::DLRRCMessageTransfer
    };
};
/*
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
*/
template <>
struct F1apMessageTypeToEnum<ErrorIndication>
{
    enum
    {
        V = (int)F1apMessageType::ErrorIndication
    };
};
/*
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
*/
template <>
struct F1apMessageTypeToEnum<UEContextSetupFailure>
{
    enum
    {
        V = (int)F1apMessageType::UEContextSetupFailure
    };
};
template <>
struct F1apMessageTypeToEnum<UEContextSetupRequest>
{
    enum
    {
        V = (int)F1apMessageType::UEContextSetupRequest
    };
};
template <>
struct F1apMessageTypeToEnum<UEContextSetupResponse>
{
    enum
    {
        V = (int)F1apMessageType::UEContextSetupResponse
    };
};
template <>
struct F1apMessageTypeToEnum<InitialULRRCMessageTransfer>
{
    enum
    {
        V = (int)F1apMessageType::InitialULRRCMessageTransfer
    };
};
/*
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
*/
template <>
struct F1apMessageTypeToEnum<Reset>
{
    enum
    {
        V = (int)F1apMessageType::Reset
    };
};
template <>
struct F1apMessageTypeToEnum<ResetAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::ResetAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<F1SetupFailure>
{
    enum
    {
        V = (int)F1apMessageType::F1SetupFailure
    };
};
template <>
struct F1apMessageTypeToEnum<F1SetupRequest>
{
    enum
    {
        V = (int)F1apMessageType::F1SetupRequest
    };
};
template <>
struct F1apMessageTypeToEnum<F1SetupResponse>
{
    enum
    {
        V = (int)F1apMessageType::F1SetupResponse
    };
};
/*
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
*/
template <>
struct F1apMessageTypeToEnum<Paging>
{
    enum
    {
        V = (int)F1apMessageType::Paging
    };
};
/*
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
*/
template <>
struct F1apMessageTypeToEnum<PrivateMessage>
{
    enum
    {
        V = (int)F1apMessageType::PrivateMessage
    };
};
template <>
struct F1apMessageTypeToEnum<PWSCancelRequest>
{
    enum
    {
        V = (int)F1apMessageType::PWSCancelRequest
    };
};
template <>
struct F1apMessageTypeToEnum<PWSCancelResponse>
{
    enum
    {
        V = (int)F1apMessageType::PWSCancelResponse
    };
};
template <>
struct F1apMessageTypeToEnum<PWSFailureIndication>
{
    enum
    {
        V = (int)F1apMessageType::PWSFailureIndication
    };
};
template <>
struct F1apMessageTypeToEnum<PWSRestartIndication>
{
    enum
    {
        V = (int)F1apMessageType::PWSRestartIndication
    };
};
template <>
struct F1apMessageTypeToEnum<GNBDUConfigurationUpdate>
{
    enum
    {
        V = (int)F1apMessageType::GNBDUConfigurationUpdate
    };
};
template <>
struct F1apMessageTypeToEnum<GNBDUConfigurationUpdateAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::GNBDUConfigurationUpdateAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<GNBDUConfigurationUpdateFailure>
{
    enum
    {
        V = (int)F1apMessageType::GNBDUConfigurationUpdateFailure
    };
};
/*
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
*/
template <>
struct F1apMessageTypeToEnum<UEContextModificationFailure>
{
    enum
    {
        V = (int)F1apMessageType::UEContextModificationFailure
    };
};
template <>
struct F1apMessageTypeToEnum<UEContextModificationRequest>
{
    enum
    {
        V = (int)F1apMessageType::UEContextModificationRequest
    };
};
template <>
struct F1apMessageTypeToEnum<UEContextModificationResponse>
{
    enum
    {
        V = (int)F1apMessageType::UEContextModificationResponse
    };
};
template <>
struct F1apMessageTypeToEnum<UEContextReleaseCommand>
{
    enum
    {
        V = (int)F1apMessageType::UEContextReleaseCommand
    };
};
template <>
struct F1apMessageTypeToEnum<UEContextReleaseComplete>
{
    enum
    {
        V = (int)F1apMessageType::UEContextReleaseComplete
    };
};
template <>
struct F1apMessageTypeToEnum<UEContextReleaseRequest>
{
    enum
    {
        V = (int)F1apMessageType::UEContextReleaseRequest
    };
};
/*
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
*/
template <>
struct F1apMessageTypeToEnum<ULRRCMessageTransfer>
{
    enum
    {
        V = (int)F1apMessageType::ULRRCMessageTransfer
    };
};

/*
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
*/
struct F1apMessageToDescription_InitiatingMessage
{
    typedef InitiatingMessage T;
};

struct F1apMessageToDescription_SuccessfulOutcome
{
    typedef SuccessfulOutcome T;
};

struct F1apMessageToDescription_UnsuccessfulOutcome
{
    typedef UnsuccessfulOutcome T;
};

template <typename T>
struct F1apMessageToDescription;

template <>
struct F1apMessageToDescription<GNBCUConfigurationUpdate> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_AMFStatusIndication> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_CellTrafficTrace> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_DeactivateTrace> : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<DLRRCMessageTransfer> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_DownlinkNonUEAssociatedNRPPaTransport>
    : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_DownlinkRANConfigurationTransfer> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_DownlinkRANStatusTransfer> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_DownlinkUEAssociatedNRPPaTransport>
    : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<ErrorIndication> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverCancel> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverNotify> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverRequest> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverRequired> : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<UEContextSetupRequest> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<InitialULRRCMessageTransfer> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_LocationReport> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_LocationReportingControl> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_LocationReportingFailureIndication>
    : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_NASNonDeliveryIndication> : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<Reset> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<F1SetupRequest> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_OverloadStart> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_OverloadStop> : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<Paging> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_PathSwitchRequest> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceModifyIndication>
    : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceModifyRequest> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceNotify> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceReleaseCommand> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceSetupRequest> : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<PrivateMessage> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<PWSCancelRequest> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<PWSFailureIndication> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<PWSRestartIndication> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<GNBDUConfigurationUpdate> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_RerouteNASRequest> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_RRCInactiveTransitionReport> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_SecondaryRATDataUsageReport> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_TraceFailureIndication> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_TraceStart> : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<UEContextModificationRequest> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<UEContextReleaseCommand> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<UEContextReleaseRequest> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_UERadioCapabilityCheckRequest> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_UERadioCapabilityInfoIndication> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_UETNLABindingReleaseRequest> : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<ULRRCMessageTransfer> : F1apMessageToDescription_InitiatingMessage
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_UplinkNonUEAssociatedNRPPaTransport>
    : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_UplinkRANConfigurationTransfer> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_UplinkRANStatusTransfer> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_UplinkUEAssociatedNRPPaTransport> : F1apMessageToDescription_InitiatingMessage
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_WriteReplaceWarningRequest> : F1apMessageToDescription_InitiatingMessage
{
};
*/
template <>
struct F1apMessageToDescription<GNBCUConfigurationUpdateAcknowledge> : F1apMessageToDescription_SuccessfulOutcome
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverCancelAcknowledge> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverCommand> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverRequestAcknowledge> : F1apMessageToDescription_SuccessfulOutcome
{
};
*/
template <>
struct F1apMessageToDescription<UEContextSetupResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ResetAcknowledge> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<F1SetupResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_PathSwitchRequestAcknowledge> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceModifyConfirm> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceModifyResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceReleaseResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_PDUSessionResourceSetupResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
*/
template <>
struct F1apMessageToDescription<PWSCancelResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<GNBDUConfigurationUpdateAcknowledge> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<UEContextModificationResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<UEContextReleaseComplete> : F1apMessageToDescription_SuccessfulOutcome
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_UERadioCapabilityCheckResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_WriteReplaceWarningResponse> : F1apMessageToDescription_SuccessfulOutcome
{
};
*/
template <>
struct F1apMessageToDescription<GNBCUConfigurationUpdateFailure> : F1apMessageToDescription_UnsuccessfulOutcome
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverFailure> : F1apMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<ASN_NGAP_HandoverPreparationFailure> : F1apMessageToDescription_UnsuccessfulOutcome
{
};
*/
template <>
struct F1apMessageToDescription<UEContextSetupFailure> : F1apMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<F1SetupFailure> : F1apMessageToDescription_UnsuccessfulOutcome
{
};
/*
template <>
struct F1apMessageToDescription<ASN_NGAP_PathSwitchRequestFailure> : F1apMessageToDescription_UnsuccessfulOutcome
{
};
*/
template <>
struct F1apMessageToDescription<GNBDUConfigurationUpdateFailure> : F1apMessageToDescription_UnsuccessfulOutcome
{
};
template <>
struct F1apMessageToDescription<UEContextModificationFailure> : F1apMessageToDescription_UnsuccessfulOutcome
{
};

template <typename T>
struct F1apMessageToIeType
{
    typedef typename std::remove_reference<decltype(*T{}.protocolIEs.list.array[0])>::type value;
};

template <typename T>
struct F1apMessageToIeUnionType
{
    typedef decltype(typename F1apMessageToIeType<T>::value{}.value.choice) value;
};

} // namespace asn::f1ap