/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "SLDRBs-FailedToBeModified-Item.h"

#include "Cause.h"
#include "ProtocolExtensionContainer.h"
static asn_TYPE_member_t asn_MBR_SLDRBs_FailedToBeModified_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SLDRBs_FailedToBeModified_Item, sLDRBID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SLDRBID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sLDRBID"
		},
	{ ATF_POINTER, 2, offsetof(struct SLDRBs_FailedToBeModified_Item, cause),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_Cause,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"cause"
		},
	{ ATF_POINTER, 1, offsetof(struct SLDRBs_FailedToBeModified_Item, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_SLDRBs_FailedToBeModified_Item_oms_1[] = { 1, 2 };
static const ber_tlv_tag_t asn_DEF_SLDRBs_FailedToBeModified_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SLDRBs_FailedToBeModified_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* sLDRBID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* cause */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_SLDRBs_FailedToBeModified_Item_specs_1 = {
	sizeof(struct SLDRBs_FailedToBeModified_Item),
	offsetof(struct SLDRBs_FailedToBeModified_Item, _asn_ctx),
	asn_MAP_SLDRBs_FailedToBeModified_Item_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_SLDRBs_FailedToBeModified_Item_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_SLDRBs_FailedToBeModified_Item = {
	"SLDRBs-FailedToBeModified-Item",
	"SLDRBs-FailedToBeModified-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_SLDRBs_FailedToBeModified_Item_tags_1,
	sizeof(asn_DEF_SLDRBs_FailedToBeModified_Item_tags_1)
		/sizeof(asn_DEF_SLDRBs_FailedToBeModified_Item_tags_1[0]), /* 1 */
	asn_DEF_SLDRBs_FailedToBeModified_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_SLDRBs_FailedToBeModified_Item_tags_1)
		/sizeof(asn_DEF_SLDRBs_FailedToBeModified_Item_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_SLDRBs_FailedToBeModified_Item_1,
	3,	/* Elements count */
	&asn_SPC_SLDRBs_FailedToBeModified_Item_specs_1	/* Additional specs */
};

