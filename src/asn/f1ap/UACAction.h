/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_UACAction_H_
#define	_UACAction_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UACAction {
	UACAction_reject_non_emergency_mo_dt	= 0,
	UACAction_reject_rrc_cr_signalling	= 1,
	UACAction_permit_emergency_sessions_and_mobile_terminated_services_only	= 2,
	UACAction_permit_high_priority_sessions_and_mobile_terminated_services_only	= 3
	/*
	 * Enumeration is extensible
	 */
} e_UACAction;

/* UACAction */
typedef long	 UACAction_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_UACAction_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_UACAction;
extern const asn_INTEGER_specifics_t asn_SPC_UACAction_specs_1;
asn_struct_free_f UACAction_free;
asn_struct_print_f UACAction_print;
asn_constr_check_f UACAction_constraint;
ber_type_decoder_f UACAction_decode_ber;
der_type_encoder_f UACAction_encode_der;
xer_type_decoder_f UACAction_decode_xer;
xer_type_encoder_f UACAction_encode_xer;
per_type_decoder_f UACAction_decode_uper;
per_type_encoder_f UACAction_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _UACAction_H_ */
#include <asn_internal.h>
