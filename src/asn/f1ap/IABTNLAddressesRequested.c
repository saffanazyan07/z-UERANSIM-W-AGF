/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "F1AP-IEs.asn"
 * 	`asn1c -fcompound-names -gen-PER -D .`
 */

#include "IABTNLAddressesRequested.h"

static int
memb_tNLAddressesOrPrefixesRequestedAllTraffic_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 256)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_tNLAddressesOrPrefixesRequestedF1_C_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 256)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_tNLAddressesOrPrefixesRequestedF1_U_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 256)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_tNLAddressesOrPrefixesRequestedNoNF1_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 256)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_memb_tNLAddressesOrPrefixesRequestedAllTraffic_constr_2 CC_NOTUSED = {
	{ 2, 1 }	/* (1..256) */,
	-1};
static asn_per_constraints_t asn_PER_memb_tNLAddressesOrPrefixesRequestedAllTraffic_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  1,  256 }	/* (1..256) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_tNLAddressesOrPrefixesRequestedF1_C_constr_3 CC_NOTUSED = {
	{ 2, 1 }	/* (1..256) */,
	-1};
static asn_per_constraints_t asn_PER_memb_tNLAddressesOrPrefixesRequestedF1_C_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  1,  256 }	/* (1..256) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_tNLAddressesOrPrefixesRequestedF1_U_constr_4 CC_NOTUSED = {
	{ 2, 1 }	/* (1..256) */,
	-1};
static asn_per_constraints_t asn_PER_memb_tNLAddressesOrPrefixesRequestedF1_U_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  1,  256 }	/* (1..256) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_tNLAddressesOrPrefixesRequestedNoNF1_constr_5 CC_NOTUSED = {
	{ 2, 1 }	/* (1..256) */,
	-1};
static asn_per_constraints_t asn_PER_memb_tNLAddressesOrPrefixesRequestedNoNF1_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  1,  256 }	/* (1..256) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_IABTNLAddressesRequested_1[] = {
	{ ATF_POINTER, 5, offsetof(struct IABTNLAddressesRequested, tNLAddressesOrPrefixesRequestedAllTraffic),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_tNLAddressesOrPrefixesRequestedAllTraffic_constr_2, &asn_PER_memb_tNLAddressesOrPrefixesRequestedAllTraffic_constr_2,  memb_tNLAddressesOrPrefixesRequestedAllTraffic_constraint_1 },
		0, 0, /* No default value */
		"tNLAddressesOrPrefixesRequestedAllTraffic"
		},
	{ ATF_POINTER, 4, offsetof(struct IABTNLAddressesRequested, tNLAddressesOrPrefixesRequestedF1_C),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_tNLAddressesOrPrefixesRequestedF1_C_constr_3, &asn_PER_memb_tNLAddressesOrPrefixesRequestedF1_C_constr_3,  memb_tNLAddressesOrPrefixesRequestedF1_C_constraint_1 },
		0, 0, /* No default value */
		"tNLAddressesOrPrefixesRequestedF1-C"
		},
	{ ATF_POINTER, 3, offsetof(struct IABTNLAddressesRequested, tNLAddressesOrPrefixesRequestedF1_U),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_tNLAddressesOrPrefixesRequestedF1_U_constr_4, &asn_PER_memb_tNLAddressesOrPrefixesRequestedF1_U_constr_4,  memb_tNLAddressesOrPrefixesRequestedF1_U_constraint_1 },
		0, 0, /* No default value */
		"tNLAddressesOrPrefixesRequestedF1-U"
		},
	{ ATF_POINTER, 2, offsetof(struct IABTNLAddressesRequested, tNLAddressesOrPrefixesRequestedNoNF1),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_tNLAddressesOrPrefixesRequestedNoNF1_constr_5, &asn_PER_memb_tNLAddressesOrPrefixesRequestedNoNF1_constr_5,  memb_tNLAddressesOrPrefixesRequestedNoNF1_constraint_1 },
		0, 0, /* No default value */
		"tNLAddressesOrPrefixesRequestedNoNF1"
		},
	{ ATF_POINTER, 1, offsetof(struct IABTNLAddressesRequested, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_154P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_IABTNLAddressesRequested_oms_1[] = { 0, 1, 2, 3, 4 };
static const ber_tlv_tag_t asn_DEF_IABTNLAddressesRequested_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_IABTNLAddressesRequested_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* tNLAddressesOrPrefixesRequestedAllTraffic */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* tNLAddressesOrPrefixesRequestedF1-C */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* tNLAddressesOrPrefixesRequestedF1-U */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* tNLAddressesOrPrefixesRequestedNoNF1 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_IABTNLAddressesRequested_specs_1 = {
	sizeof(struct IABTNLAddressesRequested),
	offsetof(struct IABTNLAddressesRequested, _asn_ctx),
	asn_MAP_IABTNLAddressesRequested_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_IABTNLAddressesRequested_oms_1,	/* Optional members */
	5, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_IABTNLAddressesRequested = {
	"IABTNLAddressesRequested",
	"IABTNLAddressesRequested",
	&asn_OP_SEQUENCE,
	asn_DEF_IABTNLAddressesRequested_tags_1,
	sizeof(asn_DEF_IABTNLAddressesRequested_tags_1)
		/sizeof(asn_DEF_IABTNLAddressesRequested_tags_1[0]), /* 1 */
	asn_DEF_IABTNLAddressesRequested_tags_1,	/* Same as above */
	sizeof(asn_DEF_IABTNLAddressesRequested_tags_1)
		/sizeof(asn_DEF_IABTNLAddressesRequested_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_IABTNLAddressesRequested_1,
	5,	/* Elements count */
	&asn_SPC_IABTNLAddressesRequested_specs_1	/* Additional specs */
};

