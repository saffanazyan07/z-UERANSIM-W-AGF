/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-PDU-Contents"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#include "PositioningMeasurementFailureIndication.h"

asn_TYPE_member_t asn_MBR_PositioningMeasurementFailureIndication_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PositioningMeasurementFailureIndication, protocolIEs),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_Container_10639P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"protocolIEs"
		},
};
static const ber_tlv_tag_t asn_DEF_PositioningMeasurementFailureIndication_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PositioningMeasurementFailureIndication_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* protocolIEs */
};
asn_SEQUENCE_specifics_t asn_SPC_PositioningMeasurementFailureIndication_specs_1 = {
	sizeof(struct PositioningMeasurementFailureIndication),
	offsetof(struct PositioningMeasurementFailureIndication, _asn_ctx),
	asn_MAP_PositioningMeasurementFailureIndication_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PositioningMeasurementFailureIndication = {
	"PositioningMeasurementFailureIndication",
	"PositioningMeasurementFailureIndication",
	&asn_OP_SEQUENCE,
	asn_DEF_PositioningMeasurementFailureIndication_tags_1,
	sizeof(asn_DEF_PositioningMeasurementFailureIndication_tags_1)
		/sizeof(asn_DEF_PositioningMeasurementFailureIndication_tags_1[0]), /* 1 */
	asn_DEF_PositioningMeasurementFailureIndication_tags_1,	/* Same as above */
	sizeof(asn_DEF_PositioningMeasurementFailureIndication_tags_1)
		/sizeof(asn_DEF_PositioningMeasurementFailureIndication_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PositioningMeasurementFailureIndication_1,
	1,	/* Elements count */
	&asn_SPC_PositioningMeasurementFailureIndication_specs_1	/* Additional specs */
};

