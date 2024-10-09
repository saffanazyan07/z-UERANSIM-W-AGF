/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "PosSRSResource-Item.h"

#include "SpatialRelationPos.h"
#include "ProtocolExtensionContainer.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_startPosition_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 13)) {
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
memb_freqDomainShift_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 268)) {
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
memb_c_SRS_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 63)) {
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
memb_sequenceId_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_nrofSymbols_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  4 }	/* (0..4) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_groupOrSequenceHopping_constr_13 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_startPosition_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  13 }	/* (0..13) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_freqDomainShift_constr_11 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 9,  9,  0,  268 }	/* (0..268) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_c_SRS_constr_12 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 6,  6,  0,  63 }	/* (0..63) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_sequenceId_constr_18 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 16,  16,  0,  65535 }	/* (0..65535) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_nrofSymbols_value2enum_5[] = {
	{ 0,	2,	"n1" },
	{ 1,	2,	"n2" },
	{ 2,	2,	"n4" },
	{ 3,	2,	"n8" },
	{ 4,	3,	"n12" }
};
static const unsigned int asn_MAP_nrofSymbols_enum2value_5[] = {
	0,	/* n1(0) */
	4,	/* n12(4) */
	1,	/* n2(1) */
	2,	/* n4(2) */
	3	/* n8(3) */
};
static const asn_INTEGER_specifics_t asn_SPC_nrofSymbols_specs_5 = {
	asn_MAP_nrofSymbols_value2enum_5,	/* "tag" => N; sorted by tag */
	asn_MAP_nrofSymbols_enum2value_5,	/* N => "tag"; sorted by N */
	5,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_nrofSymbols_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_nrofSymbols_5 = {
	"nrofSymbols",
	"nrofSymbols",
	&asn_OP_NativeEnumerated,
	asn_DEF_nrofSymbols_tags_5,
	sizeof(asn_DEF_nrofSymbols_tags_5)
		/sizeof(asn_DEF_nrofSymbols_tags_5[0]) - 1, /* 1 */
	asn_DEF_nrofSymbols_tags_5,	/* Same as above */
	sizeof(asn_DEF_nrofSymbols_tags_5)
		/sizeof(asn_DEF_nrofSymbols_tags_5[0]), /* 2 */
	{ 0, &asn_PER_type_nrofSymbols_constr_5, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_nrofSymbols_specs_5	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_groupOrSequenceHopping_value2enum_13[] = {
	{ 0,	7,	"neither" },
	{ 1,	12,	"groupHopping" },
	{ 2,	15,	"sequenceHopping" }
};
static const unsigned int asn_MAP_groupOrSequenceHopping_enum2value_13[] = {
	1,	/* groupHopping(1) */
	0,	/* neither(0) */
	2	/* sequenceHopping(2) */
};
static const asn_INTEGER_specifics_t asn_SPC_groupOrSequenceHopping_specs_13 = {
	asn_MAP_groupOrSequenceHopping_value2enum_13,	/* "tag" => N; sorted by tag */
	asn_MAP_groupOrSequenceHopping_enum2value_13,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_groupOrSequenceHopping_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_groupOrSequenceHopping_13 = {
	"groupOrSequenceHopping",
	"groupOrSequenceHopping",
	&asn_OP_NativeEnumerated,
	asn_DEF_groupOrSequenceHopping_tags_13,
	sizeof(asn_DEF_groupOrSequenceHopping_tags_13)
		/sizeof(asn_DEF_groupOrSequenceHopping_tags_13[0]) - 1, /* 1 */
	asn_DEF_groupOrSequenceHopping_tags_13,	/* Same as above */
	sizeof(asn_DEF_groupOrSequenceHopping_tags_13)
		/sizeof(asn_DEF_groupOrSequenceHopping_tags_13[0]), /* 2 */
	{ 0, &asn_PER_type_groupOrSequenceHopping_constr_13, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_groupOrSequenceHopping_specs_13	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_PosSRSResource_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, srs_PosResourceId),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SRSPosResourceID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"srs-PosResourceId"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, transmissionCombPos),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_TransmissionCombPos,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"transmissionCombPos"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, startPosition),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_startPosition_constr_4,  memb_startPosition_constraint_1 },
		0, 0, /* No default value */
		"startPosition"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, nrofSymbols),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_nrofSymbols_5,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nrofSymbols"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, freqDomainShift),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_freqDomainShift_constr_11,  memb_freqDomainShift_constraint_1 },
		0, 0, /* No default value */
		"freqDomainShift"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, c_SRS),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_c_SRS_constr_12,  memb_c_SRS_constraint_1 },
		0, 0, /* No default value */
		"c-SRS"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, groupOrSequenceHopping),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_groupOrSequenceHopping_13,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"groupOrSequenceHopping"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, resourceTypePos),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_ResourceTypePos,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"resourceTypePos"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosSRSResource_Item, sequenceId),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_sequenceId_constr_18,  memb_sequenceId_constraint_1 },
		0, 0, /* No default value */
		"sequenceId"
		},
	{ ATF_POINTER, 2, offsetof(struct PosSRSResource_Item, spatialRelationPos),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_SpatialRelationPos,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"spatialRelationPos"
		},
	{ ATF_POINTER, 1, offsetof(struct PosSRSResource_Item, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_PosSRSResource_Item_oms_1[] = { 9, 10 };
static const ber_tlv_tag_t asn_DEF_PosSRSResource_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PosSRSResource_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* srs-PosResourceId */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* transmissionCombPos */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* startPosition */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* nrofSymbols */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* freqDomainShift */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* c-SRS */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* groupOrSequenceHopping */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* resourceTypePos */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* sequenceId */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* spatialRelationPos */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_PosSRSResource_Item_specs_1 = {
	sizeof(struct PosSRSResource_Item),
	offsetof(struct PosSRSResource_Item, _asn_ctx),
	asn_MAP_PosSRSResource_Item_tag2el_1,
	11,	/* Count of tags in the map */
	asn_MAP_PosSRSResource_Item_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PosSRSResource_Item = {
	"PosSRSResource-Item",
	"PosSRSResource-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_PosSRSResource_Item_tags_1,
	sizeof(asn_DEF_PosSRSResource_Item_tags_1)
		/sizeof(asn_DEF_PosSRSResource_Item_tags_1[0]), /* 1 */
	asn_DEF_PosSRSResource_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_PosSRSResource_Item_tags_1)
		/sizeof(asn_DEF_PosSRSResource_Item_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PosSRSResource_Item_1,
	11,	/* Elements count */
	&asn_SPC_PosSRSResource_Item_specs_1	/* Additional specs */
};

