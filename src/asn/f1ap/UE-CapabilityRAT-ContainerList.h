/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_UE_CapabilityRAT_ContainerList_H_
#define	_UE_CapabilityRAT_ContainerList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UE-CapabilityRAT-ContainerList */
typedef OCTET_STRING_t	 UE_CapabilityRAT_ContainerList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UE_CapabilityRAT_ContainerList;
asn_struct_free_f UE_CapabilityRAT_ContainerList_free;
asn_struct_print_f UE_CapabilityRAT_ContainerList_print;
asn_constr_check_f UE_CapabilityRAT_ContainerList_constraint;
ber_type_decoder_f UE_CapabilityRAT_ContainerList_decode_ber;
der_type_encoder_f UE_CapabilityRAT_ContainerList_encode_der;
xer_type_decoder_f UE_CapabilityRAT_ContainerList_decode_xer;
xer_type_encoder_f UE_CapabilityRAT_ContainerList_encode_xer;
per_type_decoder_f UE_CapabilityRAT_ContainerList_decode_uper;
per_type_encoder_f UE_CapabilityRAT_ContainerList_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _UE_CapabilityRAT_ContainerList_H_ */
#include <asn_internal.h>
