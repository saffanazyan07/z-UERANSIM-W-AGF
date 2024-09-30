/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_E_CID_ReportCharacteristics_H_
#define	_E_CID_ReportCharacteristics_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E_CID_ReportCharacteristics {
	E_CID_ReportCharacteristics_onDemand	= 0,
	E_CID_ReportCharacteristics_periodic	= 1
	/*
	 * Enumeration is extensible
	 */
} e_E_CID_ReportCharacteristics;

/* E-CID-ReportCharacteristics */
typedef long	 E_CID_ReportCharacteristics_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E_CID_ReportCharacteristics;
asn_struct_free_f E_CID_ReportCharacteristics_free;
asn_struct_print_f E_CID_ReportCharacteristics_print;
asn_constr_check_f E_CID_ReportCharacteristics_constraint;
ber_type_decoder_f E_CID_ReportCharacteristics_decode_ber;
der_type_encoder_f E_CID_ReportCharacteristics_encode_der;
xer_type_decoder_f E_CID_ReportCharacteristics_decode_xer;
xer_type_encoder_f E_CID_ReportCharacteristics_encode_xer;
oer_type_decoder_f E_CID_ReportCharacteristics_decode_oer;
oer_type_encoder_f E_CID_ReportCharacteristics_encode_oer;
per_type_decoder_f E_CID_ReportCharacteristics_decode_uper;
per_type_encoder_f E_CID_ReportCharacteristics_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _E_CID_ReportCharacteristics_H_ */
#include <asn_internal.h>
