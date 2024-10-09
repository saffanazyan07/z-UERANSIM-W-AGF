/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_NRV2XServicesAuthorized_H_
#define	_NRV2XServicesAuthorized_H_


#include <asn_application.h>

/* Including external dependencies */
#include "VehicleUE.h"
#include "PedestrianUE.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* NRV2XServicesAuthorized */
typedef struct NRV2XServicesAuthorized {
	VehicleUE_t	*vehicleUE	/* OPTIONAL */;
	PedestrianUE_t	*pedestrianUE	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRV2XServicesAuthorized_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRV2XServicesAuthorized;

#ifdef __cplusplus
}
#endif

#endif	/* _NRV2XServicesAuthorized_H_ */
#include <asn_internal.h>
