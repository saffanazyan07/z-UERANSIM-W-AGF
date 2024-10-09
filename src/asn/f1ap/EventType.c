/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "EventType.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
asn_per_constraints_t asn_PER_type_EventType_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_EventType_value2enum_1[] = {
	{ 0,	9,	"on-demand" },
	{ 1,	8,	"periodic" },
	{ 2,	4,	"stop" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_EventType_enum2value_1[] = {
	0,	/* on-demand(0) */
	1,	/* periodic(1) */
	2	/* stop(2) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_EventType_specs_1 = {
	asn_MAP_EventType_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_EventType_enum2value_1,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_EventType_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_EventType = {
	"EventType",
	"EventType",
	&asn_OP_NativeEnumerated,
	asn_DEF_EventType_tags_1,
	sizeof(asn_DEF_EventType_tags_1)
		/sizeof(asn_DEF_EventType_tags_1[0]), /* 1 */
	asn_DEF_EventType_tags_1,	/* Same as above */
	sizeof(asn_DEF_EventType_tags_1)
		/sizeof(asn_DEF_EventType_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_EventType_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_EventType_specs_1	/* Additional specs */
};

