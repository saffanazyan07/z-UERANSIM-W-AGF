//
// Created by Hoonyong Park on 5/12/23.
//

#include "encode.hpp"
#include "task.hpp"
#include "utils.hpp"

#include <CU/gtp/task.hpp>
#include <CU/rrc/task.hpp>

#include <asn/ngap/ASN_NGAP_FiveG-S-TMSI.h>
#include <asn/ngap/ASN_NGAP_Paging.h>

namespace nr::CU
{

void NgapTask::handleRadioLinkFailure(int ueId)
{
    // Notify GTP task
    auto w = std::make_unique<NmCUNgapToGtp>(NmCUNgapToGtp::UE_CONTEXT_RELEASE);
    w->ueId = ueId;
    m_base->gtpTask->push(std::move(w));

    // Notify AMF
    sendContextRelease(ueId, NgapCause::RadioNetwork_radio_connection_with_ue_lost);
}

void NgapTask::receivePaging(int amfId, ASN_NGAP_Paging *msg)
{
    m_logger->debug("Paging received");

    auto *amf = findAmfContext(amfId);
    if (amf == nullptr)
        return;

    auto *ieUePagingIdentity = asn::ngap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_UEPagingIdentity);
    auto *ieTaiListForPaging = asn::ngap::GetProtocolIe(msg, ASN_NGAP_ProtocolIE_ID_id_TAIListForPaging);

    if (ieUePagingIdentity == nullptr || ieTaiListForPaging == nullptr ||
        ieUePagingIdentity->UEPagingIdentity.present != ASN_NGAP_UEPagingIdentity_PR_fiveG_S_TMSI)
    {
        m_logger->err("Invalid parameters received in Paging message");
        return;
    }

    auto w = std::make_unique<NmCUNgapToRrc>(NmCUNgapToRrc::PAGING);
    w->uePagingTmsi =
        asn::UniqueCopy(*ieUePagingIdentity->UEPagingIdentity.choice.fiveG_S_TMSI, asn_DEF_ASN_NGAP_FiveG_S_TMSI);
    w->taiListForPaging = asn::UniqueCopy(ieTaiListForPaging->TAIListForPaging, asn_DEF_ASN_NGAP_TAIListForPaging);

    m_base->rrcTask->push(std::move(w));
}

} // namespace nr::CU