//
// Created by Hoonyong Park on 6/3/23.
//

#include "task.hpp"

#include <DU/f1ap/task.hpp>
#include <lib/rrc/encode.hpp>

#include <asn/ngap/ASN_NGAP_FiveG-S-TMSI.h>
#include <asn/rrc/ASN_RRC_BCCH-BCH-Message.h>
#include <asn/rrc/ASN_RRC_BCCH-DL-SCH-Message.h>
#include <asn/rrc/ASN_RRC_CellGroupConfig.h>
#include <asn/rrc/ASN_RRC_DL-CCCH-Message.h>
#include <asn/rrc/ASN_RRC_DL-DCCH-Message.h>
#include <asn/rrc/ASN_RRC_DLInformationTransfer-IEs.h>
#include <asn/rrc/ASN_RRC_DLInformationTransfer.h>
#include <asn/rrc/ASN_RRC_PCCH-Message.h>
#include <asn/rrc/ASN_RRC_Paging.h>
#include <asn/rrc/ASN_RRC_PagingRecord.h>
#include <asn/rrc/ASN_RRC_PagingRecordList.h>
#include <asn/rrc/ASN_RRC_RRCRelease-IEs.h>
#include <asn/rrc/ASN_RRC_RRCRelease.h>
#include <asn/rrc/ASN_RRC_RRCSetup-IEs.h>
#include <asn/rrc/ASN_RRC_RRCSetup.h>
#include <asn/rrc/ASN_RRC_RRCSetupComplete-IEs.h>
#include <asn/rrc/ASN_RRC_RRCSetupComplete.h>
#include <asn/rrc/ASN_RRC_RRCSetupRequest.h>
#include <asn/rrc/ASN_RRC_UL-CCCH-Message.h>
#include <asn/rrc/ASN_RRC_UL-CCCH1-Message.h>
#include <asn/rrc/ASN_RRC_UL-DCCH-Message.h>
#include <asn/rrc/ASN_RRC_ULInformationTransfer-IEs.h>
#include <asn/rrc/ASN_RRC_ULInformationTransfer.h>

namespace nr::w_agf
{

void DURrcTask::receiveRrcSetupRequest(int ueId, const ASN_RRC_RRCSetupRequest &msg)
{
    auto *ue = tryFindUe(ueId);
    if (ue)
    {
        // TODO: handle this more properly
        m_logger->warn("Discarding RRC Setup Request, UE context already exists");
        return;
    }

    if (msg.rrcSetupRequest.ue_Identity.present == ASN_RRC_InitialUE_Identity_PR_NOTHING)
    {
        m_logger->err("Bad constructed RRC message ignored");
        return;
    }

    std::string buffer = "RRCSetupRequest|" + std::to_string(ueId) + "|";
    ue = createUe(ueId);

    if (msg.rrcSetupRequest.ue_Identity.present == ASN_RRC_InitialUE_Identity_PR_ng_5G_S_TMSI_Part1)
    {
        ue->initialId = asn::GetBitStringLong<39>(msg.rrcSetupRequest.ue_Identity.choice.ng_5G_S_TMSI_Part1);
        ue->isInitialIdSTmsi = true;
        buffer = buffer + "TRUE|" + std::to_string(ue->initialId) + "|";
    }
    else
    {
        ue->initialId = asn::GetBitStringLong<39>(msg.rrcSetupRequest.ue_Identity.choice.randomValue);
        ue->isInitialIdSTmsi = false;
        buffer = buffer + "FALSE|" + std::to_string(ue->initialId) + "|";
    }

    ue->establishmentCause = static_cast<int64_t>(msg.rrcSetupRequest.establishmentCause);
    buffer = buffer + std::to_string(ue->establishmentCause);

    auto msg1 = std::make_unique<NmDURrcToF1ap>(NmDURrcToF1ap::UL_RRC_TRANSFER);
    msg1->rrcChannel = rrc::RrcChannel::UL_CCCH;
    msg1->buffer = buffer;
    m_base->f1apTask->push(std::move(msg1));
}

void DURrcTask::receiveRrcSetupComplete(int ueId, const ASN_RRC_RRCSetupComplete &msg)
{
    auto *ue = findUe(ueId);
    if (!ue)
        return;

    auto setupComplete = msg.criticalExtensions.choice.rrcSetupComplete;

    std::string buffer = "RRCSetupComplete|" + std::to_string(ueId) + "|";

    if (msg.criticalExtensions.choice.rrcSetupComplete)
    {
        // Handle received 5G S-TMSI if any
        if (msg.criticalExtensions.choice.rrcSetupComplete->ng_5G_S_TMSI_Value)
        {
            ue->sTmsi = std::nullopt;

            auto &sTmsiValue = msg.criticalExtensions.choice.rrcSetupComplete->ng_5G_S_TMSI_Value;
            if (sTmsiValue->present == ASN_RRC_RRCSetupComplete_IEs__ng_5G_S_TMSI_Value_PR_ng_5G_S_TMSI)
            {
                ue->sTmsi = GutiMobileIdentity::FromSTmsi(asn::GetBitStringLong<48>(sTmsiValue->choice.ng_5G_S_TMSI));
            }
            else if (sTmsiValue->present == ASN_RRC_RRCSetupComplete_IEs__ng_5G_S_TMSI_Value_PR_ng_5G_S_TMSI_Part2)
            {
                if (ue->isInitialIdSTmsi)
                {
                    int64_t part2 = asn::GetBitStringLong<9>(sTmsiValue->choice.ng_5G_S_TMSI_Part2);
                    ue->sTmsi = GutiMobileIdentity::FromSTmsi((part2 << 39) | (ue->initialId));
                }
            }
        }
    }

    auto w = std::make_unique<NmDURrcToF1ap>(NmDURrcToF1ap::INITIAL_NAS_DELIVERY);
    w->ueId = ueId;
    w->pdu = asn::GetOctetString(setupComplete->dedicatedNAS_Message);
    w->rrcEstablishmentCause = ue->establishmentCause;
    w->sTmsi = ue->sTmsi;

    m_base->f1apTask->push(std::move(w));
}



}