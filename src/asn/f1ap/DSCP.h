/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_DSCP_H_
#define	_DSCP_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DSCP */
typedef BIT_STRING_t	 DSCP_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_DSCP_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_DSCP;
asn_struct_free_f DSCP_free;
asn_struct_print_f DSCP_print;
asn_constr_check_f DSCP_constraint;
ber_type_decoder_f DSCP_decode_ber;
der_type_encoder_f DSCP_encode_der;
xer_type_decoder_f DSCP_decode_xer;
xer_type_encoder_f DSCP_encode_xer;
per_type_decoder_f DSCP_decode_uper;
per_type_encoder_f DSCP_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _DSCP_H_ */
#include <asn_internal.h>
