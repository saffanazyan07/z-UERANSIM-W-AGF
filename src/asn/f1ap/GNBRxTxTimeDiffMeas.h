/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_GNBRxTxTimeDiffMeas_H_
#define	_GNBRxTxTimeDiffMeas_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "ProtocolIE-SingleContainer.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum GNBRxTxTimeDiffMeas_PR {
	GNBRxTxTimeDiffMeas_PR_NOTHING,	/* No components present */
	GNBRxTxTimeDiffMeas_PR_k0,
	GNBRxTxTimeDiffMeas_PR_k1,
	GNBRxTxTimeDiffMeas_PR_k2,
	GNBRxTxTimeDiffMeas_PR_k3,
	GNBRxTxTimeDiffMeas_PR_k4,
	GNBRxTxTimeDiffMeas_PR_k5,
	GNBRxTxTimeDiffMeas_PR_choice_extension
} GNBRxTxTimeDiffMeas_PR;

/* GNBRxTxTimeDiffMeas */
typedef struct GNBRxTxTimeDiffMeas {
	GNBRxTxTimeDiffMeas_PR present;
	union GNBRxTxTimeDiffMeas_u {
		long	 k0;
		long	 k1;
		long	 k2;
		long	 k3;
		long	 k4;
		long	 k5;
		ProtocolIE_SingleContainer_120P0_t	 choice_extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GNBRxTxTimeDiffMeas_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GNBRxTxTimeDiffMeas;
extern asn_CHOICE_specifics_t asn_SPC_GNBRxTxTimeDiffMeas_specs_1;
extern asn_TYPE_member_t asn_MBR_GNBRxTxTimeDiffMeas_1[7];
extern asn_per_constraints_t asn_PER_type_GNBRxTxTimeDiffMeas_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _GNBRxTxTimeDiffMeas_H_ */
#include <asn_internal.h>
