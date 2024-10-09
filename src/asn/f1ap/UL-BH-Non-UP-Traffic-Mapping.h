/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_UL_BH_Non_UP_Traffic_Mapping_H_
#define	_UL_BH_Non_UP_Traffic_Mapping_H_


#include <asn_application.h>

/* Including external dependencies */
#include "UL-BH-Non-UP-Traffic-Mapping-List.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* UL-BH-Non-UP-Traffic-Mapping */
typedef struct UL_BH_Non_UP_Traffic_Mapping {
	UL_BH_Non_UP_Traffic_Mapping_List_t	 uL_BH_Non_UP_Traffic_Mapping_List;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UL_BH_Non_UP_Traffic_Mapping_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UL_BH_Non_UP_Traffic_Mapping;

#ifdef __cplusplus
}
#endif

#endif	/* _UL_BH_Non_UP_Traffic_Mapping_H_ */
#include <asn_internal.h>
