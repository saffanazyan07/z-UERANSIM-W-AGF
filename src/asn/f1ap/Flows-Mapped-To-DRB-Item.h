/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_Flows_Mapped_To_DRB_Item_H_
#define	_Flows_Mapped_To_DRB_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "QoSFlowIdentifier.h"
#include "QoSFlowLevelQoSParameters.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* Flows-Mapped-To-DRB-Item */
typedef struct Flows_Mapped_To_DRB_Item {
	QoSFlowIdentifier_t	 qoSFlowIdentifier;
	QoSFlowLevelQoSParameters_t	 qoSFlowLevelQoSParameters;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Flows_Mapped_To_DRB_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Flows_Mapped_To_DRB_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_Flows_Mapped_To_DRB_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_Flows_Mapped_To_DRB_Item_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _Flows_Mapped_To_DRB_Item_H_ */
#include <asn_internal.h>
