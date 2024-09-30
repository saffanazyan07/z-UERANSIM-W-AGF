/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_UL_RTOA_Measurement_H_
#define	_UL_RTOA_Measurement_H_


#include <asn_application.h>

/* Including external dependencies */
#include "UL-RTOA-MeasurementItem.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct AdditionalPath_List;
struct ProtocolExtensionContainer;

/* UL-RTOA-Measurement */
typedef struct UL_RTOA_Measurement {
	UL_RTOA_MeasurementItem_t	 uL_RTOA_MeasurementItem;
	struct AdditionalPath_List	*additionalPath_List	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UL_RTOA_Measurement_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UL_RTOA_Measurement;
extern asn_SEQUENCE_specifics_t asn_SPC_UL_RTOA_Measurement_specs_1;
extern asn_TYPE_member_t asn_MBR_UL_RTOA_Measurement_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "AdditionalPath-List.h"
#include "ProtocolExtensionContainer.h"

#endif	/* _UL_RTOA_Measurement_H_ */
#include <asn_internal.h>
