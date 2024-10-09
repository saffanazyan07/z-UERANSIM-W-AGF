/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_ResourceTypePeriodicPos_H_
#define	_ResourceTypePeriodicPos_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ResourceTypePeriodicPos__periodicity {
	ResourceTypePeriodicPos__periodicity_slot1	= 0,
	ResourceTypePeriodicPos__periodicity_slot2	= 1,
	ResourceTypePeriodicPos__periodicity_slot4	= 2,
	ResourceTypePeriodicPos__periodicity_slot5	= 3,
	ResourceTypePeriodicPos__periodicity_slot8	= 4,
	ResourceTypePeriodicPos__periodicity_slot10	= 5,
	ResourceTypePeriodicPos__periodicity_slot16	= 6,
	ResourceTypePeriodicPos__periodicity_slot20	= 7,
	ResourceTypePeriodicPos__periodicity_slot32	= 8,
	ResourceTypePeriodicPos__periodicity_slot40	= 9,
	ResourceTypePeriodicPos__periodicity_slot64	= 10,
	ResourceTypePeriodicPos__periodicity_slot80	= 11,
	ResourceTypePeriodicPos__periodicity_slot160	= 12,
	ResourceTypePeriodicPos__periodicity_slot320	= 13,
	ResourceTypePeriodicPos__periodicity_slot640	= 14,
	ResourceTypePeriodicPos__periodicity_slot1280	= 15,
	ResourceTypePeriodicPos__periodicity_slot2560	= 16,
	ResourceTypePeriodicPos__periodicity_slot5120	= 17,
	ResourceTypePeriodicPos__periodicity_slot10240	= 18,
	ResourceTypePeriodicPos__periodicity_slot40960	= 19,
	ResourceTypePeriodicPos__periodicity_slot81920	= 20
	/*
	 * Enumeration is extensible
	 */
} e_ResourceTypePeriodicPos__periodicity;

/* Forward declarations */
struct ProtocolExtensionContainer;

/* ResourceTypePeriodicPos */
typedef struct ResourceTypePeriodicPos {
	long	 periodicity;
	long	 offset;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ResourceTypePeriodicPos_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_periodicity_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_ResourceTypePeriodicPos;
extern asn_SEQUENCE_specifics_t asn_SPC_ResourceTypePeriodicPos_specs_1;
extern asn_TYPE_member_t asn_MBR_ResourceTypePeriodicPos_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _ResourceTypePeriodicPos_H_ */
#include <asn_internal.h>
