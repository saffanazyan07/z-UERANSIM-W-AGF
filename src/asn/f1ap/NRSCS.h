/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_NRSCS_H_
#define	_NRSCS_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRSCS {
	NRSCS_scs15	= 0,
	NRSCS_scs30	= 1,
	NRSCS_scs60	= 2,
	NRSCS_scs120	= 3
	/*
	 * Enumeration is extensible
	 */
} e_NRSCS;

/* NRSCS */
typedef long	 NRSCS_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NRSCS_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NRSCS;
extern const asn_INTEGER_specifics_t asn_SPC_NRSCS_specs_1;
asn_struct_free_f NRSCS_free;
asn_struct_print_f NRSCS_print;
asn_constr_check_f NRSCS_constraint;
ber_type_decoder_f NRSCS_decode_ber;
der_type_encoder_f NRSCS_encode_der;
xer_type_decoder_f NRSCS_decode_xer;
xer_type_encoder_f NRSCS_encode_xer;
per_type_decoder_f NRSCS_decode_uper;
per_type_encoder_f NRSCS_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _NRSCS_H_ */
#include <asn_internal.h>
