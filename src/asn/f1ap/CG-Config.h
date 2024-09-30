/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_CG_Config_H_
#define	_CG_Config_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CG-Config */
typedef OCTET_STRING_t	 CG_Config_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CG_Config;
asn_struct_free_f CG_Config_free;
asn_struct_print_f CG_Config_print;
asn_constr_check_f CG_Config_constraint;
ber_type_decoder_f CG_Config_decode_ber;
der_type_encoder_f CG_Config_encode_der;
xer_type_decoder_f CG_Config_decode_xer;
xer_type_encoder_f CG_Config_encode_xer;
oer_type_decoder_f CG_Config_decode_oer;
oer_type_encoder_f CG_Config_encode_oer;
per_type_decoder_f CG_Config_decode_uper;
per_type_encoder_f CG_Config_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _CG_Config_H_ */
#include <asn_internal.h>
