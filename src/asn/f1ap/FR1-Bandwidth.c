/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "FR1-Bandwidth.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
asn_per_constraints_t asn_PER_type_FR1_Bandwidth_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  6 }	/* (0..6,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_FR1_Bandwidth_value2enum_1[] = {
	{ 0,	3,	"bw5" },
	{ 1,	4,	"bw10" },
	{ 2,	4,	"bw20" },
	{ 3,	4,	"bw40" },
	{ 4,	4,	"bw50" },
	{ 5,	4,	"bw80" },
	{ 6,	5,	"bw100" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_FR1_Bandwidth_enum2value_1[] = {
	1,	/* bw10(1) */
	6,	/* bw100(6) */
	2,	/* bw20(2) */
	3,	/* bw40(3) */
	0,	/* bw5(0) */
	4,	/* bw50(4) */
	5	/* bw80(5) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_FR1_Bandwidth_specs_1 = {
	asn_MAP_FR1_Bandwidth_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_FR1_Bandwidth_enum2value_1,	/* N => "tag"; sorted by N */
	7,	/* Number of elements in the maps */
	8,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_FR1_Bandwidth_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_FR1_Bandwidth = {
	"FR1-Bandwidth",
	"FR1-Bandwidth",
	&asn_OP_NativeEnumerated,
	asn_DEF_FR1_Bandwidth_tags_1,
	sizeof(asn_DEF_FR1_Bandwidth_tags_1)
		/sizeof(asn_DEF_FR1_Bandwidth_tags_1[0]), /* 1 */
	asn_DEF_FR1_Bandwidth_tags_1,	/* Same as above */
	sizeof(asn_DEF_FR1_Bandwidth_tags_1)
		/sizeof(asn_DEF_FR1_Bandwidth_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_FR1_Bandwidth_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_FR1_Bandwidth_specs_1	/* Additional specs */
};

