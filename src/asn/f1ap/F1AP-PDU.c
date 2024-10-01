/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-PDU-Descriptions"
 * 	found in "F1AP-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "F1AP-PDU.h"

static asn_oer_constraints_t asn_OER_type_F1AP_PDU_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_F1AP_PDU_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_F1AP_PDU_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct F1AP_PDU, choice.initiatingMessage),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_InitiatingMessage,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"initiatingMessage"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct F1AP_PDU, choice.successfulOutcome),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SuccessfulOutcome,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"successfulOutcome"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct F1AP_PDU, choice.unsuccessfulOutcome),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UnsuccessfulOutcome,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"unsuccessfulOutcome"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct F1AP_PDU, choice.choice_extension),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_SingleContainer_120P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choice-extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_F1AP_PDU_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* initiatingMessage */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* successfulOutcome */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* unsuccessfulOutcome */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* choice-extension */
};
static asn_CHOICE_specifics_t asn_SPC_F1AP_PDU_specs_1 = {
	sizeof(struct F1AP_PDU),
	offsetof(struct F1AP_PDU, _asn_ctx),
	offsetof(struct F1AP_PDU, present),
	sizeof(((struct F1AP_PDU *)0)->present),
	asn_MAP_F1AP_PDU_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_F1AP_PDU = {
	"F1AP-PDU",
	"F1AP-PDU",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_F1AP_PDU_constr_1, &asn_PER_type_F1AP_PDU_constr_1, CHOICE_constraint },
	asn_MBR_F1AP_PDU_1,
	4,	/* Elements count */
	&asn_SPC_F1AP_PDU_specs_1	/* Additional specs */
};

