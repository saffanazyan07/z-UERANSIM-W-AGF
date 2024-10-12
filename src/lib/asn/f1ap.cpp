//
// created by zyzy on 7/10/2024
// 


#include "f1ap.hpp"
#include "utils.hpp"
#include "utils/common.hpp"

#include <algorithm>
#include <functional>
#include <exception>
#include <stdexcept>

#include <asn/f1ap/GNBCUConfigurationUpdate.h> //ASN_NGAP_AMFConfigurationUpdate.h
#include <asn/f1ap/GNBCUConfigurationUpdateAcknowledge.h> //ASN_NGAP_AMFConfigurationUpdateAcknowledge.h
#include <asn/f1ap/GNBCUConfigurationUpdateFailure.h> //ASN_NGAP_AMFConfigurationUpdateFailure.h
#include <asn/f1ap/DLRRCMessageTransfer.h> //ASN_NGAP_DownlinkNASTransport.h
#include <asn/f1ap/ErrorIndication.h> //ASN_NGAP_ErrorIndication.h
#include <asn/f1ap/HandoverPreparationInformation.h> //ASN_NGAP_HandoverCancel.h & ...
#include <asn/f1ap/UEContextSetupFailure.h> //ASN_NGAP_InitialContextSetupFailure.h
#include <asn/f1ap/UEContextSetupRequest.h> //ASN_NGAP_InitialContextSetupRequest.h
#include <asn/f1ap/UEContextSetupResponse.h> //ASN_NGAP_InitialContextSetupResponse.h
#include <asn/f1ap/InitialULRRCMessageTransfer.h> //ASN_NGAP_InitialUEMessage.h
#include <asn/f1ap/InitiatingMessage.h> //InitiatingMessage.h
#include <asn/f1ap/F1AP-PDU.h> //ASN_NGAP_NGAP-PDU.h
#include <asn/f1ap/Reset.h> //ASN_NGAP_NGReset.h
#include <asn/f1ap/ResetAcknowledge.h> //ASN_NGAP_NGResetAcknowledge.h
#include <asn/f1ap/F1SetupFailure.h> //ASN_NGAP_NGSetupFailure.h
#include <asn/f1ap/F1SetupRequest.h> //ASN_NGAP_NGSetupRequest.h
#include <asn/f1ap/F1SetupResponse.h> //ASN_NGAP_NGSetupResponse.h
#include <asn/f1ap/PWSCancelRequest.h> //ASN_NGAP_PWSCancelRequest.h
#include <asn/f1ap/PWSCancelResponse.h> //ASN_NGAP_PWSCancelResponse.h
#include <asn/f1ap/PWSFailureIndication.h> //ASN_NGAP_PWSFailureIndication.h
#include <asn/f1ap/PWSRestartIndication.h> //ASN_NGAP_PWSRestartIndication.h
#include <asn/f1ap/Paging.h> //ASN_NGAP_Paging.h
#include <asn/f1ap/PrivateMessage.h> //ASN_NGAP_PrivateMessage.h
#include <asn/f1ap/ProtocolIE-Field.h> //ASN_NGAP_ProtocolIE-Field.h
#include <asn/f1ap/GNBDUConfigurationUpdate.h> //ASN_NGAP_RANConfigurationUpdate.h
#include <asn/f1ap/GNBDUConfigurationUpdateAcknowledge.h> //ASN_NGAP_RANConfigurationUpdateAcknowledge.h
#include <asn/f1ap/GNBDUConfigurationUpdateFailure.h> //ASN_NGAP_RANConfigurationUpdateFailure.h
#include <asn/f1ap/CUtoDURRCInformation.h> //.ASN_NGAP_RRCInactiveTransitionReport.h
#include <asn/f1ap/SuccessfulOutcome.h> //SuccessfulOutcome.h
#include <asn/f1ap/UEContextModificationFailure.h> //ASN_NGAP_UEContextModificationFailure.h
#include <asn/f1ap/UEContextModificationRequest.h> //ASN_NGAP_UEContextModificationRequest.h
#include <asn/f1ap/UEContextModificationResponse.h> //ASN_NGAP_UEContextModificationResponse.h
#include <asn/f1ap/UEContextReleaseCommand.h> //ASN_NGAP_UEContextReleaseCommand.h
#include <asn/f1ap/UEContextReleaseComplete.h> //ASN_NGAP_UEContextReleaseComplete.h
#include <asn/f1ap/UEContextReleaseRequest.h> //ASN_NGAP_UEContextReleaseRequest.h
#include <asn/f1ap/CauseRadioNetwork.h> //ASN_NGAP_UERadioCapabilityCheckRequest.h
#include <asn/f1ap/UnsuccessfulOutcome.h> //UnsuccessfulOutcome.h
#include <asn/f1ap/ULRRCMessageTransfer.h> //ASN_NGAP_UplinkNASTransport.h
//


