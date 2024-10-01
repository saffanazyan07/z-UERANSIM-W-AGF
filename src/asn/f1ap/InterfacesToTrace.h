/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_InterfacesToTrace_H_
#define	_InterfacesToTrace_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* InterfacesToTrace */
typedef BIT_STRING_t	 InterfacesToTrace_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_InterfacesToTrace_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_InterfacesToTrace;
asn_struct_free_f InterfacesToTrace_free;
asn_struct_print_f InterfacesToTrace_print;
asn_constr_check_f InterfacesToTrace_constraint;
ber_type_decoder_f InterfacesToTrace_decode_ber;
der_type_encoder_f InterfacesToTrace_encode_der;
xer_type_decoder_f InterfacesToTrace_decode_xer;
xer_type_encoder_f InterfacesToTrace_encode_xer;
oer_type_decoder_f InterfacesToTrace_decode_oer;
oer_type_encoder_f InterfacesToTrace_encode_oer;
per_type_decoder_f InterfacesToTrace_decode_uper;
per_type_encoder_f InterfacesToTrace_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _InterfacesToTrace_H_ */
#include <asn_internal.h>
