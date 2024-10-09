/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "RelativeGeodeticLocation.h"

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
memb_deltaLatitude_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -1024 && value <= 1023)) {
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
memb_deltaLongitude_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -1024 && value <= 1023)) {
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
memb_deltaHeight_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -1024 && value <= 1023)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_milli_Arc_SecondUnits_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_heightUnits_constr_7 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_deltaLatitude_constr_12 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11, -1024,  1023 }	/* (-1024..1023) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_deltaLongitude_constr_13 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11, -1024,  1023 }	/* (-1024..1023) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_deltaHeight_constr_14 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11, -1024,  1023 }	/* (-1024..1023) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_milli_Arc_SecondUnits_value2enum_2[] = {
	{ 0,	9,	"zerodot03" },
	{ 1,	8,	"zerodot3" },
	{ 2,	5,	"three" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_milli_Arc_SecondUnits_enum2value_2[] = {
	2,	/* three(2) */
	0,	/* zerodot03(0) */
	1	/* zerodot3(1) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_milli_Arc_SecondUnits_specs_2 = {
	asn_MAP_milli_Arc_SecondUnits_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_milli_Arc_SecondUnits_enum2value_2,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_milli_Arc_SecondUnits_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_milli_Arc_SecondUnits_2 = {
	"milli-Arc-SecondUnits",
	"milli-Arc-SecondUnits",
	&asn_OP_NativeEnumerated,
	asn_DEF_milli_Arc_SecondUnits_tags_2,
	sizeof(asn_DEF_milli_Arc_SecondUnits_tags_2)
		/sizeof(asn_DEF_milli_Arc_SecondUnits_tags_2[0]) - 1, /* 1 */
	asn_DEF_milli_Arc_SecondUnits_tags_2,	/* Same as above */
	sizeof(asn_DEF_milli_Arc_SecondUnits_tags_2)
		/sizeof(asn_DEF_milli_Arc_SecondUnits_tags_2[0]), /* 2 */
	{ 0, &asn_PER_type_milli_Arc_SecondUnits_constr_2, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_milli_Arc_SecondUnits_specs_2	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_heightUnits_value2enum_7[] = {
	{ 0,	2,	"mm" },
	{ 1,	2,	"cm" },
	{ 2,	1,	"m" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_heightUnits_enum2value_7[] = {
	1,	/* cm(1) */
	2,	/* m(2) */
	0	/* mm(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_heightUnits_specs_7 = {
	asn_MAP_heightUnits_value2enum_7,	/* "tag" => N; sorted by tag */
	asn_MAP_heightUnits_enum2value_7,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_heightUnits_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_heightUnits_7 = {
	"heightUnits",
	"heightUnits",
	&asn_OP_NativeEnumerated,
	asn_DEF_heightUnits_tags_7,
	sizeof(asn_DEF_heightUnits_tags_7)
		/sizeof(asn_DEF_heightUnits_tags_7[0]) - 1, /* 1 */
	asn_DEF_heightUnits_tags_7,	/* Same as above */
	sizeof(asn_DEF_heightUnits_tags_7)
		/sizeof(asn_DEF_heightUnits_tags_7[0]), /* 2 */
	{ 0, &asn_PER_type_heightUnits_constr_7, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_heightUnits_specs_7	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_RelativeGeodeticLocation_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RelativeGeodeticLocation, milli_Arc_SecondUnits),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_milli_Arc_SecondUnits_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"milli-Arc-SecondUnits"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RelativeGeodeticLocation, heightUnits),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_heightUnits_7,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"heightUnits"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RelativeGeodeticLocation, deltaLatitude),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_deltaLatitude_constr_12,  memb_deltaLatitude_constraint_1 },
		0, 0, /* No default value */
		"deltaLatitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RelativeGeodeticLocation, deltaLongitude),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_deltaLongitude_constr_13,  memb_deltaLongitude_constraint_1 },
		0, 0, /* No default value */
		"deltaLongitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RelativeGeodeticLocation, deltaHeight),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_deltaHeight_constr_14,  memb_deltaHeight_constraint_1 },
		0, 0, /* No default value */
		"deltaHeight"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RelativeGeodeticLocation, locationUncertainty),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LocationUncertainty,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"locationUncertainty"
		},
	{ ATF_POINTER, 1, offsetof(struct RelativeGeodeticLocation, iE_extensions),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-extensions"
		},
};
static const int asn_MAP_RelativeGeodeticLocation_oms_1[] = { 6 };
static const ber_tlv_tag_t asn_DEF_RelativeGeodeticLocation_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RelativeGeodeticLocation_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* milli-Arc-SecondUnits */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* heightUnits */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* deltaLatitude */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* deltaLongitude */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* deltaHeight */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* locationUncertainty */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* iE-extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_RelativeGeodeticLocation_specs_1 = {
	sizeof(struct RelativeGeodeticLocation),
	offsetof(struct RelativeGeodeticLocation, _asn_ctx),
	asn_MAP_RelativeGeodeticLocation_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_RelativeGeodeticLocation_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RelativeGeodeticLocation = {
	"RelativeGeodeticLocation",
	"RelativeGeodeticLocation",
	&asn_OP_SEQUENCE,
	asn_DEF_RelativeGeodeticLocation_tags_1,
	sizeof(asn_DEF_RelativeGeodeticLocation_tags_1)
		/sizeof(asn_DEF_RelativeGeodeticLocation_tags_1[0]), /* 1 */
	asn_DEF_RelativeGeodeticLocation_tags_1,	/* Same as above */
	sizeof(asn_DEF_RelativeGeodeticLocation_tags_1)
		/sizeof(asn_DEF_RelativeGeodeticLocation_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RelativeGeodeticLocation_1,
	7,	/* Elements count */
	&asn_SPC_RelativeGeodeticLocation_specs_1	/* Additional specs */
};

