/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-CommonDataTypes"
 * 	found in "asn/ngap-15.8.0.asn1" 
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ngap`
 */

#ifndef	_ASN_NGAP_ProtocolIE_ID_H_
#define	_ASN_NGAP_ProtocolIE_ID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ASN_NGAP_ProtocolIE-ID */
typedef long	 ASN_NGAP_ProtocolIE_ID_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ASN_NGAP_ProtocolIE_ID_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ASN_NGAP_ProtocolIE_ID;
asn_struct_free_f ASN_NGAP_ProtocolIE_ID_free;
asn_struct_print_f ASN_NGAP_ProtocolIE_ID_print;
asn_constr_check_f ASN_NGAP_ProtocolIE_ID_constraint;
ber_type_decoder_f ASN_NGAP_ProtocolIE_ID_decode_ber;
der_type_encoder_f ASN_NGAP_ProtocolIE_ID_encode_der;
xer_type_decoder_f ASN_NGAP_ProtocolIE_ID_decode_xer;
xer_type_encoder_f ASN_NGAP_ProtocolIE_ID_encode_xer;
per_type_decoder_f ASN_NGAP_ProtocolIE_ID_decode_uper;
per_type_encoder_f ASN_NGAP_ProtocolIE_ID_encode_uper;
per_type_decoder_f ASN_NGAP_ProtocolIE_ID_decode_aper;
per_type_encoder_f ASN_NGAP_ProtocolIE_ID_encode_aper;
#define ASN_NGAP_ProtocolIE_ID_id_AllowedNSSAI	((ASN_NGAP_ProtocolIE_ID_t)0)
#define ASN_NGAP_ProtocolIE_ID_id_AMFName	((ASN_NGAP_ProtocolIE_ID_t)1)
#define ASN_NGAP_ProtocolIE_ID_id_AMFOverloadResponse	((ASN_NGAP_ProtocolIE_ID_t)2)
#define ASN_NGAP_ProtocolIE_ID_id_AMFSetID	((ASN_NGAP_ProtocolIE_ID_t)3)
#define ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationFailedToSetupList	((ASN_NGAP_ProtocolIE_ID_t)4)
#define ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationSetupList	((ASN_NGAP_ProtocolIE_ID_t)5)
#define ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationToAddList	((ASN_NGAP_ProtocolIE_ID_t)6)
#define ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationToRemoveList	((ASN_NGAP_ProtocolIE_ID_t)7)
#define ASN_NGAP_ProtocolIE_ID_id_AMF_TNLAssociationToUpdateList	((ASN_NGAP_ProtocolIE_ID_t)8)
#define ASN_NGAP_ProtocolIE_ID_id_AMFTrafficLoadReductionIndication	((ASN_NGAP_ProtocolIE_ID_t)9)
#define ASN_NGAP_ProtocolIE_ID_id_AMF_UE_NGAP_ID	((ASN_NGAP_ProtocolIE_ID_t)10)
#define ASN_NGAP_ProtocolIE_ID_id_AssistanceDataForPaging	((ASN_NGAP_ProtocolIE_ID_t)11)
#define ASN_NGAP_ProtocolIE_ID_id_BroadcastCancelledAreaList	((ASN_NGAP_ProtocolIE_ID_t)12)
#define ASN_NGAP_ProtocolIE_ID_id_BroadcastCompletedAreaList	((ASN_NGAP_ProtocolIE_ID_t)13)
#define ASN_NGAP_ProtocolIE_ID_id_CancelAllWarningMessages	((ASN_NGAP_ProtocolIE_ID_t)14)
#define ASN_NGAP_ProtocolIE_ID_id_Cause	((ASN_NGAP_ProtocolIE_ID_t)15)
#define ASN_NGAP_ProtocolIE_ID_id_CellIDListForRestart	((ASN_NGAP_ProtocolIE_ID_t)16)
#define ASN_NGAP_ProtocolIE_ID_id_ConcurrentWarningMessageInd	((ASN_NGAP_ProtocolIE_ID_t)17)
#define ASN_NGAP_ProtocolIE_ID_id_CoreNetworkAssistanceInformationForInactive	((ASN_NGAP_ProtocolIE_ID_t)18)
#define ASN_NGAP_ProtocolIE_ID_id_CriticalityDiagnostics	((ASN_NGAP_ProtocolIE_ID_t)19)
#define ASN_NGAP_ProtocolIE_ID_id_DataCodingScheme	((ASN_NGAP_ProtocolIE_ID_t)20)
#define ASN_NGAP_ProtocolIE_ID_id_DefaultPagingDRX	((ASN_NGAP_ProtocolIE_ID_t)21)
#define ASN_NGAP_ProtocolIE_ID_id_DirectForwardingPathAvailability	((ASN_NGAP_ProtocolIE_ID_t)22)
#define ASN_NGAP_ProtocolIE_ID_id_EmergencyAreaIDListForRestart	((ASN_NGAP_ProtocolIE_ID_t)23)
#define ASN_NGAP_ProtocolIE_ID_id_EmergencyFallbackIndicator	((ASN_NGAP_ProtocolIE_ID_t)24)
#define ASN_NGAP_ProtocolIE_ID_id_EUTRA_CGI	((ASN_NGAP_ProtocolIE_ID_t)25)
#define ASN_NGAP_ProtocolIE_ID_id_FiveG_S_TMSI	((ASN_NGAP_ProtocolIE_ID_t)26)
#define ASN_NGAP_ProtocolIE_ID_id_GlobalRANNodeID	((ASN_NGAP_ProtocolIE_ID_t)27)
#define ASN_NGAP_ProtocolIE_ID_id_GUAMI	((ASN_NGAP_ProtocolIE_ID_t)28)
#define ASN_NGAP_ProtocolIE_ID_id_HandoverType	((ASN_NGAP_ProtocolIE_ID_t)29)
#define ASN_NGAP_ProtocolIE_ID_id_IMSVoiceSupportIndicator	((ASN_NGAP_ProtocolIE_ID_t)30)
#define ASN_NGAP_ProtocolIE_ID_id_IndexToRFSP	((ASN_NGAP_ProtocolIE_ID_t)31)
#define ASN_NGAP_ProtocolIE_ID_id_InfoOnRecommendedCellsAndRANNodesForPaging	((ASN_NGAP_ProtocolIE_ID_t)32)
#define ASN_NGAP_ProtocolIE_ID_id_LocationReportingRequestType	((ASN_NGAP_ProtocolIE_ID_t)33)
#define ASN_NGAP_ProtocolIE_ID_id_MaskedIMEISV	((ASN_NGAP_ProtocolIE_ID_t)34)
#define ASN_NGAP_ProtocolIE_ID_id_MessageIdentifier	((ASN_NGAP_ProtocolIE_ID_t)35)
#define ASN_NGAP_ProtocolIE_ID_id_MobilityRestrictionList	((ASN_NGAP_ProtocolIE_ID_t)36)
#define ASN_NGAP_ProtocolIE_ID_id_NASC	((ASN_NGAP_ProtocolIE_ID_t)37)
#define ASN_NGAP_ProtocolIE_ID_id_NAS_PDU	((ASN_NGAP_ProtocolIE_ID_t)38)
#define ASN_NGAP_ProtocolIE_ID_id_NASSecurityParametersFromNGRAN	((ASN_NGAP_ProtocolIE_ID_t)39)
#define ASN_NGAP_ProtocolIE_ID_id_NewAMF_UE_NGAP_ID	((ASN_NGAP_ProtocolIE_ID_t)40)
#define ASN_NGAP_ProtocolIE_ID_id_NewSecurityContextInd	((ASN_NGAP_ProtocolIE_ID_t)41)
#define ASN_NGAP_ProtocolIE_ID_id_NGAP_Message	((ASN_NGAP_ProtocolIE_ID_t)42)
#define ASN_NGAP_ProtocolIE_ID_id_NGRAN_CGI	((ASN_NGAP_ProtocolIE_ID_t)43)
#define ASN_NGAP_ProtocolIE_ID_id_NGRANTraceID	((ASN_NGAP_ProtocolIE_ID_t)44)
#define ASN_NGAP_ProtocolIE_ID_id_NR_CGI	((ASN_NGAP_ProtocolIE_ID_t)45)
#define ASN_NGAP_ProtocolIE_ID_id_NRPPa_PDU	((ASN_NGAP_ProtocolIE_ID_t)46)
#define ASN_NGAP_ProtocolIE_ID_id_NumberOfBroadcastsRequested	((ASN_NGAP_ProtocolIE_ID_t)47)
#define ASN_NGAP_ProtocolIE_ID_id_OldAMF	((ASN_NGAP_ProtocolIE_ID_t)48)
#define ASN_NGAP_ProtocolIE_ID_id_OverloadStartNSSAIList	((ASN_NGAP_ProtocolIE_ID_t)49)
#define ASN_NGAP_ProtocolIE_ID_id_PagingDRX	((ASN_NGAP_ProtocolIE_ID_t)50)
#define ASN_NGAP_ProtocolIE_ID_id_PagingOrigin	((ASN_NGAP_ProtocolIE_ID_t)51)
#define ASN_NGAP_ProtocolIE_ID_id_PagingPriority	((ASN_NGAP_ProtocolIE_ID_t)52)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceAdmittedList	((ASN_NGAP_ProtocolIE_ID_t)53)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceFailedToModifyListModRes	((ASN_NGAP_ProtocolIE_ID_t)54)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceFailedToSetupListCxtRes	((ASN_NGAP_ProtocolIE_ID_t)55)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceFailedToSetupListHOAck	((ASN_NGAP_ProtocolIE_ID_t)56)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceFailedToSetupListPSReq	((ASN_NGAP_ProtocolIE_ID_t)57)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceFailedToSetupListSURes	((ASN_NGAP_ProtocolIE_ID_t)58)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceHandoverList	((ASN_NGAP_ProtocolIE_ID_t)59)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceListCxtRelCpl	((ASN_NGAP_ProtocolIE_ID_t)60)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceListHORqd	((ASN_NGAP_ProtocolIE_ID_t)61)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceModifyListModCfm	((ASN_NGAP_ProtocolIE_ID_t)62)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceModifyListModInd	((ASN_NGAP_ProtocolIE_ID_t)63)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceModifyListModReq	((ASN_NGAP_ProtocolIE_ID_t)64)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceModifyListModRes	((ASN_NGAP_ProtocolIE_ID_t)65)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceNotifyList	((ASN_NGAP_ProtocolIE_ID_t)66)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceReleasedListNot	((ASN_NGAP_ProtocolIE_ID_t)67)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceReleasedListPSAck	((ASN_NGAP_ProtocolIE_ID_t)68)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceReleasedListPSFail	((ASN_NGAP_ProtocolIE_ID_t)69)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceReleasedListRelRes	((ASN_NGAP_ProtocolIE_ID_t)70)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceSetupListCxtReq	((ASN_NGAP_ProtocolIE_ID_t)71)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceSetupListCxtRes	((ASN_NGAP_ProtocolIE_ID_t)72)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceSetupListHOReq	((ASN_NGAP_ProtocolIE_ID_t)73)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceSetupListSUReq	((ASN_NGAP_ProtocolIE_ID_t)74)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceSetupListSURes	((ASN_NGAP_ProtocolIE_ID_t)75)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceToBeSwitchedDLList	((ASN_NGAP_ProtocolIE_ID_t)76)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceSwitchedList	((ASN_NGAP_ProtocolIE_ID_t)77)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceToReleaseListHOCmd	((ASN_NGAP_ProtocolIE_ID_t)78)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceToReleaseListRelCmd	((ASN_NGAP_ProtocolIE_ID_t)79)
#define ASN_NGAP_ProtocolIE_ID_id_PLMNSupportList	((ASN_NGAP_ProtocolIE_ID_t)80)
#define ASN_NGAP_ProtocolIE_ID_id_PWSFailedCellIDList	((ASN_NGAP_ProtocolIE_ID_t)81)
#define ASN_NGAP_ProtocolIE_ID_id_RANNodeName	((ASN_NGAP_ProtocolIE_ID_t)82)
#define ASN_NGAP_ProtocolIE_ID_id_RANPagingPriority	((ASN_NGAP_ProtocolIE_ID_t)83)
#define ASN_NGAP_ProtocolIE_ID_id_RANStatusTransfer_TransparentContainer	((ASN_NGAP_ProtocolIE_ID_t)84)
#define ASN_NGAP_ProtocolIE_ID_id_RAN_UE_NGAP_ID	((ASN_NGAP_ProtocolIE_ID_t)85)
#define ASN_NGAP_ProtocolIE_ID_id_RelativeAMFCapacity	((ASN_NGAP_ProtocolIE_ID_t)86)
#define ASN_NGAP_ProtocolIE_ID_id_RepetitionPeriod	((ASN_NGAP_ProtocolIE_ID_t)87)
#define ASN_NGAP_ProtocolIE_ID_id_ResetType	((ASN_NGAP_ProtocolIE_ID_t)88)
#define ASN_NGAP_ProtocolIE_ID_id_RoutingID	((ASN_NGAP_ProtocolIE_ID_t)89)
#define ASN_NGAP_ProtocolIE_ID_id_RRCEstablishmentCause	((ASN_NGAP_ProtocolIE_ID_t)90)
#define ASN_NGAP_ProtocolIE_ID_id_RRCInactiveTransitionReportRequest	((ASN_NGAP_ProtocolIE_ID_t)91)
#define ASN_NGAP_ProtocolIE_ID_id_RRCState	((ASN_NGAP_ProtocolIE_ID_t)92)
#define ASN_NGAP_ProtocolIE_ID_id_SecurityContext	((ASN_NGAP_ProtocolIE_ID_t)93)
#define ASN_NGAP_ProtocolIE_ID_id_SecurityKey	((ASN_NGAP_ProtocolIE_ID_t)94)
#define ASN_NGAP_ProtocolIE_ID_id_SerialNumber	((ASN_NGAP_ProtocolIE_ID_t)95)
#define ASN_NGAP_ProtocolIE_ID_id_ServedGUAMIList	((ASN_NGAP_ProtocolIE_ID_t)96)
#define ASN_NGAP_ProtocolIE_ID_id_SliceSupportList	((ASN_NGAP_ProtocolIE_ID_t)97)
#define ASN_NGAP_ProtocolIE_ID_id_SONConfigurationTransferDL	((ASN_NGAP_ProtocolIE_ID_t)98)
#define ASN_NGAP_ProtocolIE_ID_id_SONConfigurationTransferUL	((ASN_NGAP_ProtocolIE_ID_t)99)
#define ASN_NGAP_ProtocolIE_ID_id_SourceAMF_UE_NGAP_ID	((ASN_NGAP_ProtocolIE_ID_t)100)
#define ASN_NGAP_ProtocolIE_ID_id_SourceToTarget_TransparentContainer	((ASN_NGAP_ProtocolIE_ID_t)101)
#define ASN_NGAP_ProtocolIE_ID_id_SupportedTAList	((ASN_NGAP_ProtocolIE_ID_t)102)
#define ASN_NGAP_ProtocolIE_ID_id_TAIListForPaging	((ASN_NGAP_ProtocolIE_ID_t)103)
#define ASN_NGAP_ProtocolIE_ID_id_TAIListForRestart	((ASN_NGAP_ProtocolIE_ID_t)104)
#define ASN_NGAP_ProtocolIE_ID_id_TargetID	((ASN_NGAP_ProtocolIE_ID_t)105)
#define ASN_NGAP_ProtocolIE_ID_id_TargetToSource_TransparentContainer	((ASN_NGAP_ProtocolIE_ID_t)106)
#define ASN_NGAP_ProtocolIE_ID_id_TimeToWait	((ASN_NGAP_ProtocolIE_ID_t)107)
#define ASN_NGAP_ProtocolIE_ID_id_TraceActivation	((ASN_NGAP_ProtocolIE_ID_t)108)
#define ASN_NGAP_ProtocolIE_ID_id_TraceCollectionEntityIPAddress	((ASN_NGAP_ProtocolIE_ID_t)109)
#define ASN_NGAP_ProtocolIE_ID_id_UEAggregateMaximumBitRate	((ASN_NGAP_ProtocolIE_ID_t)110)
#define ASN_NGAP_ProtocolIE_ID_id_UE_associatedLogicalNG_connectionList	((ASN_NGAP_ProtocolIE_ID_t)111)
#define ASN_NGAP_ProtocolIE_ID_id_UEContextRequest	((ASN_NGAP_ProtocolIE_ID_t)112)
#define ASN_NGAP_ProtocolIE_ID_id_UE_NGAP_IDs	((ASN_NGAP_ProtocolIE_ID_t)114)
#define ASN_NGAP_ProtocolIE_ID_id_UEPagingIdentity	((ASN_NGAP_ProtocolIE_ID_t)115)
#define ASN_NGAP_ProtocolIE_ID_id_UEPresenceInAreaOfInterestList	((ASN_NGAP_ProtocolIE_ID_t)116)
#define ASN_NGAP_ProtocolIE_ID_id_UERadioCapability	((ASN_NGAP_ProtocolIE_ID_t)117)
#define ASN_NGAP_ProtocolIE_ID_id_UERadioCapabilityForPaging	((ASN_NGAP_ProtocolIE_ID_t)118)
#define ASN_NGAP_ProtocolIE_ID_id_UESecurityCapabilities	((ASN_NGAP_ProtocolIE_ID_t)119)
#define ASN_NGAP_ProtocolIE_ID_id_UnavailableGUAMIList	((ASN_NGAP_ProtocolIE_ID_t)120)
#define ASN_NGAP_ProtocolIE_ID_id_UserLocationInformation	((ASN_NGAP_ProtocolIE_ID_t)121)
#define ASN_NGAP_ProtocolIE_ID_id_WarningAreaList	((ASN_NGAP_ProtocolIE_ID_t)122)
#define ASN_NGAP_ProtocolIE_ID_id_WarningMessageContents	((ASN_NGAP_ProtocolIE_ID_t)123)
#define ASN_NGAP_ProtocolIE_ID_id_WarningSecurityInfo	((ASN_NGAP_ProtocolIE_ID_t)124)
#define ASN_NGAP_ProtocolIE_ID_id_WarningType	((ASN_NGAP_ProtocolIE_ID_t)125)
#define ASN_NGAP_ProtocolIE_ID_id_AdditionalUL_NGU_UP_TNLInformation	((ASN_NGAP_ProtocolIE_ID_t)126)
#define ASN_NGAP_ProtocolIE_ID_id_DataForwardingNotPossible	((ASN_NGAP_ProtocolIE_ID_t)127)
#define ASN_NGAP_ProtocolIE_ID_id_DL_NGU_UP_TNLInformation	((ASN_NGAP_ProtocolIE_ID_t)128)
#define ASN_NGAP_ProtocolIE_ID_id_NetworkInstance	((ASN_NGAP_ProtocolIE_ID_t)129)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionAggregateMaximumBitRate	((ASN_NGAP_ProtocolIE_ID_t)130)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceFailedToModifyListModCfm	((ASN_NGAP_ProtocolIE_ID_t)131)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceFailedToSetupListCxtFail	((ASN_NGAP_ProtocolIE_ID_t)132)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceListCxtRelReq	((ASN_NGAP_ProtocolIE_ID_t)133)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionType	((ASN_NGAP_ProtocolIE_ID_t)134)
#define ASN_NGAP_ProtocolIE_ID_id_QosFlowAddOrModifyRequestList	((ASN_NGAP_ProtocolIE_ID_t)135)
#define ASN_NGAP_ProtocolIE_ID_id_QosFlowSetupRequestList	((ASN_NGAP_ProtocolIE_ID_t)136)
#define ASN_NGAP_ProtocolIE_ID_id_QosFlowToReleaseList	((ASN_NGAP_ProtocolIE_ID_t)137)
#define ASN_NGAP_ProtocolIE_ID_id_SecurityIndication	((ASN_NGAP_ProtocolIE_ID_t)138)
#define ASN_NGAP_ProtocolIE_ID_id_UL_NGU_UP_TNLInformation	((ASN_NGAP_ProtocolIE_ID_t)139)
#define ASN_NGAP_ProtocolIE_ID_id_UL_NGU_UP_TNLModifyList	((ASN_NGAP_ProtocolIE_ID_t)140)
#define ASN_NGAP_ProtocolIE_ID_id_WarningAreaCoordinates	((ASN_NGAP_ProtocolIE_ID_t)141)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceSecondaryRATUsageList	((ASN_NGAP_ProtocolIE_ID_t)142)
#define ASN_NGAP_ProtocolIE_ID_id_HandoverFlag	((ASN_NGAP_ProtocolIE_ID_t)143)
#define ASN_NGAP_ProtocolIE_ID_id_SecondaryRATUsageInformation	((ASN_NGAP_ProtocolIE_ID_t)144)
#define ASN_NGAP_ProtocolIE_ID_id_PDUSessionResourceReleaseResponseTransfer	((ASN_NGAP_ProtocolIE_ID_t)145)
#define ASN_NGAP_ProtocolIE_ID_id_RedirectionVoiceFallback	((ASN_NGAP_ProtocolIE_ID_t)146)
#define ASN_NGAP_ProtocolIE_ID_id_UERetentionInformation	((ASN_NGAP_ProtocolIE_ID_t)147)
#define ASN_NGAP_ProtocolIE_ID_id_S_NSSAI	((ASN_NGAP_ProtocolIE_ID_t)148)
#define ASN_NGAP_ProtocolIE_ID_id_PSCellInformation	((ASN_NGAP_ProtocolIE_ID_t)149)
#define ASN_NGAP_ProtocolIE_ID_id_LastEUTRAN_PLMNIdentity	((ASN_NGAP_ProtocolIE_ID_t)150)
#define ASN_NGAP_ProtocolIE_ID_id_MaximumIntegrityProtectedDataRate_DL	((ASN_NGAP_ProtocolIE_ID_t)151)
#define ASN_NGAP_ProtocolIE_ID_id_AdditionalDLForwardingUPTNLInformation	((ASN_NGAP_ProtocolIE_ID_t)152)
#define ASN_NGAP_ProtocolIE_ID_id_AdditionalDLUPTNLInformationForHOList	((ASN_NGAP_ProtocolIE_ID_t)153)
#define ASN_NGAP_ProtocolIE_ID_id_AdditionalNGU_UP_TNLInformation	((ASN_NGAP_ProtocolIE_ID_t)154)
#define ASN_NGAP_ProtocolIE_ID_id_AdditionalDLQosFlowPerTNLInformation	((ASN_NGAP_ProtocolIE_ID_t)155)
#define ASN_NGAP_ProtocolIE_ID_id_SecurityResult	((ASN_NGAP_ProtocolIE_ID_t)156)
#define ASN_NGAP_ProtocolIE_ID_id_ENDC_SONConfigurationTransferDL	((ASN_NGAP_ProtocolIE_ID_t)157)
#define ASN_NGAP_ProtocolIE_ID_id_ENDC_SONConfigurationTransferUL	((ASN_NGAP_ProtocolIE_ID_t)158)
#define ASN_NGAP_ProtocolIE_ID_id_OldAssociatedQosFlowList_ULendmarkerexpected	((ASN_NGAP_ProtocolIE_ID_t)159)
#define ASN_NGAP_ProtocolIE_ID_id_CNTypeRestrictionsForEquivalent	((ASN_NGAP_ProtocolIE_ID_t)160)
#define ASN_NGAP_ProtocolIE_ID_id_CNTypeRestrictionsForServing	((ASN_NGAP_ProtocolIE_ID_t)161)
#define ASN_NGAP_ProtocolIE_ID_id_NewGUAMI	((ASN_NGAP_ProtocolIE_ID_t)162)
#define ASN_NGAP_ProtocolIE_ID_id_ULForwarding	((ASN_NGAP_ProtocolIE_ID_t)163)
#define ASN_NGAP_ProtocolIE_ID_id_ULForwardingUP_TNLInformation	((ASN_NGAP_ProtocolIE_ID_t)164)
#define ASN_NGAP_ProtocolIE_ID_id_CNAssistedRANTuning	((ASN_NGAP_ProtocolIE_ID_t)165)
#define ASN_NGAP_ProtocolIE_ID_id_CommonNetworkInstance	((ASN_NGAP_ProtocolIE_ID_t)166)
#define ASN_NGAP_ProtocolIE_ID_id_NGRAN_TNLAssociationToRemoveList	((ASN_NGAP_ProtocolIE_ID_t)167)
#define ASN_NGAP_ProtocolIE_ID_id_TNLAssociationTransportLayerAddressNGRAN	((ASN_NGAP_ProtocolIE_ID_t)168)
#define ASN_NGAP_ProtocolIE_ID_id_EndpointIPAddressAndPort	((ASN_NGAP_ProtocolIE_ID_t)169)
#define ASN_NGAP_ProtocolIE_ID_id_LocationReportingAdditionalInfo	((ASN_NGAP_ProtocolIE_ID_t)170)
#define ASN_NGAP_ProtocolIE_ID_id_SourceToTarget_AMFInformationReroute	((ASN_NGAP_ProtocolIE_ID_t)171)
#define ASN_NGAP_ProtocolIE_ID_id_AdditionalULForwardingUPTNLInformation	((ASN_NGAP_ProtocolIE_ID_t)172)
#define ASN_NGAP_ProtocolIE_ID_id_SCTP_TLAs	((ASN_NGAP_ProtocolIE_ID_t)173)
#define ASN_NGAP_ProtocolIE_ID_id_SelectedPLMNIdentity	((ASN_NGAP_ProtocolIE_ID_t)174)

#ifdef __cplusplus
}
#endif

#endif	/* _ASN_NGAP_ProtocolIE_ID_H_ */
#include <asn_internal.h>