namespace asn::f1ap
{

F1AP_PDU *F1apPduFromPduDescription(InitiatingMessage *desc)
{
    auto pdu = asn::New<F1AP_PDU>();
    pdu->present = F1AP_PDU_PR_initiatingMessage;
    pdu->choice.initiatingMessage = *desc;
    return pdu;
}

F1AP_PDU *F1apPduFromPduDescription(SuccessfulOutcome *desc)
{
    auto pdu = asn::New<F1AP_PDU>();
    pdu->present = F1AP_PDU_PR_successfulOutcome;
    pdu->choice.successfulOutcome = *desc;
    return pdu;
}

F1AP_PDU *F1apPduFromPduDescription(UnsuccessfulOutcome *desc)
{
    auto pdu = asn::New<F1AP_PDU>();
    pdu->present = F1AP_PDU_PR_unsuccessfulOutcome;
    pdu->choice.unsuccessfulOutcome = *desc;
    return pdu;
}

void *NewDescFromMessageType(F1apMessageType type, void *&pOutDescription)
{
    int pduDescription = GetPduDescription(type);
    assert(pduDescription >= 0 && pduDescription <= 2);

    if (pduDescription == 0)
    {
        auto *desc = asn::New<InitiatingMessage>();
        desc->procedureCode = GetProcedureCode(type);
        desc->criticality = GetProcedureCriticality(type);
        desc->value.present = static_cast<InitiatingMessage__value_PR>(GetProcedurePresent(type));
        pOutDescription = desc;

        switch (type)
        {
        case F1apMessageType::GNBCUConfigurationUpdate:
            return &desc->value.choice.GNBCUConfigurationUpdate;
        /*
        case F1apMessageType::HandoverCancel:
            return &desc->value.choice.HandoverCancel;
        case F1apMessageType::HandoverRequired:
            return &desc->value.choice.HandoverRequired;
        case F1apMessageType::HandoverRequest:
            return &desc->value.choice.HandoverRequest;
        */
        case F1apMessageType::UEContextSetupRequest:
            return &desc->value.choice.UEContextSetupRequest;
        case F1apMessageType::Reset:
            return &desc->value.choice.Reset;
        case F1apMessageType::F1SetupRequest:
            return &desc->value.choice.F1SetupRequest;
        /*
        case F1apMessageType::PathSwitchRequest:
            return &desc->value.choice.PathSwitchRequest;
        case F1apMessageType::PDUSessionResourceModifyRequest:
            return &desc->value.choice.PDUSessionResourceModifyRequest;
        case F1apMessageType::PDUSessionResourceModifyIndication:
            return &desc->value.choice.PDUSessionResourceModifyIndication;
        case F1apMessageType::PDUSessionResourceReleaseCommand:
            return &desc->value.choice.PDUSessionResourceReleaseCommand;
        case F1apMessageType::PDUSessionResourceSetupRequest:
            return &desc->value.choice.PDUSessionResourceSetupRequest;
        */
        case F1apMessageType::PWSCancelRequest:
            return &desc->value.choice.PWSCancelRequest;
        case F1apMessageType::GNBDUConfigurationUpdate:
            return &desc->value.choice.GNBDUConfigurationUpdate;
        case F1apMessageType::UEContextModificationRequest:
            return &desc->value.choice.UEContextModificationRequest;
        case F1apMessageType::UEContextReleaseCommand:
            return &desc->value.choice.UEContextReleaseCommand;
        /*
        case F1apMessageType::UERadioCapabilityCheckRequest:
            return &desc->value.choice.UERadioCapabilityCheckRequest;
        case F1apMessageType::WriteReplaceWarningRequest:
            return &desc->value.choice.WriteReplaceWarningRequest;
        */
        //case F1apMessageType::AMFStatusIndication:
        //    return &desc->value.choice.AMFStatusIndication;
        //case F1apMessageType::CellTrafficTrace:
        //    return &desc->value.choice.CellTrafficTrace;
        //case F1apMessageType::DeactivateTrace:
        //    return &desc->value.choice.DeactivateTrace;
        case F1apMessageType::DLRRCMessageTransfer:
            return &desc->value.choice.DLRRCMessageTransfer;
        //case F1apMessageType::DownlinkNonUEAssociatedNRPPaTransport:
        //    return &desc->value.choice.DownlinkNonUEAssociatedNRPPaTransport;
        /*
        case F1apMessageType::DownlinkRANConfigurationTransfer:
            return &desc->value.choice.DownlinkRANConfigurationTransfer;
        case F1apMessageType::DownlinkRANStatusTransfer:
            return &desc->value.choice.DownlinkRANStatusTransfer;
        case F1apMessageType::DownlinkUEAssociatedNRPPaTransport:
            return &desc->value.choice.DownlinkUEAssociatedNRPPaTransport;
        */
        case F1apMessageType::ErrorIndication:
            return &desc->value.choice.ErrorIndication;
        //case F1apMessageType::HandoverNotify:
        //    return &desc->value.choice.HandoverNotify;
        case F1apMessageType::InitialULRRCMessageTransfer:
            return &desc->value.choice.InitialULRRCMessageTransfer;
        /*
        case F1apMessageType::LocationReport:
            return &desc->value.choice.LocationReport;
        case F1apMessageType::LocationReportingControl:
            return &desc->value.choice.LocationReportingControl;
        case F1apMessageType::LocationReportingFailureIndication:
            return &desc->value.choice.LocationReportingFailureIndication;
        case F1apMessageType::NASNonDeliveryIndication:
            return &desc->value.choice.NASNonDeliveryIndication;
        case F1apMessageType::OverloadStart:
            return &desc->value.choice.OverloadStart;
        case F1apMessageType::OverloadStop:
            return &desc->value.choice.OverloadStop;
        */    
        case F1apMessageType::Paging:
            return &desc->value.choice.Paging;
        //case F1apMessageType::PDUSessionResourceNotify:
        //    return &desc->value.choice.PDUSessionResourceNotify;
        case F1apMessageType::PrivateMessage:
            return &desc->value.choice.PrivateMessage;
        case F1apMessageType::PWSFailureIndication:
            return &desc->value.choice.PWSFailureIndication;
        case F1apMessageType::PWSRestartIndication:
            return &desc->value.choice.PWSRestartIndication;
        /*case F1apMessageType::RerouteNASRequest:
            return &desc->value.choice.RerouteNASRequest;
        case F1apMessageType::RRCInactiveTransitionReport:
            return &desc->value.choice.RRCInactiveTransitionReport;
        case F1apMessageType::SecondaryRATDataUsageReport:
            return &desc->value.choice.SecondaryRATDataUsageReport;
        case F1apMessageType::TraceFailureIndication:
            return &desc->value.choice.TraceFailureIndication;
        case F1apMessageType::TraceStart:
            return &desc->value.choice.TraceStart;
        */
        case F1apMessageType::UEContextReleaseRequest:
            return &desc->value.choice.UEContextReleaseRequest;
        /*
        case F1apMessageType::UERadioCapabilityInfoIndication:
            return &desc->value.choice.UERadioCapabilityInfoIndication;
        case F1apMessageType::UETNLABindingReleaseRequest:
            return &desc->value.choice.UETNLABindingReleaseRequest;
        */
        case F1apMessageType::ULRRCMessageTransfer:
            return &desc->value.choice.ULRRCMessageTransfer;
        /*
        case F1apMessageType::UplinkNonUEAssociatedNRPPaTransport:
            return &desc->value.choice.UplinkNonUEAssociatedNRPPaTransport;
        case F1apMessageType::UplinkRANConfigurationTransfer:
            return &desc->value.choice.UplinkRANConfigurationTransfer;
        case F1apMessageType::UplinkRANStatusTransfer:
            return &desc->value.choice.UplinkRANStatusTransfer;
        case F1apMessageType::UplinkUEAssociatedNRPPaTransport:
            return &desc->value.choice.UplinkUEAssociatedNRPPaTransport;
        */
        default:
            assert(false);
        }
    }

    if (pduDescription == 1)
    {
        auto *desc = asn::New<SuccessfulOutcome>();
        desc->procedureCode = GetProcedureCode(type);
        desc->criticality = GetProcedureCriticality(type);
        desc->value.present = static_cast<SuccessfulOutcome__value_PR>(GetProcedurePresent(type));
        pOutDescription = desc;

        switch (type)
        {
        case F1apMessageType::GNBCUConfigurationUpdateAcknowledge:
            return &desc->value.choice.GNBCUConfigurationUpdateAcknowledge;
        /*
        case F1apMessageType::HandoverCancelAcknowledge:
            return &desc->value.choice.HandoverCancelAcknowledge;
        case F1apMessageType::HandoverCommand:
            return &desc->value.choice.HandoverCommand;
        case F1apMessageType::HandoverRequestAcknowledge:
            return &desc->value.choice.HandoverRequestAcknowledge;
        */
        case F1apMessageType::UEContextSetupResponse:
            return &desc->value.choice.UEContextSetupResponse;
        case F1apMessageType::ResetAcknowledge:
            return &desc->value.choice.ResetAcknowledge;
        case F1apMessageType::F1SetupResponse:
            return &desc->value.choice.F1SetupResponse;
        /*
        case F1apMessageType::PathSwitchRequestAcknowledge:
            return &desc->value.choice.PathSwitchRequestAcknowledge;
        case F1apMessageType::PDUSessionResourceModifyResponse:
            return &desc->value.choice.PDUSessionResourceModifyResponse;
        case F1apMessageType::PDUSessionResourceModifyConfirm:
            return &desc->value.choice.PDUSessionResourceModifyConfirm;
        case F1apMessageType::PDUSessionResourceReleaseResponse:
            return &desc->value.choice.PDUSessionResourceReleaseResponse;
        case F1apMessageType::PDUSessionResourceSetupResponse:
            return &desc->value.choice.PDUSessionResourceSetupResponse;
        */
        case F1apMessageType::PWSCancelResponse:
            return &desc->value.choice.PWSCancelResponse;
        case F1apMessageType::GNBDUConfigurationUpdateAcknowledge:
            return &desc->value.choice.GNBDUConfigurationUpdateAcknowledge;
        case F1apMessageType::UEContextModificationResponse:
            return &desc->value.choice.UEContextModificationResponse;
        case F1apMessageType::UEContextReleaseComplete:
            return &desc->value.choice.UEContextReleaseComplete;
        /*
        case F1apMessageType::UERadioCapabilityCheckResponse:
            return &desc->value.choice.UERadioCapabilityCheckResponse;
        case F1apMessageType::WriteReplaceWarningResponse:
            return &desc->value.choice.WriteReplaceWarningResponse;
        */
        default:
            assert(false);
        }
    }

    if (pduDescription == 2)
    {
        auto *desc = asn::New<UnsuccessfulOutcome>();
        desc->procedureCode = GetProcedureCode(type);
        desc->criticality = GetProcedureCriticality(type);
        desc->value.present = static_cast<UnsuccessfulOutcome__value_PR>(GetProcedurePresent(type));
        pOutDescription = desc;

        switch (type)
        {
        case F1apMessageType::GNBCUConfigurationUpdateFailure:
            return &desc->value.choice.GNBCUConfigurationUpdateFailure;
        /*
        case F1apMessageType::HandoverPreparationFailure:
            return &desc->value.choice.HandoverPreparationFailure;
        case F1apMessageType::HandoverFailure:
            return &desc->value.choice.HandoverFailure;
        */
        case F1apMessageType::UEContextSetupFailure:
            return &desc->value.choice.UEContextSetupFailure;
        case F1apMessageType::F1SetupFailure:
            return &desc->value.choice.F1SetupFailure;
        //case F1apMessageType::PathSwitchRequestFailure:
        //    return &desc->value.choice.PathSwitchRequestFailure;
        case F1apMessageType::GNBDUConfigurationUpdateFailure:
            return &desc->value.choice.GNBDUConfigurationUpdateFailure;
        case F1apMessageType::UEContextModificationFailure:
            return &desc->value.choice.UEContextModificationFailure;
        default:
            assert(false);
            break;
        }
    }

    assert(false);
    return nullptr;
}

int GetProcedureCode(F1apMessageType messageType)
{
    switch (messageType)
    {
    case F1apMessageType::GNBCUConfigurationUpdate:
    case F1apMessageType::GNBCUConfigurationUpdateAcknowledge:
    case F1apMessageType::GNBCUConfigurationUpdateFailure:
        return 0;
    //case F1apMessageType::AMFStatusIndication:
    //    return 1;
    //case F1apMessageType::CellTrafficTrace:
    //    return 2;
    //case F1apMessageType::DeactivateTrace:
    //    return 3;
    case F1apMessageType::DLRRCMessageTransfer:
        return 4;
    //case F1apMessageType::DownlinkNonUEAssociatedNRPPaTransport:
    //    return 5;
    /*
    case F1apMessageType::DownlinkRANConfigurationTransfer:
        return 6;
    case F1apMessageType::DownlinkRANStatusTransfer:
        return 7;
    case F1apMessageType::DownlinkUEAssociatedNRPPaTransport:
        return 8;
    */
    case F1apMessageType::ErrorIndication:
        return 9;
    /*
    case F1apMessageType::HandoverCancel:
    case F1apMessageType::HandoverCancelAcknowledge:
        return 10;
    case F1apMessageType::HandoverNotify:
        return 11;
    case F1apMessageType::HandoverPreparationFailure:
    case F1apMessageType::HandoverRequired:
    case F1apMessageType::HandoverCommand:
        return 12;
    case F1apMessageType::HandoverRequest:
    case F1apMessageType::HandoverRequestAcknowledge:
    case F1apMessageType::HandoverFailure:
        return 13;
    */
    case F1apMessageType::UEContextSetupFailure:
    case F1apMessageType::UEContextSetupRequest:
    case F1apMessageType::UEContextSetupResponse:
        return 14;
    case F1apMessageType::InitialULRRCMessageTransfer:
        return 15;
    /*
    case F1apMessageType::LocationReportingControl:
        return 16;
    case F1apMessageType::LocationReportingFailureIndication:
        return 17;
    case F1apMessageType::LocationReport:
        return 18;
    case F1apMessageType::NASNonDeliveryIndication:
        return 19;
    */
    case F1apMessageType::Reset:
    case F1apMessageType::ResetAcknowledge:
        return 20;
    case F1apMessageType::F1SetupFailure:
    case F1apMessageType::F1SetupRequest:
    case F1apMessageType::F1SetupResponse:
        return 21;
    /*
    case F1apMessageType::OverloadStart:
        return 22;
    case F1apMessageType::OverloadStop:
        return 23;
    */
    case F1apMessageType::Paging:
        return 24;
    /*
    case F1apMessageType::PathSwitchRequest:
    case F1apMessageType::PathSwitchRequestAcknowledge:
    case F1apMessageType::PathSwitchRequestFailure:
        return 25;
    case F1apMessageType::PDUSessionResourceModifyRequest:
    case F1apMessageType::PDUSessionResourceModifyResponse:
        return 26;
    case F1apMessageType::PDUSessionResourceModifyConfirm:
    case F1apMessageType::PDUSessionResourceModifyIndication:
        return 27;
    case F1apMessageType::PDUSessionResourceReleaseCommand:
    case F1apMessageType::PDUSessionResourceReleaseResponse:
        return 28;
    case F1apMessageType::PDUSessionResourceSetupRequest:
    case F1apMessageType::PDUSessionResourceSetupResponse:
        return 29;
    case F1apMessageType::PDUSessionResourceNotify:
        return 30;
    */
    case F1apMessageType::PrivateMessage:
        return 31;
    case F1apMessageType::PWSCancelRequest:
    case F1apMessageType::PWSCancelResponse:
        return 32;
    case F1apMessageType::PWSFailureIndication:
        return 33;
    case F1apMessageType::PWSRestartIndication:
        return 34;
    case F1apMessageType::GNBDUConfigurationUpdate:
    case F1apMessageType::GNBDUConfigurationUpdateAcknowledge:
    case F1apMessageType::GNBDUConfigurationUpdateFailure:
        return 35;
    /*case F1apMessageType::RerouteNASRequest:
        return 36;
    case F1apMessageType::RRCInactiveTransitionReport:
        return 37;
    case F1apMessageType::TraceFailureIndication:
        return 38;
    case F1apMessageType::TraceStart:
        return 39;
    */
    case F1apMessageType::UEContextModificationFailure:
    case F1apMessageType::UEContextModificationRequest:
    case F1apMessageType::UEContextModificationResponse:
        return 40;
    case F1apMessageType::UEContextReleaseCommand:
    case F1apMessageType::UEContextReleaseComplete:
        return 41;
    case F1apMessageType::UEContextReleaseRequest:
        return 42;
    /*
    case F1apMessageType::UERadioCapabilityCheckRequest:
    case F1apMessageType::UERadioCapabilityCheckResponse:
    case F1apMessageType::UERadioCapabilityInfoIndication:
        return 44;
    case F1apMessageType::UETNLABindingReleaseRequest:
        return 45;
    */
    case F1apMessageType::ULRRCMessageTransfer:
        return 46;
    /*
    case F1apMessageType::UplinkNonUEAssociatedNRPPaTransport:
        return 47;
    case F1apMessageType::UplinkRANConfigurationTransfer:
        return 48;
    case F1apMessageType::UplinkRANStatusTransfer:
        return 49;
    case F1apMessageType::UplinkUEAssociatedNRPPaTransport:
        return 50;
    case F1apMessageType::WriteReplaceWarningRequest:
    case F1apMessageType::WriteReplaceWarningResponse:
        return 51;
    case F1apMessageType::SecondaryRATDataUsageReport:
        return 52;
    */
    default:
        assert(false);
        break;
    }

    return 0;
}

int GetProcedureCriticality(F1apMessageType messageType)
{
    switch (messageType)
    {
    case F1apMessageType::GNBCUConfigurationUpdate:
    case F1apMessageType::GNBCUConfigurationUpdateAcknowledge:
    case F1apMessageType::GNBCUConfigurationUpdateFailure:
    /*
    case F1apMessageType::HandoverCancel:
    case F1apMessageType::HandoverCancelAcknowledge:
    case F1apMessageType::HandoverCommand:
    case F1apMessageType::HandoverFailure:
    case F1apMessageType::HandoverPreparationFailure:
    case F1apMessageType::HandoverRequest:
    case F1apMessageType::HandoverRequestAcknowledge:
    case F1apMessageType::HandoverRequired:
    */
    case F1apMessageType::UEContextSetupFailure:
    case F1apMessageType::UEContextSetupRequest:
    case F1apMessageType::UEContextSetupResponse:
    case F1apMessageType::Reset:
    case F1apMessageType::ResetAcknowledge:
    case F1apMessageType::F1SetupFailure:
    case F1apMessageType::F1SetupRequest:
    case F1apMessageType::F1SetupResponse:
    /*
    case F1apMessageType::OverloadStop:
    case F1apMessageType::PathSwitchRequest:
    case F1apMessageType::PathSwitchRequestAcknowledge:
    case F1apMessageType::PathSwitchRequestFailure:
    case F1apMessageType::PDUSessionResourceModifyConfirm:
    case F1apMessageType::PDUSessionResourceModifyIndication:
    case F1apMessageType::PDUSessionResourceModifyRequest:
    case F1apMessageType::PDUSessionResourceModifyResponse:
    case F1apMessageType::PDUSessionResourceReleaseCommand:
    case F1apMessageType::PDUSessionResourceReleaseResponse:
    case F1apMessageType::PDUSessionResourceSetupRequest:
    case F1apMessageType::PDUSessionResourceSetupResponse:
    */
    case F1apMessageType::PWSCancelRequest:
    case F1apMessageType::PWSCancelResponse:
    case F1apMessageType::GNBDUConfigurationUpdate:
    case F1apMessageType::GNBDUConfigurationUpdateAcknowledge:
    case F1apMessageType::GNBDUConfigurationUpdateFailure:
    //case F1apMessageType::RerouteNASRequest:
    case F1apMessageType::UEContextModificationFailure:
    case F1apMessageType::UEContextModificationRequest:
    case F1apMessageType::UEContextModificationResponse:
    case F1apMessageType::UEContextReleaseCommand:
    case F1apMessageType::UEContextReleaseComplete:
    /*
    case F1apMessageType::UERadioCapabilityCheckRequest:
    case F1apMessageType::UERadioCapabilityCheckResponse:
    case F1apMessageType::WriteReplaceWarningRequest:
    case F1apMessageType::WriteReplaceWarningResponse:
        return 0;
    */
    //case F1apMessageType::AMFStatusIndication:
    //case F1apMessageType::CellTrafficTrace:
    //case F1apMessageType::DeactivateTrace:
    case F1apMessageType::DLRRCMessageTransfer:
    //case F1apMessageType::DownlinkNonUEAssociatedNRPPaTransport:
    //case F1apMessageType::DownlinkRANConfigurationTransfer:
    //case F1apMessageType::DownlinkRANStatusTransfer:
    //case F1apMessageType::DownlinkUEAssociatedNRPPaTransport:
    case F1apMessageType::ErrorIndication:
    //case F1apMessageType::HandoverNotify:
    case F1apMessageType::InitialULRRCMessageTransfer:
    /*
    case F1apMessageType::LocationReport:
    case F1apMessageType::LocationReportingControl:
    case F1apMessageType::LocationReportingFailureIndication:
    case F1apMessageType::NASNonDeliveryIndication:
    case F1apMessageType::OverloadStart:
    */
    case F1apMessageType::Paging:
    //case F1apMessageType::PDUSessionResourceNotify:
    case F1apMessageType::PrivateMessage:
    case F1apMessageType::PWSFailureIndication:
    case F1apMessageType::PWSRestartIndication:
    /*
    case F1apMessageType::RRCInactiveTransitionReport:
    case F1apMessageType::SecondaryRATDataUsageReport:
    case F1apMessageType::TraceFailureIndication:
    case F1apMessageType::TraceStart:
    */
    case F1apMessageType::UEContextReleaseRequest:
    /*
    case F1apMessageType::UERadioCapabilityInfoIndication:
    case F1apMessageType::UETNLABindingReleaseRequest:
    */
    case F1apMessageType::ULRRCMessageTransfer:
    /*case F1apMessageType::UplinkNonUEAssociatedNRPPaTransport:
    case F1apMessageType::UplinkRANConfigurationTransfer:
    case F1apMessageType::UplinkRANStatusTransfer:
    case F1apMessageType::UplinkUEAssociatedNRPPaTransport:
    */
        return 1;
    default:
        return 2;
    }
}

int GetProcedurePresent(F1apMessageType messageType)
{
    switch (messageType)
    {
    case F1apMessageType::GNBCUConfigurationUpdate:
        return InitiatingMessage__value_PR_GNBCUConfigurationUpdate;
    /*
    case F1apMessageType::HandoverCancel:
        return InitiatingMessage__value_PR_HandoverCancel;
    case F1apMessageType::HandoverRequired:
        return InitiatingMessage__value_PR_HandoverRequired;
    case F1apMessageType::HandoverRequest:
        return InitiatingMessage__value_PR_HandoverRequest;
    */
    case F1apMessageType::UEContextSetupRequest:
        return InitiatingMessage__value_PR_UEContextSetupRequest;
    case F1apMessageType::Reset:
        return InitiatingMessage__value_PR_Reset;
    case F1apMessageType::F1SetupRequest:
        return InitiatingMessage__value_PR_F1SetupRequest;
    /*
    case F1apMessageType::PathSwitchRequest:
        return InitiatingMessage__value_PR_PathSwitchRequest;
    case F1apMessageType::PDUSessionResourceModifyRequest:
        return InitiatingMessage__value_PR_PDUSessionResourceModifyRequest;
    case F1apMessageType::PDUSessionResourceModifyIndication:
        return InitiatingMessage__value_PR_PDUSessionResourceModifyIndication;
    case F1apMessageType::PDUSessionResourceReleaseCommand:
        return InitiatingMessage__value_PR_PDUSessionResourceReleaseCommand;
    case F1apMessageType::PDUSessionResourceSetupRequest:
        return InitiatingMessage__value_PR_PDUSessionResourceSetupRequest;
    */
    case F1apMessageType::PWSCancelRequest:
        return InitiatingMessage__value_PR_PWSCancelRequest;
    case F1apMessageType::GNBDUConfigurationUpdate:
        return InitiatingMessage__value_PR_GNBDUConfigurationUpdate;
    case F1apMessageType::UEContextModificationRequest:
        return InitiatingMessage__value_PR_UEContextModificationRequest;
    case F1apMessageType::UEContextReleaseCommand:
        return InitiatingMessage__value_PR_UEContextReleaseCommand;
    /*
    case F1apMessageType::UERadioCapabilityCheckRequest:
        return InitiatingMessage__value_PR_UERadioCapabilityCheckRequest;
    case F1apMessageType::WriteReplaceWarningRequest:
        return InitiatingMessage__value_PR_WriteReplaceWarningRequest;
    case F1apMessageType::AMFStatusIndication:
        return InitiatingMessage__value_PR_AMFStatusIndication;
    case F1apMessageType::CellTrafficTrace:
        return InitiatingMessage__value_PR_CellTrafficTrace;
    case F1apMessageType::DeactivateTrace:
        return InitiatingMessage__value_PR_DeactivateTrace;
    */
    case F1apMessageType::DLRRCMessageTransfer:
        return InitiatingMessage__value_PR_DLRRCMessageTransfer;
    /*case F1apMessageType::DownlinkNonUEAssociatedNRPPaTransport:
        return InitiatingMessage__value_PR_DownlinkNonUEAssociatedNRPPaTransport;
    case F1apMessageType::DownlinkRANConfigurationTransfer:
        return InitiatingMessage__value_PR_DownlinkRANConfigurationTransfer;
    case F1apMessageType::DownlinkRANStatusTransfer:
        return InitiatingMessage__value_PR_DownlinkRANStatusTransfer;
    case F1apMessageType::DownlinkUEAssociatedNRPPaTransport:
        return InitiatingMessage__value_PR_DownlinkUEAssociatedNRPPaTransport;
    */
    case F1apMessageType::ErrorIndication:
        return InitiatingMessage__value_PR_ErrorIndication;
    //case F1apMessageType::HandoverNotify:
    //    return InitiatingMessage__value_PR_HandoverNotify;
    case F1apMessageType::InitialULRRCMessageTransfer:
        return InitiatingMessage__value_PR_InitialULRRCMessageTransfer;
    /*
    case F1apMessageType::LocationReport:
        return InitiatingMessage__value_PR_LocationReport;
    case F1apMessageType::LocationReportingControl:
        return InitiatingMessage__value_PR_LocationReportingControl;
    case F1apMessageType::LocationReportingFailureIndication:
        return InitiatingMessage__value_PR_LocationReportingFailureIndication;
    case F1apMessageType::NASNonDeliveryIndication:
        return InitiatingMessage__value_PR_NASNonDeliveryIndication;
    case F1apMessageType::OverloadStart:
        return InitiatingMessage__value_PR_OverloadStart;
    case F1apMessageType::OverloadStop:
        return InitiatingMessage__value_PR_OverloadStop;
    */
    case F1apMessageType::Paging:
        return InitiatingMessage__value_PR_Paging;
    //case F1apMessageType::PDUSessionResourceNotify:
    //    return InitiatingMessage__value_PR_PDUSessionResourceNotify;
    case F1apMessageType::PrivateMessage:
        return InitiatingMessage__value_PR_PrivateMessage;
    case F1apMessageType::PWSFailureIndication:
        return InitiatingMessage__value_PR_PWSFailureIndication;
    case F1apMessageType::PWSRestartIndication:
        return InitiatingMessage__value_PR_PWSRestartIndication;
    /*
    case F1apMessageType::RerouteNASRequest:
        return InitiatingMessage__value_PR_RerouteNASRequest;
    case F1apMessageType::RRCInactiveTransitionReport:
        return InitiatingMessage__value_PR_RRCInactiveTransitionReport;
    case F1apMessageType::SecondaryRATDataUsageReport:
        return InitiatingMessage__value_PR_SecondaryRATDataUsageReport;
    case F1apMessageType::TraceFailureIndication:
        return InitiatingMessage__value_PR_TraceFailureIndication;
    case F1apMessageType::TraceStart:
        return InitiatingMessage__value_PR_TraceStart;
    */
    case F1apMessageType::UEContextReleaseRequest:
        return InitiatingMessage__value_PR_UEContextReleaseRequest;
    /*
    case F1apMessageType::UERadioCapabilityInfoIndication:
        return InitiatingMessage__value_PR_UERadioCapabilityInfoIndication;
    case F1apMessageType::UETNLABindingReleaseRequest:
        return InitiatingMessage__value_PR_UETNLABindingReleaseRequest;
    */
    case F1apMessageType::ULRRCMessageTransfer:
        return InitiatingMessage__value_PR_ULRRCMessageTransfer;
    /*
    case F1apMessageType::UplinkNonUEAssociatedNRPPaTransport:
        return InitiatingMessage__value_PR_UplinkNonUEAssociatedNRPPaTransport;
    case F1apMessageType::UplinkRANConfigurationTransfer:
        return InitiatingMessage__value_PR_UplinkRANConfigurationTransfer;
    case F1apMessageType::UplinkRANStatusTransfer:
        return InitiatingMessage__value_PR_UplinkRANStatusTransfer;
    case F1apMessageType::UplinkUEAssociatedNRPPaTransport:
        return InitiatingMessage__value_PR_UplinkUEAssociatedNRPPaTransport;
    */
    case F1apMessageType::GNBCUConfigurationUpdateAcknowledge:
        return SuccessfulOutcome__value_PR_GNBCUConfigurationUpdateAcknowledge;
    /*
    case F1apMessageType::HandoverCancelAcknowledge:
        return SuccessfulOutcome__value_PR_HandoverCancelAcknowledge;
    case F1apMessageType::HandoverCommand:
        return SuccessfulOutcome__value_PR_HandoverCommand;
    case F1apMessageType::HandoverRequestAcknowledge:
        return SuccessfulOutcome__value_PR_HandoverRequestAcknowledge;
    */
    case F1apMessageType::UEContextSetupResponse:
        return SuccessfulOutcome__value_PR_UEContextSetupResponse;
    case F1apMessageType::ResetAcknowledge:
        return SuccessfulOutcome__value_PR_ResetAcknowledge;
    case F1apMessageType::F1SetupResponse:
        return SuccessfulOutcome__value_PR_F1SetupResponse;
    /*
    case F1apMessageType::PathSwitchRequestAcknowledge:
        return SuccessfulOutcome__value_PR_PathSwitchRequestAcknowledge;
    case F1apMessageType::PDUSessionResourceModifyResponse:
        return SuccessfulOutcome__value_PR_PDUSessionResourceModifyResponse;
    case F1apMessageType::PDUSessionResourceModifyConfirm:
        return SuccessfulOutcome__value_PR_PDUSessionResourceModifyConfirm;
    case F1apMessageType::PDUSessionResourceReleaseResponse:
        return SuccessfulOutcome__value_PR_PDUSessionResourceReleaseResponse;
    case F1apMessageType::PDUSessionResourceSetupResponse:
        return SuccessfulOutcome__value_PR_PDUSessionResourceSetupResponse;
    */
    case F1apMessageType::PWSCancelResponse:
        return SuccessfulOutcome__value_PR_PWSCancelResponse;
    case F1apMessageType::GNBDUConfigurationUpdateAcknowledge:
        return SuccessfulOutcome__value_PR_GNBDUConfigurationUpdateAcknowledge;
    case F1apMessageType::UEContextModificationResponse:
        return SuccessfulOutcome__value_PR_UEContextModificationResponse;
    case F1apMessageType::UEContextReleaseComplete:
        return SuccessfulOutcome__value_PR_UEContextReleaseComplete;
    /*
    case F1apMessageType::UERadioCapabilityCheckResponse:
        return SuccessfulOutcome__value_PR_UERadioCapabilityCheckResponse;
    case F1apMessageType::WriteReplaceWarningResponse:
        return SuccessfulOutcome__value_PR_WriteReplaceWarningResponse;
    */
    case F1apMessageType::GNBCUConfigurationUpdateFailure:
        return UnsuccessfulOutcome__value_PR_GNBCUConfigurationUpdateFailure;
    /*
    case F1apMessageType::HandoverPreparationFailure:
        return UnsuccessfulOutcome__value_PR_HandoverPreparationFailure;
    case F1apMessageType::HandoverFailure:
        return UnsuccessfulOutcome__value_PR_HandoverFailure;
    */
    case F1apMessageType::UEContextSetupFailure:
        return UnsuccessfulOutcome__value_PR_UEContextSetupFailure;
    case F1apMessageType::F1SetupFailure:
        return UnsuccessfulOutcome__value_PR_F1SetupFailure;
    /*
    case F1apMessageType::PathSwitchRequestFailure:
        return UnsuccessfulOutcome__value_PR_PathSwitchRequestFailure;
    */
    case F1apMessageType::GNBDUConfigurationUpdateFailure:
        return UnsuccessfulOutcome__value_PR_GNBDUConfigurationUpdateFailure;
    case F1apMessageType::UEContextModificationFailure:
        return UnsuccessfulOutcome__value_PR_UEContextModificationFailure;
    default:
        assert(false);
        break;
    }

    return 0;
}

int GetPduDescription(F1apMessageType messageType)
{
    switch (messageType)
    {
    case F1apMessageType::GNBCUConfigurationUpdate:
    /*
    case F1apMessageType::HandoverCancel:
    case F1apMessageType::HandoverRequired:
    case F1apMessageType::HandoverRequest:
    */
    case F1apMessageType::UEContextSetupRequest:
    case F1apMessageType::Reset:
    case F1apMessageType::F1SetupRequest:
    /*
    case F1apMessageType::PathSwitchRequest:
    case F1apMessageType::PDUSessionResourceModifyRequest:
    case F1apMessageType::PDUSessionResourceModifyIndication:
    case F1apMessageType::PDUSessionResourceReleaseCommand:
    case F1apMessageType::PDUSessionResourceSetupRequest:
    */
    case F1apMessageType::PWSCancelRequest:
    case F1apMessageType::GNBDUConfigurationUpdate:
    case F1apMessageType::UEContextModificationRequest:
    case F1apMessageType::UEContextReleaseCommand:
    /*
    case F1apMessageType::UERadioCapabilityCheckRequest:
    case F1apMessageType::WriteReplaceWarningRequest:
    case F1apMessageType::AMFStatusIndication:
    case F1apMessageType::CellTrafficTrace:
    case F1apMessageType::DeactivateTrace:
    */
    case F1apMessageType::DLRRCMessageTransfer:
    //case F1apMessageType::DownlinkNonUEAssociatedNRPPaTransport:
    //case F1apMessageType::DownlinkRANConfigurationTransfer:
    //case F1apMessageType::DownlinkRANStatusTransfer:
    //case F1apMessageType::DownlinkUEAssociatedNRPPaTransport:
    case F1apMessageType::ErrorIndication:
    //case F1apMessageType::HandoverNotify:
    case F1apMessageType::InitialULRRCMessageTransfer:
    /*
    case F1apMessageType::LocationReport:
    case F1apMessageType::LocationReportingControl:
    case F1apMessageType::LocationReportingFailureIndication:
    case F1apMessageType::NASNonDeliveryIndication:
    case F1apMessageType::OverloadStart:
    case F1apMessageType::OverloadStop:
    */
    case F1apMessageType::Paging:
    //case F1apMessageType::PDUSessionResourceNotify:
    case F1apMessageType::PrivateMessage:
    case F1apMessageType::PWSFailureIndication:
    case F1apMessageType::PWSRestartIndication:
    /*
    case F1apMessageType::RerouteNASRequest:
    case F1apMessageType::RRCInactiveTransitionReport:
    case F1apMessageType::SecondaryRATDataUsageReport:
    case F1apMessageType::TraceFailureIndication:
    case F1apMessageType::TraceStart:
    */
    case F1apMessageType::UEContextReleaseRequest:
    //case F1apMessageType::UERadioCapabilityInfoIndication:
    //case F1apMessageType::UETNLABindingReleaseRequest:
    case F1apMessageType::ULRRCMessageTransfer:
    /*
    case F1apMessageType::UplinkNonUEAssociatedNRPPaTransport:
    case F1apMessageType::UplinkRANConfigurationTransfer:
    case F1apMessageType::UplinkRANStatusTransfer:
    case F1apMessageType::UplinkUEAssociatedNRPPaTransport:
    */
        return 0;

    case F1apMessageType::GNBCUConfigurationUpdateAcknowledge:
    /*
    case F1apMessageType::HandoverCancelAcknowledge:
    case F1apMessageType::HandoverCommand:
    case F1apMessageType::HandoverRequestAcknowledge:
    */
    case F1apMessageType::UEContextSetupResponse:
    case F1apMessageType::ResetAcknowledge:
    case F1apMessageType::F1SetupResponse:
    /*
    case F1apMessageType::PathSwitchRequestAcknowledge:
    case F1apMessageType::PDUSessionResourceModifyResponse:
    case F1apMessageType::PDUSessionResourceModifyConfirm:
    case F1apMessageType::PDUSessionResourceReleaseResponse:
    case F1apMessageType::PDUSessionResourceSetupResponse:
    */
    case F1apMessageType::PWSCancelResponse:
    case F1apMessageType::GNBDUConfigurationUpdateAcknowledge:
    case F1apMessageType::UEContextModificationResponse:
    case F1apMessageType::UEContextReleaseComplete:
    //case F1apMessageType::UERadioCapabilityCheckResponse:
    //case F1apMessageType::WriteReplaceWarningResponse:
        return 1;

    case F1apMessageType::GNBCUConfigurationUpdateFailure:
    //case F1apMessageType::HandoverPreparationFailure:
    //case F1apMessageType::HandoverFailure:
    case F1apMessageType::UEContextSetupFailure:
    case F1apMessageType::F1SetupFailure:
    //case F1apMessageType::PathSwitchRequestFailure:
    case F1apMessageType::GNBDUConfigurationUpdateFailure:
    case F1apMessageType::UEContextModificationFailure:
        return 2;
    default:
        assert(false);
        break;
    }

    return 0;
}

struct IeFieldInfo
{
    unsigned int ieIdOffset;
    unsigned int ieCriticalityOffset;
    unsigned int ieStructSize;
    void *listPtr;
    unsigned int presOffset;
    unsigned int choiceOffset;
    unsigned int presSize;
    unsigned int memberIndex;
    void *protocolIeContainerPtr;
    asn_anonymous_set_ *list;
};

static bool GetProtocolIeInfo(const F1AP_PDU &pdu, const asn_TYPE_descriptor_t &ieType, IeFieldInfo &info)
{
    if (!utils::IsLittleEndian())
        throw std::runtime_error("Big Endian architecture is not supported");

    const asn_TYPE_descriptor_t *desc = nullptr;
    const void *ptr = nullptr;

    // Check the present value of the PDU
    switch (pdu.present)
    {
    case F1AP_PDU_PR_initiatingMessage:
        desc = &asn_DEF_InitiatingMessage;
        ptr = static_cast<const void*>(&pdu.choice.initiatingMessage);
        break;
    case F1AP_PDU_PR_successfulOutcome:
        desc = &asn_DEF_SuccessfulOutcome;
        ptr = static_cast<const void*>(&pdu.choice.successfulOutcome);
        break;
    case F1AP_PDU_PR_unsuccessfulOutcome:
        desc = &asn_DEF_UnsuccessfulOutcome;
        ptr = static_cast<const void*>(&pdu.choice.unsuccessfulOutcome);
        break;
    default:
        return false;
    }

    // Navigate to the IE container
    ptr = static_cast<const int8_t*>(ptr) + desc->elements[2].memb_offset;
    desc = desc->elements[2].type;

    const auto *members = desc->elements;
    unsigned memberCount = desc->elements_count;

    const auto *choiceSpecs = reinterpret_cast<const asn_CHOICE_specifics_t *>(desc->specifics);
    unsigned presentEnumSize = choiceSpecs->pres_size;

    const auto *presPtr = static_cast<const int8_t*>(ptr) + choiceSpecs->pres_offset;

    // Read the present value
    uint64_t presentValue = 0;
    for (unsigned i = 0; i < presentEnumSize; i++)
        presentValue += (static_cast<uint64_t>(*(presPtr + i)) & 0xFF) << (i * 8);

    if (presentValue == 0 || presentValue > memberCount)
        return false;

    // Cast safely and ensure const correctness
    ptr = static_cast<const int8_t*>(ptr) + members[presentValue - 1].memb_offset;
    desc = members[presentValue - 1].type;

    members = desc->elements;
    memberCount = desc->elements_count;

    ptr = static_cast<const int8_t*>(ptr) + members[0].memb_offset;
    desc = members[0].type;

    // Cast to const void* to avoid issues
    info.protocolIeContainerPtr = const_cast<void*>(ptr);

    members = desc->elements;
    memberCount = desc->elements_count;

    ptr = static_cast<const int8_t*>(ptr) + members[0].memb_offset;
    desc = members[0].type;

    members = desc->elements;
    memberCount = desc->elements_count;

    info.ieIdOffset = members[0].memb_offset;
    info.ieCriticalityOffset = members[1].memb_offset;
    info.ieStructSize = reinterpret_cast<const asn_SEQUENCE_specifics_t *>(desc->specifics)->struct_size;

    info.listPtr = const_cast<void*>(ptr);

    info.presOffset = members[2].memb_offset;
    info.choiceOffset = members[2].memb_offset;

    ptr = static_cast<const int8_t*>(ptr) + members[2].memb_offset;
    desc = members[2].type;

    members = desc->elements;
    memberCount = desc->elements_count;

    choiceSpecs = reinterpret_cast<const asn_CHOICE_specifics_t *>(desc->specifics);
    info.presOffset += choiceSpecs->pres_offset;

    info.presSize = choiceSpecs->pres_size;

    info.memberIndex = ~0U;

    for (unsigned i = 0; i < memberCount; i++)
    {
        if (members[i].type == &ieType)
        {
            info.memberIndex = i;
            break;
        }
    }

    if (info.memberIndex == ~0U)
        return false;

    ptr = static_cast<const int8_t*>(ptr) + members[info.memberIndex].memb_offset;
    desc = members[info.memberIndex].type;

    info.choiceOffset += members[info.memberIndex].memb_offset;

    info.list = reinterpret_cast<asn_anonymous_set_ *>(info.listPtr);

    return true;
}

/*static bool GetProtocolIeInfo(const F1AP_PDU &pdu, const asn_TYPE_descriptor_t &ieType, IeFieldInfo &info)
{
    // This function assumes all ASN structs are "C++ standard layout".
    // Therefore no problem is expected since the structs are already standard layout.

    // Assert that the machine is Little Endian. (This assumption is used for presentEnumSize and related)
    if (!utils::IsLittleEndian())
        throw std::runtime_error("Big Endian architecture is not supported");

    asn_TYPE_descriptor_t *desc;
    const void *ptr;

    if (pdu.present == F1AP_PDU_PR_initiatingMessage)
    {
        desc = &asn_DEF_InitiatingMessage;
        ptr = static_cast<const void*>(&pdu.choice.initiatingMessage);
    }
    else if (pdu.present == F1AP_PDU_PR_successfulOutcome)
    {
        desc = &asn_DEF_SuccessfulOutcome;
        ptr = static_cast<const void*>(&pdu.choice.successfulOutcome);
    }
    else if (pdu.present == F1AP_PDU_PR_unsuccessfulOutcome)
    {
        desc = &asn_DEF_UnsuccessfulOutcome;
        ptr = static_cast<const void*>(&pdu.choice.unsuccessfulOutcome);
    }
    else
        return false;

    ptr = static_cast<const int8_t*>(ptr) + desc->elements[2].memb_offset;
    desc = desc->elements[2].type;

    auto members = desc->elements;
    unsigned memberCount = desc->elements_count;

    auto choiceSpecs = reinterpret_cast<const asn_CHOICE_specifics_t *>(desc->specifics);

    unsigned presentEnumSize = choiceSpecs->pres_size;

    auto presPtr = static_cast<const int8_t*>(ptr) + choiceSpecs->pres_offset;
    //auto presPtr = reinterpret_cast<int8_t *>(ptr) + choiceSpecs->pres_offset;

    uint64_t presentValue = 0;
    for (unsigned i = 0; i < presentEnumSize; i++)
        presentValue += (*(presPtr + i) & 0xFF) << (i * 8);

    if (presentValue == 0)
        return false;

    ptr = static_cast<const int8_t*>(ptr) + members[presentValue - 1].memb_offset;
    //ptr = reinterpret_cast<int8_t *>(ptr) + members[presentValue - 1].memb_offset;
    desc = members[presentValue - 1].type;

    members = desc->elements;
    memberCount = desc->elements_count;

    ptr = reinterpret_cast<int8_t *>(ptr) + members[0].memb_offset;
    desc = members[0].type;

    info.protocolIeContainerPtr = ptr;

    members = desc->elements;
    memberCount = desc->elements_count;

    ptr = reinterpret_cast<int8_t *>(ptr) + members[0].memb_offset;
    desc = members[0].type;

    members = desc->elements;
    memberCount = desc->elements_count;

    info.ieIdOffset = members[0].memb_offset;
    info.ieCriticalityOffset = members[1].memb_offset;
    info.ieStructSize = reinterpret_cast<const asn_SEQUENCE_specifics_t *>(desc->specifics)->struct_size;

    info.listPtr = const_cast<void*>(ptr);
    //info.listPtr = ptr;

    info.presOffset = members[2].memb_offset;
    info.choiceOffset = members[2].memb_offset;

    ptr = reinterpret_cast<int8_t *>(ptr) + members[2].memb_offset;
    desc = members[2].type;

    members = desc->elements;
    memberCount = desc->elements_count;

    choiceSpecs = reinterpret_cast<const asn_CHOICE_specifics_t *>(desc->specifics);
    info.presOffset += choiceSpecs->pres_offset;

    info.presSize = choiceSpecs->pres_size;

    info.memberIndex = ~0;

    for (unsigned i = 0; i < memberCount; i++)
    {
        if (members[i].type == &ieType)
        {
            // NOT: Birden fazla varsa ilk buludğunu alıyor.
            info.memberIndex = i;
            break;
        }
    }

    if (info.memberIndex == ~0U)
        return false;

    ptr = reinterpret_cast<int8_t *>(ptr) + members[info.memberIndex].memb_offset;
    desc = members[info.memberIndex].type;

    info.choiceOffset += members[info.memberIndex].memb_offset;

    info.list = reinterpret_cast<asn_anonymous_set_ *>(info.listPtr);

    return true;
}
*/
bool IsProtocolIeUsable(const F1AP_PDU &pdu, const asn_TYPE_descriptor_t &ieType)
{
    IeFieldInfo inf{};
    return GetProtocolIeInfo(pdu, ieType, inf);
}

void *FindProtocolIeInPdu(const F1AP_PDU &pdu, const asn_TYPE_descriptor_t &ieType, int protocolIeId)
{
    IeFieldInfo inf{};
    if (!GetProtocolIeInfo(pdu, ieType, inf))
        return nullptr;

    for (int i = 0; i < inf.list->count; i++)
    {
        void *item = inf.list->array[i];
        ProtocolIE_ID_t ieId =
            *reinterpret_cast<ProtocolIE_ID_t *>((reinterpret_cast<int8_t *>(item) + inf.ieIdOffset));
        if (ieId == protocolIeId)
        {
            auto *valuePlace = (void *)(reinterpret_cast<int8_t *>(item) + inf.choiceOffset);
            return valuePlace;
        }
    }
    return nullptr;
}

bool AddProtocolIeIfUsable(const F1AP_PDU &pdu, const asn_TYPE_descriptor_t &ieType, int protocolIeId,
                           int criticality, const std::function<void(void *)> &ieCreator)
{
    IeFieldInfo inf{};
    if (!GetProtocolIeInfo(pdu, ieType, inf))
        return false;

    /* Create and add new protocol IE field */
    {
        void *newIe = calloc(1, inf.ieStructSize);

        *reinterpret_cast<ProtocolIE_ID_t *>((reinterpret_cast<int8_t *>(newIe) + inf.ieIdOffset)) =
            protocolIeId;
        *reinterpret_cast<Criticality_t *>((reinterpret_cast<int8_t *>(newIe) + inf.ieCriticalityOffset)) =
            criticality;

        auto *newPresPtr = (reinterpret_cast<int8_t *>(newIe) + inf.presOffset);

        for (unsigned i = 0; i < inf.presSize; i++)
            newPresPtr[i] = ((inf.memberIndex + 1) >> (i * 8)) & 0xFF;

        auto *valuePlace = (void *)(reinterpret_cast<int8_t *>(newIe) + inf.choiceOffset);
        ieCreator(valuePlace);

        ASN_SEQUENCE_ADD(inf.protocolIeContainerPtr, newIe);

        // Sorting according to present value. See "asn::ngap::AddProtocolIe" function.
        std::sort(inf.list->array, inf.list->array + inf.list->count, [&inf](void *a, void *b) {
            auto *aPresPtr = reinterpret_cast<int8_t *>(a) + inf.presOffset;
            auto *bPresPtr = reinterpret_cast<int8_t *>(b) + inf.presOffset;

            uint64_t aPresValue = 0, bPresValue = 0;
            for (unsigned i = 0; i < inf.presSize; i++)
            {
                aPresValue += (*(aPresPtr + i) & 0xFF) << (i * 8);
                bPresValue += (*(bPresPtr + i) & 0xFF) << (i * 8);
            }

            return aPresValue < bPresValue;
        });
    }

    return true;
}

} // namespace asn::f1ap
