/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_DRB_Notify_Item_H_
#define	_DRB_Notify_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DRBID.h"
#include "Notification-Cause.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* DRB-Notify-Item */
typedef struct DRB_Notify_Item {
	DRBID_t	 dRBID;
	Notification_Cause_t	 notification_Cause;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DRB_Notify_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DRB_Notify_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _DRB_Notify_Item_H_ */
#include <asn_internal.h>
