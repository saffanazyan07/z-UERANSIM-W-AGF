/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_HardwareLoadIndicator_H_
#define	_HardwareLoadIndicator_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* HardwareLoadIndicator */
typedef struct HardwareLoadIndicator {
	long	 dLHardwareLoadIndicator;
	long	 uLHardwareLoadIndicator;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} HardwareLoadIndicator_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HardwareLoadIndicator;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _HardwareLoadIndicator_H_ */
#include <asn_internal.h>
