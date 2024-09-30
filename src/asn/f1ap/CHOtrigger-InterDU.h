/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_CHOtrigger_InterDU_H_
#define	_CHOtrigger_InterDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CHOtrigger_InterDU {
	CHOtrigger_InterDU_cho_initiation	= 0,
	CHOtrigger_InterDU_cho_replace	= 1
	/*
	 * Enumeration is extensible
	 */
} e_CHOtrigger_InterDU;

/* CHOtrigger-InterDU */
typedef long	 CHOtrigger_InterDU_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_CHOtrigger_InterDU_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_CHOtrigger_InterDU;
extern const asn_INTEGER_specifics_t asn_SPC_CHOtrigger_InterDU_specs_1;
asn_struct_free_f CHOtrigger_InterDU_free;
asn_struct_print_f CHOtrigger_InterDU_print;
asn_constr_check_f CHOtrigger_InterDU_constraint;
ber_type_decoder_f CHOtrigger_InterDU_decode_ber;
der_type_encoder_f CHOtrigger_InterDU_encode_der;
xer_type_decoder_f CHOtrigger_InterDU_decode_xer;
xer_type_encoder_f CHOtrigger_InterDU_encode_xer;
oer_type_decoder_f CHOtrigger_InterDU_decode_oer;
oer_type_encoder_f CHOtrigger_InterDU_encode_oer;
per_type_decoder_f CHOtrigger_InterDU_decode_uper;
per_type_encoder_f CHOtrigger_InterDU_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _CHOtrigger_InterDU_H_ */
#include <asn_internal.h>
