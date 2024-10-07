/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "TransmissionComb.h"

#include "ProtocolIE-SingleContainer.h"
static int
memb_combOffset_n2_constraint_2(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 1)) {
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
memb_cyclicShift_n2_constraint_2(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 7)) {
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
memb_combOffset_n4_constraint_5(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 3)) {
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
memb_cyclicShift_n4_constraint_5(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 11)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_combOffset_n2_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_cyclicShift_n2_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  7 }	/* (0..7) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_combOffset_n4_constr_6 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_cyclicShift_n4_constr_7 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  11 }	/* (0..11) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_per_constraints_t asn_PER_type_TransmissionComb_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_n2_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TransmissionComb__n2, combOffset_n2),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_combOffset_n2_constr_3,  memb_combOffset_n2_constraint_2 },
		0, 0, /* No default value */
		"combOffset-n2"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct TransmissionComb__n2, cyclicShift_n2),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_cyclicShift_n2_constr_4,  memb_cyclicShift_n2_constraint_2 },
		0, 0, /* No default value */
		"cyclicShift-n2"
		},
};
static const ber_tlv_tag_t asn_DEF_n2_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_n2_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* combOffset-n2 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* cyclicShift-n2 */
};
static asn_SEQUENCE_specifics_t asn_SPC_n2_specs_2 = {
	sizeof(struct TransmissionComb__n2),
	offsetof(struct TransmissionComb__n2, _asn_ctx),
	asn_MAP_n2_tag2el_2,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_n2_2 = {
	"n2",
	"n2",
	&asn_OP_SEQUENCE,
	asn_DEF_n2_tags_2,
	sizeof(asn_DEF_n2_tags_2)
		/sizeof(asn_DEF_n2_tags_2[0]) - 1, /* 1 */
	asn_DEF_n2_tags_2,	/* Same as above */
	sizeof(asn_DEF_n2_tags_2)
		/sizeof(asn_DEF_n2_tags_2[0]), /* 2 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_n2_2,
	2,	/* Elements count */
	&asn_SPC_n2_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_n4_5[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TransmissionComb__n4, combOffset_n4),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_combOffset_n4_constr_6,  memb_combOffset_n4_constraint_5 },
		0, 0, /* No default value */
		"combOffset-n4"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct TransmissionComb__n4, cyclicShift_n4),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_cyclicShift_n4_constr_7,  memb_cyclicShift_n4_constraint_5 },
		0, 0, /* No default value */
		"cyclicShift-n4"
		},
};
static const ber_tlv_tag_t asn_DEF_n4_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_n4_tag2el_5[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* combOffset-n4 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* cyclicShift-n4 */
};
static asn_SEQUENCE_specifics_t asn_SPC_n4_specs_5 = {
	sizeof(struct TransmissionComb__n4),
	offsetof(struct TransmissionComb__n4, _asn_ctx),
	asn_MAP_n4_tag2el_5,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_n4_5 = {
	"n4",
	"n4",
	&asn_OP_SEQUENCE,
	asn_DEF_n4_tags_5,
	sizeof(asn_DEF_n4_tags_5)
		/sizeof(asn_DEF_n4_tags_5[0]) - 1, /* 1 */
	asn_DEF_n4_tags_5,	/* Same as above */
	sizeof(asn_DEF_n4_tags_5)
		/sizeof(asn_DEF_n4_tags_5[0]), /* 2 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_n4_5,
	2,	/* Elements count */
	&asn_SPC_n4_specs_5	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_TransmissionComb_1[] = {
	{ ATF_POINTER, 0, offsetof(struct TransmissionComb, choice.n2),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_n2_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"n2"
		},
	{ ATF_POINTER, 0, offsetof(struct TransmissionComb, choice.n4),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_n4_5,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"n4"
		},
	{ ATF_POINTER, 0, offsetof(struct TransmissionComb, choice.choice_extension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_SingleContainer_10642P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choice-extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_TransmissionComb_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* n2 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* n4 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* choice-extension */
};
asn_CHOICE_specifics_t asn_SPC_TransmissionComb_specs_1 = {
	sizeof(struct TransmissionComb),
	offsetof(struct TransmissionComb, _asn_ctx),
	offsetof(struct TransmissionComb, present),
	sizeof(((struct TransmissionComb *)0)->present),
	asn_MAP_TransmissionComb_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_TransmissionComb = {
	"TransmissionComb",
	"TransmissionComb",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_TransmissionComb_constr_1, CHOICE_constraint },
	asn_MBR_TransmissionComb_1,
	3,	/* Elements count */
	&asn_SPC_TransmissionComb_specs_1	/* Additional specs */
};

