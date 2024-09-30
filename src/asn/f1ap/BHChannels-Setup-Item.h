/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_BHChannels_Setup_Item_H_
#define	_BHChannels_Setup_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BHRLCChannelID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* BHChannels-Setup-Item */
typedef struct BHChannels_Setup_Item {
	BHRLCChannelID_t	 bHRLCChannelID;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BHChannels_Setup_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BHChannels_Setup_Item;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _BHChannels_Setup_Item_H_ */
#include <asn_internal.h>
