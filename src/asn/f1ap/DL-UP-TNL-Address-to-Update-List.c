/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-PDU-Contents"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "DL-UP-TNL-Address-to-Update-List.h"

#include "ProtocolIE-SingleContainer.h"
static asn_per_constraints_t asn_PER_type_DL_UP_TNL_Address_to_Update_List_constr_1 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 3,  3,  1,  8 }	/* (SIZE(1..8)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_DL_UP_TNL_Address_to_Update_List_1[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_ProtocolIE_SingleContainer_10642P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_DL_UP_TNL_Address_to_Update_List_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_DL_UP_TNL_Address_to_Update_List_specs_1 = {
	sizeof(struct DL_UP_TNL_Address_to_Update_List),
	offsetof(struct DL_UP_TNL_Address_to_Update_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t asn_DEF_DL_UP_TNL_Address_to_Update_List = {
	"DL-UP-TNL-Address-to-Update-List",
	"DL-UP-TNL-Address-to-Update-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_DL_UP_TNL_Address_to_Update_List_tags_1,
	sizeof(asn_DEF_DL_UP_TNL_Address_to_Update_List_tags_1)
		/sizeof(asn_DEF_DL_UP_TNL_Address_to_Update_List_tags_1[0]), /* 1 */
	asn_DEF_DL_UP_TNL_Address_to_Update_List_tags_1,	/* Same as above */
	sizeof(asn_DEF_DL_UP_TNL_Address_to_Update_List_tags_1)
		/sizeof(asn_DEF_DL_UP_TNL_Address_to_Update_List_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_DL_UP_TNL_Address_to_Update_List_constr_1, SEQUENCE_OF_constraint },
	asn_MBR_DL_UP_TNL_Address_to_Update_List_1,
	1,	/* Single element */
	&asn_SPC_DL_UP_TNL_Address_to_Update_List_specs_1	/* Additional specs */
};

