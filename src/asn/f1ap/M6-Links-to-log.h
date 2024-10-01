/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_M6_Links_to_log_H_
#define	_M6_Links_to_log_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum M6_Links_to_log {
	M6_Links_to_log_uplink	= 0,
	M6_Links_to_log_downlink	= 1,
	M6_Links_to_log_both_uplink_and_downlink	= 2
	/*
	 * Enumeration is extensible
	 */
} e_M6_Links_to_log;

/* M6-Links-to-log */
typedef long	 M6_Links_to_log_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_M6_Links_to_log_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_M6_Links_to_log;
extern const asn_INTEGER_specifics_t asn_SPC_M6_Links_to_log_specs_1;
asn_struct_free_f M6_Links_to_log_free;
asn_struct_print_f M6_Links_to_log_print;
asn_constr_check_f M6_Links_to_log_constraint;
ber_type_decoder_f M6_Links_to_log_decode_ber;
der_type_encoder_f M6_Links_to_log_encode_der;
xer_type_decoder_f M6_Links_to_log_decode_xer;
xer_type_encoder_f M6_Links_to_log_encode_xer;
oer_type_decoder_f M6_Links_to_log_decode_oer;
oer_type_encoder_f M6_Links_to_log_encode_oer;
per_type_decoder_f M6_Links_to_log_decode_uper;
per_type_encoder_f M6_Links_to_log_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _M6_Links_to_log_H_ */
#include <asn_internal.h>
