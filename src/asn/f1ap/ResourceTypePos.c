/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "ResourceTypePos.h"

#include "ResourceTypePeriodicPos.h"
#include "ResourceTypeSemi-persistentPos.h"
#include "ResourceTypeAperiodicPos.h"
#include "ProtocolIE-SingleContainer.h"
asn_per_constraints_t asn_PER_type_ResourceTypePos_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_ResourceTypePos_1[] = {
	{ ATF_POINTER, 0, offsetof(struct ResourceTypePos, choice.periodic),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ResourceTypePeriodicPos,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"periodic"
		},
	{ ATF_POINTER, 0, offsetof(struct ResourceTypePos, choice.semi_persistent),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ResourceTypeSemi_persistentPos,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"semi-persistent"
		},
	{ ATF_POINTER, 0, offsetof(struct ResourceTypePos, choice.aperiodic),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ResourceTypeAperiodicPos,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"aperiodic"
		},
	{ ATF_POINTER, 0, offsetof(struct ResourceTypePos, choice.choice_extension),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_SingleContainer_10642P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choice-extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_ResourceTypePos_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* periodic */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* semi-persistent */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* aperiodic */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* choice-extension */
};
asn_CHOICE_specifics_t asn_SPC_ResourceTypePos_specs_1 = {
	sizeof(struct ResourceTypePos),
	offsetof(struct ResourceTypePos, _asn_ctx),
	offsetof(struct ResourceTypePos, present),
	sizeof(((struct ResourceTypePos *)0)->present),
	asn_MAP_ResourceTypePos_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_ResourceTypePos = {
	"ResourceTypePos",
	"ResourceTypePos",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_ResourceTypePos_constr_1, CHOICE_constraint },
	asn_MBR_ResourceTypePos_1,
	4,	/* Elements count */
	&asn_SPC_ResourceTypePos_specs_1	/* Additional specs */
};

