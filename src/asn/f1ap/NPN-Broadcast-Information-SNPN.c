/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "NPN-Broadcast-Information-SNPN.h"

asn_TYPE_member_t asn_MBR_NPN_Broadcast_Information_SNPN_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NPN_Broadcast_Information_SNPN, broadcastSNPNID_List),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BroadcastSNPN_ID_List,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"broadcastSNPNID-List"
		},
	{ ATF_POINTER, 1, offsetof(struct NPN_Broadcast_Information_SNPN, iE_Extension),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_154P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extension"
		},
};
static const int asn_MAP_NPN_Broadcast_Information_SNPN_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_NPN_Broadcast_Information_SNPN_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NPN_Broadcast_Information_SNPN_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* broadcastSNPNID-List */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* iE-Extension */
};
asn_SEQUENCE_specifics_t asn_SPC_NPN_Broadcast_Information_SNPN_specs_1 = {
	sizeof(struct NPN_Broadcast_Information_SNPN),
	offsetof(struct NPN_Broadcast_Information_SNPN, _asn_ctx),
	asn_MAP_NPN_Broadcast_Information_SNPN_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_NPN_Broadcast_Information_SNPN_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NPN_Broadcast_Information_SNPN = {
	"NPN-Broadcast-Information-SNPN",
	"NPN-Broadcast-Information-SNPN",
	&asn_OP_SEQUENCE,
	asn_DEF_NPN_Broadcast_Information_SNPN_tags_1,
	sizeof(asn_DEF_NPN_Broadcast_Information_SNPN_tags_1)
		/sizeof(asn_DEF_NPN_Broadcast_Information_SNPN_tags_1[0]), /* 1 */
	asn_DEF_NPN_Broadcast_Information_SNPN_tags_1,	/* Same as above */
	sizeof(asn_DEF_NPN_Broadcast_Information_SNPN_tags_1)
		/sizeof(asn_DEF_NPN_Broadcast_Information_SNPN_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_NPN_Broadcast_Information_SNPN_1,
	2,	/* Elements count */
	&asn_SPC_NPN_Broadcast_Information_SNPN_specs_1	/* Additional specs */
};

