/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_Slot_Configuration_Item_H_
#define	_Slot_Configuration_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "SymbolAllocInSlot.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* Slot-Configuration-Item */
typedef struct Slot_Configuration_Item {
	long	 slotIndex;
	SymbolAllocInSlot_t	 symbolAllocInSlot;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Slot_Configuration_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Slot_Configuration_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_Slot_Configuration_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_Slot_Configuration_Item_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _Slot_Configuration_Item_H_ */
#include <asn_internal.h>
