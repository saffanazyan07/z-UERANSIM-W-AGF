/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_GNB_DU_System_Information_H_
#define	_GNB_DU_System_Information_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MIB-message.h"
#include "SIB1-message.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* GNB-DU-System-Information */
typedef struct GNB_DU_System_Information {
	MIB_message_t	 mIB_message;
	SIB1_message_t	 sIB1_message;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GNB_DU_System_Information_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GNB_DU_System_Information;
extern asn_SEQUENCE_specifics_t asn_SPC_GNB_DU_System_Information_specs_1;
extern asn_TYPE_member_t asn_MBR_GNB_DU_System_Information_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _GNB_DU_System_Information_H_ */
#include <asn_internal.h>
