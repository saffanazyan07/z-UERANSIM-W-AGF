/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "PRSMutingOption1.h"

#include "ProtocolExtensionContainer.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_per_constraints_t asn_PER_type_mutingBitRepetitionFactor_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  3 }	/* (0..3,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_mutingBitRepetitionFactor_value2enum_3[] = {
	{ 0,	3,	"rf1" },
	{ 1,	3,	"rf2" },
	{ 2,	3,	"rf4" },
	{ 3,	3,	"rf8" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_mutingBitRepetitionFactor_enum2value_3[] = {
	0,	/* rf1(0) */
	1,	/* rf2(1) */
	2,	/* rf4(2) */
	3	/* rf8(3) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_mutingBitRepetitionFactor_specs_3 = {
	asn_MAP_mutingBitRepetitionFactor_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_mutingBitRepetitionFactor_enum2value_3,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	5,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_mutingBitRepetitionFactor_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mutingBitRepetitionFactor_3 = {
	"mutingBitRepetitionFactor",
	"mutingBitRepetitionFactor",
	&asn_OP_NativeEnumerated,
	asn_DEF_mutingBitRepetitionFactor_tags_3,
	sizeof(asn_DEF_mutingBitRepetitionFactor_tags_3)
		/sizeof(asn_DEF_mutingBitRepetitionFactor_tags_3[0]) - 1, /* 1 */
	asn_DEF_mutingBitRepetitionFactor_tags_3,	/* Same as above */
	sizeof(asn_DEF_mutingBitRepetitionFactor_tags_3)
		/sizeof(asn_DEF_mutingBitRepetitionFactor_tags_3[0]), /* 2 */
	{ 0, &asn_PER_type_mutingBitRepetitionFactor_constr_3, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_mutingBitRepetitionFactor_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_PRSMutingOption1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PRSMutingOption1, mutingPattern),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_DL_PRSMutingPattern,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"mutingPattern"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PRSMutingOption1, mutingBitRepetitionFactor),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_mutingBitRepetitionFactor_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"mutingBitRepetitionFactor"
		},
	{ ATF_POINTER, 1, offsetof(struct PRSMutingOption1, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_PRSMutingOption1_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_PRSMutingOption1_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PRSMutingOption1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* mutingPattern */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mutingBitRepetitionFactor */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_PRSMutingOption1_specs_1 = {
	sizeof(struct PRSMutingOption1),
	offsetof(struct PRSMutingOption1, _asn_ctx),
	asn_MAP_PRSMutingOption1_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_PRSMutingOption1_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PRSMutingOption1 = {
	"PRSMutingOption1",
	"PRSMutingOption1",
	&asn_OP_SEQUENCE,
	asn_DEF_PRSMutingOption1_tags_1,
	sizeof(asn_DEF_PRSMutingOption1_tags_1)
		/sizeof(asn_DEF_PRSMutingOption1_tags_1[0]), /* 1 */
	asn_DEF_PRSMutingOption1_tags_1,	/* Same as above */
	sizeof(asn_DEF_PRSMutingOption1_tags_1)
		/sizeof(asn_DEF_PRSMutingOption1_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PRSMutingOption1_1,
	3,	/* Elements count */
	&asn_SPC_PRSMutingOption1_specs_1	/* Additional specs */
};

