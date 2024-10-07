/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_CHOtrigger_IntraDU_H_
#define	_CHOtrigger_IntraDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CHOtrigger_IntraDU {
	CHOtrigger_IntraDU_cho_initiation	= 0,
	CHOtrigger_IntraDU_cho_replace	= 1,
	CHOtrigger_IntraDU_cho_cancel	= 2
	/*
	 * Enumeration is extensible
	 */
} e_CHOtrigger_IntraDU;

/* CHOtrigger-IntraDU */
typedef long	 CHOtrigger_IntraDU_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_CHOtrigger_IntraDU_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_CHOtrigger_IntraDU;
extern const asn_INTEGER_specifics_t asn_SPC_CHOtrigger_IntraDU_specs_1;
asn_struct_free_f CHOtrigger_IntraDU_free;
asn_struct_print_f CHOtrigger_IntraDU_print;
asn_constr_check_f CHOtrigger_IntraDU_constraint;
ber_type_decoder_f CHOtrigger_IntraDU_decode_ber;
der_type_encoder_f CHOtrigger_IntraDU_encode_der;
xer_type_decoder_f CHOtrigger_IntraDU_decode_xer;
xer_type_encoder_f CHOtrigger_IntraDU_encode_xer;
per_type_decoder_f CHOtrigger_IntraDU_decode_uper;
per_type_encoder_f CHOtrigger_IntraDU_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _CHOtrigger_IntraDU_H_ */
#include <asn_internal.h>
