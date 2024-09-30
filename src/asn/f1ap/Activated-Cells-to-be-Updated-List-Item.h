/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_Activated_Cells_to_be_Updated_List_Item_H_
#define	_Activated_Cells_to_be_Updated_List_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRCGI.h"
#include "IAB-DU-Cell-Resource-Configuration-Mode-Info.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* Activated-Cells-to-be-Updated-List-Item */
typedef struct Activated_Cells_to_be_Updated_List_Item {
	NRCGI_t	 nRCGI;
	IAB_DU_Cell_Resource_Configuration_Mode_Info_t	 iAB_DU_Cell_Resource_Configuration_Mode_Info;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Activated_Cells_to_be_Updated_List_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Activated_Cells_to_be_Updated_List_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_Activated_Cells_to_be_Updated_List_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_Activated_Cells_to_be_Updated_List_Item_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _Activated_Cells_to_be_Updated_List_Item_H_ */
#include <asn_internal.h>
