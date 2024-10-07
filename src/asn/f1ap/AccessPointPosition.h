/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_AccessPointPosition_H_
#define	_AccessPointPosition_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum AccessPointPosition__latitudeSign {
	AccessPointPosition__latitudeSign_north	= 0,
	AccessPointPosition__latitudeSign_south	= 1
} e_AccessPointPosition__latitudeSign;
typedef enum AccessPointPosition__directionOfAltitude {
	AccessPointPosition__directionOfAltitude_height	= 0,
	AccessPointPosition__directionOfAltitude_depth	= 1
} e_AccessPointPosition__directionOfAltitude;

/* Forward declarations */
struct ProtocolExtensionContainer;

/* AccessPointPosition */
typedef struct AccessPointPosition {
	long	 latitudeSign;
	long	 latitude;
	long	 longitude;
	long	 directionOfAltitude;
	long	 altitude;
	long	 uncertaintySemi_major;
	long	 uncertaintySemi_minor;
	long	 orientationOfMajorAxis;
	long	 uncertaintyAltitude;
	long	 confidence;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AccessPointPosition_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_latitudeSign_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_directionOfAltitude_7;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_AccessPointPosition;
extern asn_SEQUENCE_specifics_t asn_SPC_AccessPointPosition_specs_1;
extern asn_TYPE_member_t asn_MBR_AccessPointPosition_1[11];

#ifdef __cplusplus
}
#endif

#endif	/* _AccessPointPosition_H_ */
#include <asn_internal.h>
