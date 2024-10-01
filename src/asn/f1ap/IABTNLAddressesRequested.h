/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_IABTNLAddressesRequested_H_
#define	_IABTNLAddressesRequested_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* IABTNLAddressesRequested */
typedef struct IABTNLAddressesRequested {
	long	*tNLAddressesOrPrefixesRequestedAllTraffic	/* OPTIONAL */;
	long	*tNLAddressesOrPrefixesRequestedF1_C	/* OPTIONAL */;
	long	*tNLAddressesOrPrefixesRequestedF1_U	/* OPTIONAL */;
	long	*tNLAddressesOrPrefixesRequestedNoNF1	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IABTNLAddressesRequested_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IABTNLAddressesRequested;
extern asn_SEQUENCE_specifics_t asn_SPC_IABTNLAddressesRequested_specs_1;
extern asn_TYPE_member_t asn_MBR_IABTNLAddressesRequested_1[5];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _IABTNLAddressesRequested_H_ */
#include <asn_internal.h>
