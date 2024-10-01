/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_PedestrianUE_H_
#define	_PedestrianUE_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PedestrianUE {
	PedestrianUE_authorized	= 0,
	PedestrianUE_not_authorized	= 1
	/*
	 * Enumeration is extensible
	 */
} e_PedestrianUE;

/* PedestrianUE */
typedef long	 PedestrianUE_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PedestrianUE_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PedestrianUE;
extern const asn_INTEGER_specifics_t asn_SPC_PedestrianUE_specs_1;
asn_struct_free_f PedestrianUE_free;
asn_struct_print_f PedestrianUE_print;
asn_constr_check_f PedestrianUE_constraint;
ber_type_decoder_f PedestrianUE_decode_ber;
der_type_encoder_f PedestrianUE_encode_der;
xer_type_decoder_f PedestrianUE_decode_xer;
xer_type_encoder_f PedestrianUE_encode_xer;
oer_type_decoder_f PedestrianUE_decode_oer;
oer_type_encoder_f PedestrianUE_encode_oer;
per_type_decoder_f PedestrianUE_decode_uper;
per_type_encoder_f PedestrianUE_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _PedestrianUE_H_ */
#include <asn_internal.h>
