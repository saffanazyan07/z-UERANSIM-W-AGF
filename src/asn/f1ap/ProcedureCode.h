/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-CommonDataTypes"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_ProcedureCode_H_
#define	_ProcedureCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ProcedureCode */
typedef long	 ProcedureCode_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ProcedureCode_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ProcedureCode;
asn_struct_free_f ProcedureCode_free;
asn_struct_print_f ProcedureCode_print;
asn_constr_check_f ProcedureCode_constraint;
ber_type_decoder_f ProcedureCode_decode_ber;
der_type_encoder_f ProcedureCode_encode_der;
xer_type_decoder_f ProcedureCode_decode_xer;
xer_type_encoder_f ProcedureCode_encode_xer;
per_type_decoder_f ProcedureCode_decode_uper;
per_type_encoder_f ProcedureCode_encode_uper;
#define ASN_F1AP_ProcedureCode_id_Reset	((ASN_F1AP_ProcedureCode_t)0)
#define ASN_F1AP_ProcedureCode_id_F1Setup	((ASN_F1AP_ProcedureCode_t)1)
#define ASN_F1AP_ProcedureCode_id_ErrorIndication	((ASN_F1AP_ProcedureCode_t)2)
#define ASN_F1AP_ProcedureCode_id_gNBDUConfigurationUpdate	((ASN_F1AP_ProcedureCode_t)3)
#define ASN_F1AP_ProcedureCode_id_gNBCUConfigurationUpdate	((ASN_F1AP_ProcedureCode_t)4)
#define ASN_F1AP_ProcedureCode_id_UEContextSetup	((ASN_F1AP_ProcedureCode_t)5)
#define ASN_F1AP_ProcedureCode_id_UEContextRelease	((ASN_F1AP_ProcedureCode_t)6)
#define ASN_F1AP_ProcedureCode_id_UEContextModification	((ASN_F1AP_ProcedureCode_t)7)
#define ASN_F1AP_ProcedureCode_id_UEContextModificationRequired	((ASN_F1AP_ProcedureCode_t)8)
#define ASN_F1AP_ProcedureCode_id_UEMobilityCommand	((ASN_F1AP_ProcedureCode_t)9)
#define ASN_F1AP_ProcedureCode_id_UEContextReleaseRequest	((ASN_F1AP_ProcedureCode_t)10)
#define ASN_F1AP_ProcedureCode_id_InitialULRRCMessageTransfer	((ASN_F1AP_ProcedureCode_t)11)
#define ASN_F1AP_ProcedureCode_id_DLRRCMessageTransfer	((ASN_F1AP_ProcedureCode_t)12)
#define ASN_F1AP_ProcedureCode_id_ULRRCMessageTransfer	((ASN_F1AP_ProcedureCode_t)13)
#define ASN_F1AP_ProcedureCode_id_privateMessage	((ASN_F1AP_ProcedureCode_t)14)
#define ASN_F1AP_ProcedureCode_id_UEInactivityNotification	((ASN_F1AP_ProcedureCode_t)15)
#define ASN_F1AP_ProcedureCode_id_GNBDUResourceCoordination	((ASN_F1AP_ProcedureCode_t)16)
#define ASN_F1AP_ProcedureCode_id_SystemInformationDeliveryCommand	((ASN_F1AP_ProcedureCode_t)17)
#define ASN_F1AP_ProcedureCode_id_Paging	((ASN_F1AP_ProcedureCode_t)18)
#define ASN_F1AP_ProcedureCode_id_Notify	((ASN_F1AP_ProcedureCode_t)19)
#define ASN_F1AP_ProcedureCode_id_WriteReplaceWarning	((ASN_F1AP_ProcedureCode_t)20)
#define ASN_F1AP_ProcedureCode_id_PWSCancel	((ASN_F1AP_ProcedureCode_t)21)
#define ASN_F1AP_ProcedureCode_id_PWSRestartIndication	((ASN_F1AP_ProcedureCode_t)22)
#define ASN_F1AP_ProcedureCode_id_PWSFailureIndication	((ASN_F1AP_ProcedureCode_t)23)
#define ASN_F1AP_ProcedureCode_id_GNBDUStatusIndication	((ASN_F1AP_ProcedureCode_t)24)
#define ASN_F1AP_ProcedureCode_id_RRCDeliveryReport	((ASN_F1AP_ProcedureCode_t)25)
#define ASN_F1AP_ProcedureCode_id_F1Removal	((ASN_F1AP_ProcedureCode_t)26)
#define ASN_F1AP_ProcedureCode_id_NetworkAccessRateReduction	((ASN_F1AP_ProcedureCode_t)27)
#define ASN_F1AP_ProcedureCode_id_TraceStart	((ASN_F1AP_ProcedureCode_t)28)
#define ASN_F1AP_ProcedureCode_id_DeactivateTrace	((ASN_F1AP_ProcedureCode_t)29)
#define ASN_F1AP_ProcedureCode_id_DUCURadioInformationTransfer	((ASN_F1AP_ProcedureCode_t)30)
#define ASN_F1AP_ProcedureCode_id_CUDURadioInformationTransfer	((ASN_F1AP_ProcedureCode_t)31)
#define ASN_F1AP_ProcedureCode_id_BAPMappingConfiguration	((ASN_F1AP_ProcedureCode_t)32)
#define ASN_F1AP_ProcedureCode_id_GNBDUResourceConfiguration	((ASN_F1AP_ProcedureCode_t)33)
#define ASN_F1AP_ProcedureCode_id_IABTNLAddressAllocation	((ASN_F1AP_ProcedureCode_t)34)
#define ASN_F1AP_ProcedureCode_id_IABUPConfigurationUpdate	((ASN_F1AP_ProcedureCode_t)35)
#define ASN_F1AP_ProcedureCode_id_resourceStatusReportingInitiation	((ASN_F1AP_ProcedureCode_t)36)
#define ASN_F1AP_ProcedureCode_id_resourceStatusReporting	((ASN_F1AP_ProcedureCode_t)37)
#define ASN_F1AP_ProcedureCode_id_accessAndMobilityIndication	((ASN_F1AP_ProcedureCode_t)38)
#define ASN_F1AP_ProcedureCode_id_accessSuccess	((ASN_F1AP_ProcedureCode_t)39)
#define ASN_F1AP_ProcedureCode_id_cellTrafficTrace	((ASN_F1AP_ProcedureCode_t)40)
#define ASN_F1AP_ProcedureCode_id_PositioningMeasurementExchange	((ASN_F1AP_ProcedureCode_t)41)
#define ASN_F1AP_ProcedureCode_id_PositioningAssistanceInformationControl	((ASN_F1AP_ProcedureCode_t)42)
#define ASN_F1AP_ProcedureCode_id_PositioningAssistanceInformationFeedback	((ASN_F1AP_ProcedureCode_t)43)
#define ASN_F1AP_ProcedureCode_id_PositioningMeasurementReport	((ASN_F1AP_ProcedureCode_t)44)
#define ASN_F1AP_ProcedureCode_id_PositioningMeasurementAbort	((ASN_F1AP_ProcedureCode_t)45)
#define ASN_F1AP_ProcedureCode_id_PositioningMeasurementFailureIndication	((ASN_F1AP_ProcedureCode_t)46)
#define ASN_F1AP_ProcedureCode_id_PositioningMeasurementUpdate	((ASN_F1AP_ProcedureCode_t)47)
#define ASN_F1AP_ProcedureCode_id_TRPInformationExchange	((ASN_F1AP_ProcedureCode_t)48)
#define ASN_F1AP_ProcedureCode_id_PositioningInformationExchange	((ASN_F1AP_ProcedureCode_t)49)
#define ASN_F1AP_ProcedureCode_id_PositioningActivation	((ASN_F1AP_ProcedureCode_t)50)
#define ASN_F1AP_ProcedureCode_id_PositioningDeactivation	((ASN_F1AP_ProcedureCode_t)51)
#define ASN_F1AP_ProcedureCode_id_E_CIDMeasurementInitiation	((ASN_F1AP_ProcedureCode_t)52)
#define ASN_F1AP_ProcedureCode_id_E_CIDMeasurementFailureIndication	((ASN_F1AP_ProcedureCode_t)53)
#define ASN_F1AP_ProcedureCode_id_E_CIDMeasurementReport	((ASN_F1AP_ProcedureCode_t)54)
#define ASN_F1AP_ProcedureCode_id_E_CIDMeasurementTermination	((ASN_F1AP_ProcedureCode_t)55)
#define ASN_F1AP_ProcedureCode_id_PositioningInformationUpdate	((ASN_F1AP_ProcedureCode_t)56)
#define ASN_F1AP_ProcedureCode_id_ReferenceTimeInformationReport	((ASN_F1AP_ProcedureCode_t)57)
#define ASN_F1AP_ProcedureCode_id_ReferenceTimeInformationReportingControl	((ASN_F1AP_ProcedureCode_t)58)

#ifdef __cplusplus
}
#endif

#endif	/* _ProcedureCode_H_ */
#include <asn_internal.h>
