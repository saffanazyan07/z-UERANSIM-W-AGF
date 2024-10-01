/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_NeedforGap_H_
#define	_NeedforGap_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NeedforGap {
	NeedforGap_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_NeedforGap;

/* NeedforGap */
typedef long	 NeedforGap_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NeedforGap;
asn_struct_free_f NeedforGap_free;
asn_struct_print_f NeedforGap_print;
asn_constr_check_f NeedforGap_constraint;
ber_type_decoder_f NeedforGap_decode_ber;
der_type_encoder_f NeedforGap_encode_der;
xer_type_decoder_f NeedforGap_decode_xer;
xer_type_encoder_f NeedforGap_encode_xer;
oer_type_decoder_f NeedforGap_decode_oer;
oer_type_encoder_f NeedforGap_encode_oer;
per_type_decoder_f NeedforGap_decode_uper;
per_type_encoder_f NeedforGap_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _NeedforGap_H_ */
#include <asn_internal.h>
