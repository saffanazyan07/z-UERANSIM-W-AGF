/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "DUCURIMInformation.h"

#include "ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_DUCURIMInformation_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DUCURIMInformation, victimgNBSetID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GNBSetID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"victimgNBSetID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DUCURIMInformation, rIMRSDetectionStatus),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIMRSDetectionStatus,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"rIMRSDetectionStatus"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DUCURIMInformation, aggressorCellList),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AggressorCellList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"aggressorCellList"
		},
	{ ATF_POINTER, 1, offsetof(struct DUCURIMInformation, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_DUCURIMInformation_oms_1[] = { 3 };
static const ber_tlv_tag_t asn_DEF_DUCURIMInformation_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DUCURIMInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* victimgNBSetID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* rIMRSDetectionStatus */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* aggressorCellList */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_DUCURIMInformation_specs_1 = {
	sizeof(struct DUCURIMInformation),
	offsetof(struct DUCURIMInformation, _asn_ctx),
	asn_MAP_DUCURIMInformation_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_DUCURIMInformation_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_DUCURIMInformation = {
	"DUCURIMInformation",
	"DUCURIMInformation",
	&asn_OP_SEQUENCE,
	asn_DEF_DUCURIMInformation_tags_1,
	sizeof(asn_DEF_DUCURIMInformation_tags_1)
		/sizeof(asn_DEF_DUCURIMInformation_tags_1[0]), /* 1 */
	asn_DEF_DUCURIMInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_DUCURIMInformation_tags_1)
		/sizeof(asn_DEF_DUCURIMInformation_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_DUCURIMInformation_1,
	4,	/* Elements count */
	&asn_SPC_DUCURIMInformation_specs_1	/* Additional specs */
};

