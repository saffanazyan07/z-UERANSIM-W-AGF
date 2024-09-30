/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "DL-PRS.h"

static int
memb_prsid_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 255)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_memb_prsid_constr_2 CC_NOTUSED = {
	{ 1, 1 }	/* (0..255) */,
	-1};
static asn_per_constraints_t asn_PER_memb_prsid_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_DL_PRS_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DL_PRS, prsid),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_prsid_constr_2, &asn_PER_memb_prsid_constr_2,  memb_prsid_constraint_1 },
		0, 0, /* No default value */
		"prsid"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DL_PRS, dl_PRSResourceSetID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PRS_Resource_Set_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"dl-PRSResourceSetID"
		},
	{ ATF_POINTER, 2, offsetof(struct DL_PRS, dl_PRSResourceID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PRS_Resource_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"dl-PRSResourceID"
		},
	{ ATF_POINTER, 1, offsetof(struct DL_PRS, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_154P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_DL_PRS_oms_1[] = { 2, 3 };
static const ber_tlv_tag_t asn_DEF_DL_PRS_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DL_PRS_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* prsid */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* dl-PRSResourceSetID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* dl-PRSResourceID */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_DL_PRS_specs_1 = {
	sizeof(struct DL_PRS),
	offsetof(struct DL_PRS, _asn_ctx),
	asn_MAP_DL_PRS_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_DL_PRS_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_DL_PRS = {
	"DL-PRS",
	"DL-PRS",
	&asn_OP_SEQUENCE,
	asn_DEF_DL_PRS_tags_1,
	sizeof(asn_DEF_DL_PRS_tags_1)
		/sizeof(asn_DEF_DL_PRS_tags_1[0]), /* 1 */
	asn_DEF_DL_PRS_tags_1,	/* Same as above */
	sizeof(asn_DEF_DL_PRS_tags_1)
		/sizeof(asn_DEF_DL_PRS_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_DL_PRS_1,
	4,	/* Elements count */
	&asn_SPC_DL_PRS_specs_1	/* Additional specs */
};

