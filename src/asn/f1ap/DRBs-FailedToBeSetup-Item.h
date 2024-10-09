/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_DRBs_FailedToBeSetup_Item_H_
#define	_DRBs_FailedToBeSetup_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DRBID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Cause;
struct ProtocolExtensionContainer;

/* DRBs-FailedToBeSetup-Item */
typedef struct DRBs_FailedToBeSetup_Item {
	DRBID_t	 dRBID;
	struct Cause	*cause	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DRBs_FailedToBeSetup_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DRBs_FailedToBeSetup_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _DRBs_FailedToBeSetup_Item_H_ */
#include <asn_internal.h>
