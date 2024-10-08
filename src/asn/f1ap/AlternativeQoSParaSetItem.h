/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_AlternativeQoSParaSetItem_H_
#define	_AlternativeQoSParaSetItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include "QoSParaSetIndex.h"
#include "BitRate.h"
#include "PacketDelayBudget.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PacketErrorRate;
struct ProtocolExtensionContainer;

/* AlternativeQoSParaSetItem */
typedef struct AlternativeQoSParaSetItem {
	QoSParaSetIndex_t	 alternativeQoSParaSetIndex;
	BitRate_t	*guaranteedFlowBitRateDL	/* OPTIONAL */;
	BitRate_t	*guaranteedFlowBitRateUL	/* OPTIONAL */;
	PacketDelayBudget_t	*packetDelayBudget	/* OPTIONAL */;
	struct PacketErrorRate	*packetErrorRate	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AlternativeQoSParaSetItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AlternativeQoSParaSetItem;
extern asn_SEQUENCE_specifics_t asn_SPC_AlternativeQoSParaSetItem_specs_1;
extern asn_TYPE_member_t asn_MBR_AlternativeQoSParaSetItem_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _AlternativeQoSParaSetItem_H_ */
#include <asn_internal.h>
