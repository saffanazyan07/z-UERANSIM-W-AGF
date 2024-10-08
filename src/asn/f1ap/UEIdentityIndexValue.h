/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D ../src/asn/f1ap/`
 */

#ifndef	_UEIdentityIndexValue_H_
#define	_UEIdentityIndexValue_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UEIdentityIndexValue_PR {
	UEIdentityIndexValue_PR_NOTHING,	/* No components present */
	UEIdentityIndexValue_PR_indexLength10,
	UEIdentityIndexValue_PR_choice_extension
} UEIdentityIndexValue_PR;

/* Forward declarations */
struct ProtocolIE_SingleContainer;

/* UEIdentityIndexValue */
typedef struct UEIdentityIndexValue {
	UEIdentityIndexValue_PR present;
	union UEIdentityIndexValue_u {
		BIT_STRING_t	 indexLength10;
		struct ProtocolIE_SingleContainer	*choice_extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UEIdentityIndexValue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UEIdentityIndexValue;

#ifdef __cplusplus
}
#endif

#endif	/* _UEIdentityIndexValue_H_ */
#include <asn_internal.h>
