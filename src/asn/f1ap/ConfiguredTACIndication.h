/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_ConfiguredTACIndication_H_
#define	_ConfiguredTACIndication_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ConfiguredTACIndication {
	ConfiguredTACIndication_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_ConfiguredTACIndication;

/* ConfiguredTACIndication */
typedef long	 ConfiguredTACIndication_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ConfiguredTACIndication;
asn_struct_free_f ConfiguredTACIndication_free;
asn_struct_print_f ConfiguredTACIndication_print;
asn_constr_check_f ConfiguredTACIndication_constraint;
ber_type_decoder_f ConfiguredTACIndication_decode_ber;
der_type_encoder_f ConfiguredTACIndication_encode_der;
xer_type_decoder_f ConfiguredTACIndication_decode_xer;
xer_type_encoder_f ConfiguredTACIndication_encode_xer;
per_type_decoder_f ConfiguredTACIndication_decode_uper;
per_type_encoder_f ConfiguredTACIndication_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _ConfiguredTACIndication_H_ */
#include <asn_internal.h>
