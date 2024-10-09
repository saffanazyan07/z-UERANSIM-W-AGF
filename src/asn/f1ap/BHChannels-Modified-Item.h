/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_BHChannels_Modified_Item_H_
#define	_BHChannels_Modified_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BHRLCChannelID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* BHChannels-Modified-Item */
typedef struct BHChannels_Modified_Item {
	BHRLCChannelID_t	 bHRLCChannelID;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BHChannels_Modified_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BHChannels_Modified_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _BHChannels_Modified_Item_H_ */
#include <asn_internal.h>
