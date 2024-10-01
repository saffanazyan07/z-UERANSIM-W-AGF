/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_GTPTLAs_H_
#define	_GTPTLAs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct GTPTLA_Item;

/* GTPTLAs */
typedef struct GTPTLAs {
	A_SEQUENCE_OF(struct GTPTLA_Item) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GTPTLAs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GTPTLAs;
extern asn_SET_OF_specifics_t asn_SPC_GTPTLAs_specs_1;
extern asn_TYPE_member_t asn_MBR_GTPTLAs_1[1];
extern asn_per_constraints_t asn_PER_type_GTPTLAs_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "GTPTLA-Item.h"

#endif	/* _GTPTLAs_H_ */
#include <asn_internal.h>
