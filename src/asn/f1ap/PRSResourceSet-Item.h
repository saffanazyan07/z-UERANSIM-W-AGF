/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_PRSResourceSet_Item_H_
#define	_PRSResourceSet_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PRS-Resource-Set-ID.h"
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include "PRSResource-List.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PRSResourceSet_Item__subcarrierSpacing {
	PRSResourceSet_Item__subcarrierSpacing_kHz15	= 0,
	PRSResourceSet_Item__subcarrierSpacing_kHz30	= 1,
	PRSResourceSet_Item__subcarrierSpacing_kHz60	= 2,
	PRSResourceSet_Item__subcarrierSpacing_kHz120	= 3
	/*
	 * Enumeration is extensible
	 */
} e_PRSResourceSet_Item__subcarrierSpacing;
typedef enum PRSResourceSet_Item__combSize {
	PRSResourceSet_Item__combSize_n2	= 0,
	PRSResourceSet_Item__combSize_n4	= 1,
	PRSResourceSet_Item__combSize_n6	= 2,
	PRSResourceSet_Item__combSize_n12	= 3
	/*
	 * Enumeration is extensible
	 */
} e_PRSResourceSet_Item__combSize;
typedef enum PRSResourceSet_Item__cPType {
	PRSResourceSet_Item__cPType_normal	= 0,
	PRSResourceSet_Item__cPType_extended	= 1
	/*
	 * Enumeration is extensible
	 */
} e_PRSResourceSet_Item__cPType;
typedef enum PRSResourceSet_Item__resourceSetPeriodicity {
	PRSResourceSet_Item__resourceSetPeriodicity_n4	= 0,
	PRSResourceSet_Item__resourceSetPeriodicity_n5	= 1,
	PRSResourceSet_Item__resourceSetPeriodicity_n8	= 2,
	PRSResourceSet_Item__resourceSetPeriodicity_n10	= 3,
	PRSResourceSet_Item__resourceSetPeriodicity_n16	= 4,
	PRSResourceSet_Item__resourceSetPeriodicity_n20	= 5,
	PRSResourceSet_Item__resourceSetPeriodicity_n32	= 6,
	PRSResourceSet_Item__resourceSetPeriodicity_n40	= 7,
	PRSResourceSet_Item__resourceSetPeriodicity_n64	= 8,
	PRSResourceSet_Item__resourceSetPeriodicity_n80	= 9,
	PRSResourceSet_Item__resourceSetPeriodicity_n160	= 10,
	PRSResourceSet_Item__resourceSetPeriodicity_n320	= 11,
	PRSResourceSet_Item__resourceSetPeriodicity_n640	= 12,
	PRSResourceSet_Item__resourceSetPeriodicity_n1280	= 13,
	PRSResourceSet_Item__resourceSetPeriodicity_n2560	= 14,
	PRSResourceSet_Item__resourceSetPeriodicity_n5120	= 15,
	PRSResourceSet_Item__resourceSetPeriodicity_n10240	= 16,
	PRSResourceSet_Item__resourceSetPeriodicity_n20480	= 17,
	PRSResourceSet_Item__resourceSetPeriodicity_n40960	= 18,
	PRSResourceSet_Item__resourceSetPeriodicity_n81920	= 19
	/*
	 * Enumeration is extensible
	 */
} e_PRSResourceSet_Item__resourceSetPeriodicity;
typedef enum PRSResourceSet_Item__resourceRepetitionFactor {
	PRSResourceSet_Item__resourceRepetitionFactor_rf1	= 0,
	PRSResourceSet_Item__resourceRepetitionFactor_rf2	= 1,
	PRSResourceSet_Item__resourceRepetitionFactor_rf4	= 2,
	PRSResourceSet_Item__resourceRepetitionFactor_rf6	= 3,
	PRSResourceSet_Item__resourceRepetitionFactor_rf8	= 4,
	PRSResourceSet_Item__resourceRepetitionFactor_rf16	= 5,
	PRSResourceSet_Item__resourceRepetitionFactor_rf32	= 6
	/*
	 * Enumeration is extensible
	 */
} e_PRSResourceSet_Item__resourceRepetitionFactor;
typedef enum PRSResourceSet_Item__resourceTimeGap {
	PRSResourceSet_Item__resourceTimeGap_tg1	= 0,
	PRSResourceSet_Item__resourceTimeGap_tg2	= 1,
	PRSResourceSet_Item__resourceTimeGap_tg4	= 2,
	PRSResourceSet_Item__resourceTimeGap_tg8	= 3,
	PRSResourceSet_Item__resourceTimeGap_tg16	= 4,
	PRSResourceSet_Item__resourceTimeGap_tg32	= 5
	/*
	 * Enumeration is extensible
	 */
} e_PRSResourceSet_Item__resourceTimeGap;
typedef enum PRSResourceSet_Item__resourceNumberofSymbols {
	PRSResourceSet_Item__resourceNumberofSymbols_n2	= 0,
	PRSResourceSet_Item__resourceNumberofSymbols_n4	= 1,
	PRSResourceSet_Item__resourceNumberofSymbols_n6	= 2,
	PRSResourceSet_Item__resourceNumberofSymbols_n12	= 3
	/*
	 * Enumeration is extensible
	 */
} e_PRSResourceSet_Item__resourceNumberofSymbols;

/* Forward declarations */
struct PRSMuting;
struct ProtocolExtensionContainer;

/* PRSResourceSet-Item */
typedef struct PRSResourceSet_Item {
	PRS_Resource_Set_ID_t	 pRSResourceSetID;
	long	 subcarrierSpacing;
	long	 pRSbandwidth;
	long	 startPRB;
	long	 pointA;
	long	 combSize;
	long	 cPType;
	long	 resourceSetPeriodicity;
	long	 resourceSetSlotOffset;
	long	 resourceRepetitionFactor;
	long	 resourceTimeGap;
	long	 resourceNumberofSymbols;
	struct PRSMuting	*pRSMuting	/* OPTIONAL */;
	long	 pRSResourceTransmitPower;
	PRSResource_List_t	 pRSResource_List;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PRSResourceSet_Item_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_subcarrierSpacing_3;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_combSize_12;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_cPType_18;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_resourceSetPeriodicity_22;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_resourceRepetitionFactor_45;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_resourceTimeGap_54;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_resourceNumberofSymbols_62;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_PRSResourceSet_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_PRSResourceSet_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_PRSResourceSet_Item_1[16];

#ifdef __cplusplus
}
#endif

#endif	/* _PRSResourceSet_Item_H_ */
#include <asn_internal.h>
