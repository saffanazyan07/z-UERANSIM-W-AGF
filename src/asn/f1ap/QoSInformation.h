/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_QoSInformation_H_
#define	_QoSInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum QoSInformation_PR {
	QoSInformation_PR_NOTHING,	/* No components present */
	QoSInformation_PR_eUTRANQoS,
	QoSInformation_PR_choice_extension
} QoSInformation_PR;

/* Forward declarations */
struct EUTRANQoS;
struct ProtocolIE_SingleContainer;

/* QoSInformation */
typedef struct QoSInformation {
	QoSInformation_PR present;
	union QoSInformation_u {
		struct EUTRANQoS	*eUTRANQoS;
		struct ProtocolIE_SingleContainer	*choice_extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} QoSInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_QoSInformation;
extern asn_CHOICE_specifics_t asn_SPC_QoSInformation_specs_1;
extern asn_TYPE_member_t asn_MBR_QoSInformation_1[2];
extern asn_per_constraints_t asn_PER_type_QoSInformation_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _QoSInformation_H_ */
#include <asn_internal.h>
