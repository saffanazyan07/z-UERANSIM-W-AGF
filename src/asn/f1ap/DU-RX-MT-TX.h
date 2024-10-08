/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_DU_RX_MT_TX_H_
#define	_DU_RX_MT_TX_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DU_RX_MT_TX {
	DU_RX_MT_TX_supported	= 0,
	DU_RX_MT_TX_not_supported	= 1
} e_DU_RX_MT_TX;

/* DU-RX-MT-TX */
typedef long	 DU_RX_MT_TX_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_DU_RX_MT_TX_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_DU_RX_MT_TX;
extern const asn_INTEGER_specifics_t asn_SPC_DU_RX_MT_TX_specs_1;
asn_struct_free_f DU_RX_MT_TX_free;
asn_struct_print_f DU_RX_MT_TX_print;
asn_constr_check_f DU_RX_MT_TX_constraint;
ber_type_decoder_f DU_RX_MT_TX_decode_ber;
der_type_encoder_f DU_RX_MT_TX_encode_der;
xer_type_decoder_f DU_RX_MT_TX_decode_xer;
xer_type_encoder_f DU_RX_MT_TX_encode_xer;
per_type_decoder_f DU_RX_MT_TX_decode_uper;
per_type_encoder_f DU_RX_MT_TX_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _DU_RX_MT_TX_H_ */
#include <asn_internal.h>
