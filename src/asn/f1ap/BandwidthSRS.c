/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "BandwidthSRS.h"

static asn_oer_constraints_t asn_OER_type_BandwidthSRS_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_BandwidthSRS_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_BandwidthSRS_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct BandwidthSRS, choice.fR1),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_FR1_Bandwidth,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"fR1"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BandwidthSRS, choice.fR2),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_FR2_Bandwidth,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"fR2"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BandwidthSRS, choice.choice_extension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_SingleContainer_120P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choice-extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_BandwidthSRS_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* fR1 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* fR2 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* choice-extension */
};
asn_CHOICE_specifics_t asn_SPC_BandwidthSRS_specs_1 = {
	sizeof(struct BandwidthSRS),
	offsetof(struct BandwidthSRS, _asn_ctx),
	offsetof(struct BandwidthSRS, present),
	sizeof(((struct BandwidthSRS *)0)->present),
	asn_MAP_BandwidthSRS_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_BandwidthSRS = {
	"BandwidthSRS",
	"BandwidthSRS",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_BandwidthSRS_constr_1, &asn_PER_type_BandwidthSRS_constr_1, CHOICE_constraint },
	asn_MBR_BandwidthSRS_1,
	3,	/* Elements count */
	&asn_SPC_BandwidthSRS_specs_1	/* Additional specs */
};

