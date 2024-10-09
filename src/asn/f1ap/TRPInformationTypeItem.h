/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_TRPInformationTypeItem_H_
#define	_TRPInformationTypeItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TRPInformationTypeItem {
	TRPInformationTypeItem_nrPCI	= 0,
	TRPInformationTypeItem_nG_RAN_CGI	= 1,
	TRPInformationTypeItem_arfcn	= 2,
	TRPInformationTypeItem_pRSConfig	= 3,
	TRPInformationTypeItem_sSBConfig	= 4,
	TRPInformationTypeItem_sFNInitTime	= 5,
	TRPInformationTypeItem_spatialDirectInfo	= 6,
	TRPInformationTypeItem_geoCoord	= 7,
	/*
	 * Enumeration is extensible
	 */
	TRPInformationTypeItem_trp_type	= 8
} e_TRPInformationTypeItem;

/* TRPInformationTypeItem */
typedef long	 TRPInformationTypeItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TRPInformationTypeItem;
asn_struct_free_f TRPInformationTypeItem_free;
asn_struct_print_f TRPInformationTypeItem_print;
asn_constr_check_f TRPInformationTypeItem_constraint;
ber_type_decoder_f TRPInformationTypeItem_decode_ber;
der_type_encoder_f TRPInformationTypeItem_encode_der;
xer_type_decoder_f TRPInformationTypeItem_decode_xer;
xer_type_encoder_f TRPInformationTypeItem_encode_xer;
per_type_decoder_f TRPInformationTypeItem_decode_uper;
per_type_encoder_f TRPInformationTypeItem_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _TRPInformationTypeItem_H_ */
#include <asn_internal.h>
