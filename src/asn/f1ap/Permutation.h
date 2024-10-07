/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_Permutation_H_
#define	_Permutation_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Permutation {
	Permutation_dfu	= 0,
	Permutation_ufd	= 1
	/*
	 * Enumeration is extensible
	 */
} e_Permutation;

/* Permutation */
typedef long	 Permutation_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Permutation_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Permutation;
extern const asn_INTEGER_specifics_t asn_SPC_Permutation_specs_1;
asn_struct_free_f Permutation_free;
asn_struct_print_f Permutation_print;
asn_constr_check_f Permutation_constraint;
ber_type_decoder_f Permutation_decode_ber;
der_type_encoder_f Permutation_encode_der;
xer_type_decoder_f Permutation_decode_xer;
xer_type_encoder_f Permutation_encode_xer;
per_type_decoder_f Permutation_decode_uper;
per_type_encoder_f Permutation_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _Permutation_H_ */
#include <asn_internal.h>
