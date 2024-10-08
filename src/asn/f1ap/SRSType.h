/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-PDU-Contents"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_SRSType_H_
#define	_SRSType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SRSType_PR {
	SRSType_PR_NOTHING,	/* No components present */
	SRSType_PR_semipersistentSRS,
	SRSType_PR_aperiodicSRS,
	SRSType_PR_choice_extension
} SRSType_PR;

/* Forward declarations */
struct SemipersistentSRS;
struct AperiodicSRS;
struct ProtocolIE_SingleContainer;

/* SRSType */
typedef struct SRSType {
	SRSType_PR present;
	union SRSType_u {
		struct SemipersistentSRS	*semipersistentSRS;
		struct AperiodicSRS	*aperiodicSRS;
		struct ProtocolIE_SingleContainer	*choice_extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SRSType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SRSType;

#ifdef __cplusplus
}
#endif

#endif	/* _SRSType_H_ */
#include <asn_internal.h>
