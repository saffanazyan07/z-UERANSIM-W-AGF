/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "NR-Mode-Info.h"

static asn_oer_constraints_t asn_OER_type_NR_Mode_Info_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_NR_Mode_Info_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_NR_Mode_Info_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NR_Mode_Info, choice.fDD),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_FDD_Info,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"fDD"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NR_Mode_Info, choice.tDD),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TDD_Info,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"tDD"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NR_Mode_Info, choice.choice_extension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_SingleContainer_120P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choice-extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_NR_Mode_Info_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* fDD */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* tDD */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* choice-extension */
};
asn_CHOICE_specifics_t asn_SPC_NR_Mode_Info_specs_1 = {
	sizeof(struct NR_Mode_Info),
	offsetof(struct NR_Mode_Info, _asn_ctx),
	offsetof(struct NR_Mode_Info, present),
	sizeof(((struct NR_Mode_Info *)0)->present),
	asn_MAP_NR_Mode_Info_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_NR_Mode_Info = {
	"NR-Mode-Info",
	"NR-Mode-Info",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_NR_Mode_Info_constr_1, &asn_PER_type_NR_Mode_Info_constr_1, CHOICE_constraint },
	asn_MBR_NR_Mode_Info_1,
	3,	/* Elements count */
	&asn_SPC_NR_Mode_Info_specs_1	/* Additional specs */
};

