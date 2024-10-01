/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "PathlossReferenceInfo.h"

asn_TYPE_member_t asn_MBR_PathlossReferenceInfo_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PathlossReferenceInfo, pathlossReferenceSignal),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_PathlossReferenceSignal,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"pathlossReferenceSignal"
		},
	{ ATF_POINTER, 1, offsetof(struct PathlossReferenceInfo, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_154P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_PathlossReferenceInfo_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_PathlossReferenceInfo_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PathlossReferenceInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pathlossReferenceSignal */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_PathlossReferenceInfo_specs_1 = {
	sizeof(struct PathlossReferenceInfo),
	offsetof(struct PathlossReferenceInfo, _asn_ctx),
	asn_MAP_PathlossReferenceInfo_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_PathlossReferenceInfo_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PathlossReferenceInfo = {
	"PathlossReferenceInfo",
	"PathlossReferenceInfo",
	&asn_OP_SEQUENCE,
	asn_DEF_PathlossReferenceInfo_tags_1,
	sizeof(asn_DEF_PathlossReferenceInfo_tags_1)
		/sizeof(asn_DEF_PathlossReferenceInfo_tags_1[0]), /* 1 */
	asn_DEF_PathlossReferenceInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_PathlossReferenceInfo_tags_1)
		/sizeof(asn_DEF_PathlossReferenceInfo_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PathlossReferenceInfo_1,
	2,	/* Elements count */
	&asn_SPC_PathlossReferenceInfo_specs_1	/* Additional specs */
};

