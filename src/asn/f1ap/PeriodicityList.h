/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_PeriodicityList_H_
#define	_PeriodicityList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PeriodicityList_Item;

/* PeriodicityList */
typedef struct PeriodicityList {
	A_SEQUENCE_OF(struct PeriodicityList_Item) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PeriodicityList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PeriodicityList;
extern asn_SET_OF_specifics_t asn_SPC_PeriodicityList_specs_1;
extern asn_TYPE_member_t asn_MBR_PeriodicityList_1[1];
extern asn_per_constraints_t asn_PER_type_PeriodicityList_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _PeriodicityList_H_ */
#include <asn_internal.h>
