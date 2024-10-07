/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "Extended-GNB-DU-Name.h"

#include "ProtocolExtensionContainer.h"
static asn_TYPE_member_t asn_MBR_Extended_GNB_DU_Name_1[] = {
	{ ATF_POINTER, 3, offsetof(struct Extended_GNB_DU_Name, gNB_DU_NameVisibleString),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GNB_DU_NameVisibleString,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"gNB-DU-NameVisibleString"
		},
	{ ATF_POINTER, 2, offsetof(struct Extended_GNB_DU_Name, gNB_DU_NameUTF8String),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GNB_DU_NameUTF8String,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"gNB-DU-NameUTF8String"
		},
	{ ATF_POINTER, 1, offsetof(struct Extended_GNB_DU_Name, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_Extended_GNB_DU_Name_oms_1[] = { 0, 1, 2 };
static const ber_tlv_tag_t asn_DEF_Extended_GNB_DU_Name_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Extended_GNB_DU_Name_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gNB-DU-NameVisibleString */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* gNB-DU-NameUTF8String */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_Extended_GNB_DU_Name_specs_1 = {
	sizeof(struct Extended_GNB_DU_Name),
	offsetof(struct Extended_GNB_DU_Name, _asn_ctx),
	asn_MAP_Extended_GNB_DU_Name_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_Extended_GNB_DU_Name_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Extended_GNB_DU_Name = {
	"Extended-GNB-DU-Name",
	"Extended-GNB-DU-Name",
	&asn_OP_SEQUENCE,
	asn_DEF_Extended_GNB_DU_Name_tags_1,
	sizeof(asn_DEF_Extended_GNB_DU_Name_tags_1)
		/sizeof(asn_DEF_Extended_GNB_DU_Name_tags_1[0]), /* 1 */
	asn_DEF_Extended_GNB_DU_Name_tags_1,	/* Same as above */
	sizeof(asn_DEF_Extended_GNB_DU_Name_tags_1)
		/sizeof(asn_DEF_Extended_GNB_DU_Name_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Extended_GNB_DU_Name_1,
	3,	/* Elements count */
	&asn_SPC_Extended_GNB_DU_Name_specs_1	/* Additional specs */
};

