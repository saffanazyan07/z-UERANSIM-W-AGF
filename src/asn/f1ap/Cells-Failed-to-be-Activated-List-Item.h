/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_Cells_Failed_to_be_Activated_List_Item_H_
#define	_Cells_Failed_to_be_Activated_List_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRCGI.h"
#include "Cause.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* Cells-Failed-to-be-Activated-List-Item */
typedef struct Cells_Failed_to_be_Activated_List_Item {
	NRCGI_t	 nRCGI;
	Cause_t	 cause;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Cells_Failed_to_be_Activated_List_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Cells_Failed_to_be_Activated_List_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _Cells_Failed_to_be_Activated_List_Item_H_ */
#include <asn_internal.h>
