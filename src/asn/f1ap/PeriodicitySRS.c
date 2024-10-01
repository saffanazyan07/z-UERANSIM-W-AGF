/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "PeriodicitySRS.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_PeriodicitySRS_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_PeriodicitySRS_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  5,  5,  0,  24 }	/* (0..24,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_PeriodicitySRS_value2enum_1[] = {
	{ 0,	7,	"ms0p125" },
	{ 1,	6,	"ms0p25" },
	{ 2,	5,	"ms0p5" },
	{ 3,	7,	"ms0p625" },
	{ 4,	3,	"ms1" },
	{ 5,	6,	"ms1p25" },
	{ 6,	3,	"ms2" },
	{ 7,	5,	"ms2p5" },
	{ 8,	3,	"ms4" },
	{ 9,	3,	"ms5" },
	{ 10,	3,	"ms8" },
	{ 11,	4,	"ms10" },
	{ 12,	4,	"ms16" },
	{ 13,	4,	"ms20" },
	{ 14,	4,	"ms32" },
	{ 15,	4,	"ms40" },
	{ 16,	4,	"ms64" },
	{ 17,	4,	"ms80" },
	{ 18,	5,	"ms160" },
	{ 19,	5,	"ms320" },
	{ 20,	5,	"ms640" },
	{ 21,	6,	"ms1280" },
	{ 22,	6,	"ms2560" },
	{ 23,	6,	"ms5120" },
	{ 24,	7,	"ms10240" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_PeriodicitySRS_enum2value_1[] = {
	0,	/* ms0p125(0) */
	1,	/* ms0p25(1) */
	2,	/* ms0p5(2) */
	3,	/* ms0p625(3) */
	4,	/* ms1(4) */
	11,	/* ms10(11) */
	24,	/* ms10240(24) */
	21,	/* ms1280(21) */
	12,	/* ms16(12) */
	18,	/* ms160(18) */
	5,	/* ms1p25(5) */
	6,	/* ms2(6) */
	13,	/* ms20(13) */
	22,	/* ms2560(22) */
	7,	/* ms2p5(7) */
	14,	/* ms32(14) */
	19,	/* ms320(19) */
	8,	/* ms4(8) */
	15,	/* ms40(15) */
	9,	/* ms5(9) */
	23,	/* ms5120(23) */
	16,	/* ms64(16) */
	20,	/* ms640(20) */
	10,	/* ms8(10) */
	17	/* ms80(17) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_PeriodicitySRS_specs_1 = {
	asn_MAP_PeriodicitySRS_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_PeriodicitySRS_enum2value_1,	/* N => "tag"; sorted by N */
	25,	/* Number of elements in the maps */
	26,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_PeriodicitySRS_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_PeriodicitySRS = {
	"PeriodicitySRS",
	"PeriodicitySRS",
	&asn_OP_NativeEnumerated,
	asn_DEF_PeriodicitySRS_tags_1,
	sizeof(asn_DEF_PeriodicitySRS_tags_1)
		/sizeof(asn_DEF_PeriodicitySRS_tags_1[0]), /* 1 */
	asn_DEF_PeriodicitySRS_tags_1,	/* Same as above */
	sizeof(asn_DEF_PeriodicitySRS_tags_1)
		/sizeof(asn_DEF_PeriodicitySRS_tags_1[0]), /* 1 */
	{ &asn_OER_type_PeriodicitySRS_constr_1, &asn_PER_type_PeriodicitySRS_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_PeriodicitySRS_specs_1	/* Additional specs */
};

