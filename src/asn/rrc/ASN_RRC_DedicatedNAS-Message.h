/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NR-RRC-Definitions"
 * 	found in "asn/nr-rrc-15.6.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D rrc`
 */

#ifndef	_ASN_RRC_DedicatedNAS_Message_H_
#define	_ASN_RRC_DedicatedNAS_Message_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ASN_RRC_DedicatedNAS-Message */
typedef OCTET_STRING_t	 ASN_RRC_DedicatedNAS_Message_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ASN_RRC_DedicatedNAS_Message;
asn_struct_free_f ASN_RRC_DedicatedNAS_Message_free;
asn_struct_print_f ASN_RRC_DedicatedNAS_Message_print;
asn_constr_check_f ASN_RRC_DedicatedNAS_Message_constraint;
ber_type_decoder_f ASN_RRC_DedicatedNAS_Message_decode_ber;
der_type_encoder_f ASN_RRC_DedicatedNAS_Message_encode_der;
xer_type_decoder_f ASN_RRC_DedicatedNAS_Message_decode_xer;
xer_type_encoder_f ASN_RRC_DedicatedNAS_Message_encode_xer;
per_type_decoder_f ASN_RRC_DedicatedNAS_Message_decode_uper;
per_type_encoder_f ASN_RRC_DedicatedNAS_Message_encode_uper;
per_type_decoder_f ASN_RRC_DedicatedNAS_Message_decode_aper;
per_type_encoder_f ASN_RRC_DedicatedNAS_Message_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ASN_RRC_DedicatedNAS_Message_H_ */
#include <asn_internal.h>
