/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_PositioningBroadcastCells_H_
#define	_PositioningBroadcastCells_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NRCGI;

/* PositioningBroadcastCells */
typedef struct PositioningBroadcastCells {
	A_SEQUENCE_OF(struct NRCGI) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PositioningBroadcastCells_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PositioningBroadcastCells;

#ifdef __cplusplus
}
#endif

#endif	/* _PositioningBroadcastCells_H_ */
#include <asn_internal.h>
