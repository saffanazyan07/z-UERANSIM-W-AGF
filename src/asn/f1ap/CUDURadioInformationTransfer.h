/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-PDU-Contents"
 * 	found in "F1AP-PDU-Contents.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#ifndef	_CUDURadioInformationTransfer_H_
#define	_CUDURadioInformationTransfer_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ProtocolIE-Container.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CUDURadioInformationTransfer */
typedef struct CUDURadioInformationTransfer {
	ProtocolIE_Container_117P0_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CUDURadioInformationTransfer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CUDURadioInformationTransfer;

#ifdef __cplusplus
}
#endif

#endif	/* _CUDURadioInformationTransfer_H_ */
#include <asn_internal.h>
