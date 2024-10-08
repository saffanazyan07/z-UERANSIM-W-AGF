/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "DUF-Slot-Config-List.h"

#include "DUF-Slot-Config-Item.h"
asn_per_constraints_t asn_PER_type_DUF_Slot_Config_List_constr_1 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 9,  9,  1,  320 }	/* (SIZE(1..320)) */,
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_DUF_Slot_Config_List_1[] = {
	{ ATF_POINTER, 0, 0,
		-1 /* Ambiguous tag (CHOICE?) */,
		0,
		&asn_DEF_DUF_Slot_Config_Item,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_DUF_Slot_Config_List_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_SET_OF_specifics_t asn_SPC_DUF_Slot_Config_List_specs_1 = {
	sizeof(struct DUF_Slot_Config_List),
	offsetof(struct DUF_Slot_Config_List, _asn_ctx),
	2,	/* XER encoding is XMLValueList */
};
asn_TYPE_descriptor_t asn_DEF_DUF_Slot_Config_List = {
	"DUF-Slot-Config-List",
	"DUF-Slot-Config-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_DUF_Slot_Config_List_tags_1,
	sizeof(asn_DEF_DUF_Slot_Config_List_tags_1)
		/sizeof(asn_DEF_DUF_Slot_Config_List_tags_1[0]), /* 1 */
	asn_DEF_DUF_Slot_Config_List_tags_1,	/* Same as above */
	sizeof(asn_DEF_DUF_Slot_Config_List_tags_1)
		/sizeof(asn_DEF_DUF_Slot_Config_List_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_DUF_Slot_Config_List_constr_1, SEQUENCE_OF_constraint },
	asn_MBR_DUF_Slot_Config_List_1,
	1,	/* Single element */
	&asn_SPC_DUF_Slot_Config_List_specs_1	/* Additional specs */
};

