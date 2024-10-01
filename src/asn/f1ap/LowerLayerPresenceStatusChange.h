/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_LowerLayerPresenceStatusChange_H_
#define	_LowerLayerPresenceStatusChange_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LowerLayerPresenceStatusChange {
	LowerLayerPresenceStatusChange_suspend_lower_layers	= 0,
	LowerLayerPresenceStatusChange_resume_lower_layers	= 1
	/*
	 * Enumeration is extensible
	 */
} e_LowerLayerPresenceStatusChange;

/* LowerLayerPresenceStatusChange */
typedef long	 LowerLayerPresenceStatusChange_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LowerLayerPresenceStatusChange;
asn_struct_free_f LowerLayerPresenceStatusChange_free;
asn_struct_print_f LowerLayerPresenceStatusChange_print;
asn_constr_check_f LowerLayerPresenceStatusChange_constraint;
ber_type_decoder_f LowerLayerPresenceStatusChange_decode_ber;
der_type_encoder_f LowerLayerPresenceStatusChange_encode_der;
xer_type_decoder_f LowerLayerPresenceStatusChange_decode_xer;
xer_type_encoder_f LowerLayerPresenceStatusChange_encode_xer;
oer_type_decoder_f LowerLayerPresenceStatusChange_decode_oer;
oer_type_encoder_f LowerLayerPresenceStatusChange_encode_oer;
per_type_decoder_f LowerLayerPresenceStatusChange_decode_uper;
per_type_encoder_f LowerLayerPresenceStatusChange_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _LowerLayerPresenceStatusChange_H_ */
#include <asn_internal.h>
