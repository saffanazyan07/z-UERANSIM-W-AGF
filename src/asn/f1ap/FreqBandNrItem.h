/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_FreqBandNrItem_H_
#define	_FreqBandNrItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;
struct SupportedSULFreqBandItem;

/* FreqBandNrItem */
typedef struct FreqBandNrItem {
	long	 freqBandIndicatorNr;
	struct FreqBandNrItem__supportedSULBandList {
		A_SEQUENCE_OF(struct SupportedSULFreqBandItem) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} supportedSULBandList;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FreqBandNrItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FreqBandNrItem;
extern asn_SEQUENCE_specifics_t asn_SPC_FreqBandNrItem_specs_1;
extern asn_TYPE_member_t asn_MBR_FreqBandNrItem_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"
#include "SupportedSULFreqBandItem.h"

#endif	/* _FreqBandNrItem_H_ */
#include <asn_internal.h>
