/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_FDD_Info_H_
#define	_FDD_Info_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRFreqInfo.h"
#include "Transmission-Bandwidth.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* FDD-Info */
typedef struct FDD_Info {
	NRFreqInfo_t	 uL_NRFreqInfo;
	NRFreqInfo_t	 dL_NRFreqInfo;
	Transmission_Bandwidth_t	 uL_Transmission_Bandwidth;
	Transmission_Bandwidth_t	 dL_Transmission_Bandwidth;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FDD_Info_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FDD_Info;
extern asn_SEQUENCE_specifics_t asn_SPC_FDD_Info_specs_1;
extern asn_TYPE_member_t asn_MBR_FDD_Info_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _FDD_Info_H_ */
#include <asn_internal.h>
