/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_IAB_Info_IAB_DU_H_
#define	_IAB_Info_IAB_DU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MultiplexingInfo;
struct IAB_STC_Info;
struct ProtocolExtensionContainer;

/* IAB-Info-IAB-DU */
typedef struct IAB_Info_IAB_DU {
	struct MultiplexingInfo	*multiplexingInfo	/* OPTIONAL */;
	struct IAB_STC_Info	*iAB_STC_Info	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IAB_Info_IAB_DU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IAB_Info_IAB_DU;

#ifdef __cplusplus
}
#endif

#endif	/* _IAB_Info_IAB_DU_H_ */
#include <asn_internal.h>
