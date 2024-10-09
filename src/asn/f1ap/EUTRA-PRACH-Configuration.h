/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_EUTRA_PRACH_Configuration_H_
#define	_EUTRA_PRACH_Configuration_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <BOOLEAN.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* EUTRA-PRACH-Configuration */
typedef struct EUTRA_PRACH_Configuration {
	long	 rootSequenceIndex;
	long	 zeroCorrelationIndex;
	BOOLEAN_t	 highSpeedFlag;
	long	 prach_FreqOffset;
	long	*prach_ConfigIndex	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} EUTRA_PRACH_Configuration_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EUTRA_PRACH_Configuration;
extern asn_SEQUENCE_specifics_t asn_SPC_EUTRA_PRACH_Configuration_specs_1;
extern asn_TYPE_member_t asn_MBR_EUTRA_PRACH_Configuration_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _EUTRA_PRACH_Configuration_H_ */
#include <asn_internal.h>
