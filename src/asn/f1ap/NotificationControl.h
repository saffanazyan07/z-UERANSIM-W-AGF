/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_NotificationControl_H_
#define	_NotificationControl_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NotificationControl {
	NotificationControl_active	= 0,
	NotificationControl_not_active	= 1
	/*
	 * Enumeration is extensible
	 */
} e_NotificationControl;

/* NotificationControl */
typedef long	 NotificationControl_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NotificationControl_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NotificationControl;
extern const asn_INTEGER_specifics_t asn_SPC_NotificationControl_specs_1;
asn_struct_free_f NotificationControl_free;
asn_struct_print_f NotificationControl_print;
asn_constr_check_f NotificationControl_constraint;
ber_type_decoder_f NotificationControl_decode_ber;
der_type_encoder_f NotificationControl_encode_der;
xer_type_decoder_f NotificationControl_decode_xer;
xer_type_encoder_f NotificationControl_encode_xer;
per_type_decoder_f NotificationControl_decode_uper;
per_type_encoder_f NotificationControl_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _NotificationControl_H_ */
#include <asn_internal.h>
