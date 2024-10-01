/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_GTPTLA_Item_H_
#define	_GTPTLA_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TransportLayerAddress.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* GTPTLA-Item */
typedef struct GTPTLA_Item {
	TransportLayerAddress_t	 gTPTransportLayerAddress;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GTPTLA_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GTPTLA_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_GTPTLA_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_GTPTLA_Item_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _GTPTLA_Item_H_ */
#include <asn_internal.h>
