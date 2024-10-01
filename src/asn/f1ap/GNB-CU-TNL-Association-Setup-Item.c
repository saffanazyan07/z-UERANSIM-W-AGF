/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "GNB-CU-TNL-Association-Setup-Item.h"

static asn_TYPE_member_t asn_MBR_GNB_CU_TNL_Association_Setup_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GNB_CU_TNL_Association_Setup_Item, tNLAssociationTransportLayerAddress),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_CP_TransportLayerAddress,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"tNLAssociationTransportLayerAddress"
		},
	{ ATF_POINTER, 1, offsetof(struct GNB_CU_TNL_Association_Setup_Item, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_154P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_GNB_CU_TNL_Association_Setup_Item_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_GNB_CU_TNL_Association_Setup_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GNB_CU_TNL_Association_Setup_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* tNLAssociationTransportLayerAddress */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_GNB_CU_TNL_Association_Setup_Item_specs_1 = {
	sizeof(struct GNB_CU_TNL_Association_Setup_Item),
	offsetof(struct GNB_CU_TNL_Association_Setup_Item, _asn_ctx),
	asn_MAP_GNB_CU_TNL_Association_Setup_Item_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_GNB_CU_TNL_Association_Setup_Item_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_GNB_CU_TNL_Association_Setup_Item = {
	"GNB-CU-TNL-Association-Setup-Item",
	"GNB-CU-TNL-Association-Setup-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_GNB_CU_TNL_Association_Setup_Item_tags_1,
	sizeof(asn_DEF_GNB_CU_TNL_Association_Setup_Item_tags_1)
		/sizeof(asn_DEF_GNB_CU_TNL_Association_Setup_Item_tags_1[0]), /* 1 */
	asn_DEF_GNB_CU_TNL_Association_Setup_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_GNB_CU_TNL_Association_Setup_Item_tags_1)
		/sizeof(asn_DEF_GNB_CU_TNL_Association_Setup_Item_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_GNB_CU_TNL_Association_Setup_Item_1,
	2,	/* Elements count */
	&asn_SPC_GNB_CU_TNL_Association_Setup_Item_specs_1	/* Additional specs */
};

