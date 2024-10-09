/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_SNSSAIAvailableCapacity_Item_H_
#define	_SNSSAIAvailableCapacity_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SNSSAI.h"
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* SNSSAIAvailableCapacity-Item */
typedef struct SNSSAIAvailableCapacity_Item {
	SNSSAI_t	 sNSSAI;
	long	*sliceAvailableCapacityValueDownlink	/* OPTIONAL */;
	long	*sliceAvailableCapacityValueUplink	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SNSSAIAvailableCapacity_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SNSSAIAvailableCapacity_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_SNSSAIAvailableCapacity_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_SNSSAIAvailableCapacity_Item_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _SNSSAIAvailableCapacity_Item_H_ */
#include <asn_internal.h>
