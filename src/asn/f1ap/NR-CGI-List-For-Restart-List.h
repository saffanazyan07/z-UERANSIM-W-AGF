/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-PDU-Contents"
 * 	found in "F1AP-PDU-Contents.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_NR_CGI_List_For_Restart_List_H_
#define	_NR_CGI_List_For_Restart_List_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolIE_SingleContainer;

/* NR-CGI-List-For-Restart-List */
typedef struct NR_CGI_List_For_Restart_List {
	A_SEQUENCE_OF(struct ProtocolIE_SingleContainer) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NR_CGI_List_For_Restart_List_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NR_CGI_List_For_Restart_List;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolIE-SingleContainer.h"

#endif	/* _NR_CGI_List_For_Restart_List_H_ */
#include <asn_internal.h>
