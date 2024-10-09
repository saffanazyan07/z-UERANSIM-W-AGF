/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_DCBasedDuplicationConfigured_H_
#define	_DCBasedDuplicationConfigured_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DCBasedDuplicationConfigured {
	DCBasedDuplicationConfigured_true	= 0,
	/*
	 * Enumeration is extensible
	 */
	DCBasedDuplicationConfigured_false	= 1
} e_DCBasedDuplicationConfigured;

/* DCBasedDuplicationConfigured */
typedef long	 DCBasedDuplicationConfigured_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DCBasedDuplicationConfigured;
asn_struct_free_f DCBasedDuplicationConfigured_free;
asn_struct_print_f DCBasedDuplicationConfigured_print;
asn_constr_check_f DCBasedDuplicationConfigured_constraint;
ber_type_decoder_f DCBasedDuplicationConfigured_decode_ber;
der_type_encoder_f DCBasedDuplicationConfigured_encode_der;
xer_type_decoder_f DCBasedDuplicationConfigured_decode_xer;
xer_type_encoder_f DCBasedDuplicationConfigured_encode_xer;
per_type_decoder_f DCBasedDuplicationConfigured_decode_uper;
per_type_encoder_f DCBasedDuplicationConfigured_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _DCBasedDuplicationConfigured_H_ */
#include <asn_internal.h>
