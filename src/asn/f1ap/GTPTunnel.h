/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_GTPTunnel_H_
#define	_GTPTunnel_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TransportLayerAddress.h"
#include "GTP-TEID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* GTPTunnel */
typedef struct GTPTunnel {
	TransportLayerAddress_t	 transportLayerAddress;
	GTP_TEID_t	 gTP_TEID;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GTPTunnel_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GTPTunnel;
extern asn_SEQUENCE_specifics_t asn_SPC_GTPTunnel_specs_1;
extern asn_TYPE_member_t asn_MBR_GTPTunnel_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _GTPTunnel_H_ */
#include <asn_internal.h>
