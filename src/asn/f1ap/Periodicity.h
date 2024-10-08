/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_Periodicity_H_
#define	_Periodicity_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Periodicity */
typedef long	 Periodicity_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Periodicity_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Periodicity;
asn_struct_free_f Periodicity_free;
asn_struct_print_f Periodicity_print;
asn_constr_check_f Periodicity_constraint;
ber_type_decoder_f Periodicity_decode_ber;
der_type_encoder_f Periodicity_encode_der;
xer_type_decoder_f Periodicity_decode_xer;
xer_type_encoder_f Periodicity_encode_xer;
per_type_decoder_f Periodicity_decode_uper;
per_type_encoder_f Periodicity_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _Periodicity_H_ */
#include <asn_internal.h>
