/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_GNB_RxTxTimeDiff_H_
#define	_GNB_RxTxTimeDiff_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GNBRxTxTimeDiffMeas.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct AdditionalPath_List;
struct ProtocolExtensionContainer;

/* GNB-RxTxTimeDiff */
typedef struct GNB_RxTxTimeDiff {
	GNBRxTxTimeDiffMeas_t	 rxTxTimeDiff;
	struct AdditionalPath_List	*additionalPath_List	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GNB_RxTxTimeDiff_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GNB_RxTxTimeDiff;
extern asn_SEQUENCE_specifics_t asn_SPC_GNB_RxTxTimeDiff_specs_1;
extern asn_TYPE_member_t asn_MBR_GNB_RxTxTimeDiff_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "AdditionalPath-List.h"
#include "ProtocolExtensionContainer.h"

#endif	/* _GNB_RxTxTimeDiff_H_ */
#include <asn_internal.h>
