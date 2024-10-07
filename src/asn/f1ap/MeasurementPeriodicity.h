/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_MeasurementPeriodicity_H_
#define	_MeasurementPeriodicity_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MeasurementPeriodicity {
	MeasurementPeriodicity_ms120	= 0,
	MeasurementPeriodicity_ms240	= 1,
	MeasurementPeriodicity_ms480	= 2,
	MeasurementPeriodicity_ms640	= 3,
	MeasurementPeriodicity_ms1024	= 4,
	MeasurementPeriodicity_ms2048	= 5,
	MeasurementPeriodicity_ms5120	= 6,
	MeasurementPeriodicity_ms10240	= 7,
	MeasurementPeriodicity_min1	= 8,
	MeasurementPeriodicity_min6	= 9,
	MeasurementPeriodicity_min12	= 10,
	MeasurementPeriodicity_min30	= 11,
	/*
	 * Enumeration is extensible
	 */
	MeasurementPeriodicity_ms20480	= 12,
	MeasurementPeriodicity_ms40960	= 13
} e_MeasurementPeriodicity;

/* MeasurementPeriodicity */
typedef long	 MeasurementPeriodicity_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasurementPeriodicity;
asn_struct_free_f MeasurementPeriodicity_free;
asn_struct_print_f MeasurementPeriodicity_print;
asn_constr_check_f MeasurementPeriodicity_constraint;
ber_type_decoder_f MeasurementPeriodicity_decode_ber;
der_type_encoder_f MeasurementPeriodicity_encode_der;
xer_type_decoder_f MeasurementPeriodicity_decode_xer;
xer_type_encoder_f MeasurementPeriodicity_encode_xer;
per_type_decoder_f MeasurementPeriodicity_decode_uper;
per_type_encoder_f MeasurementPeriodicity_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _MeasurementPeriodicity_H_ */
#include <asn_internal.h>
