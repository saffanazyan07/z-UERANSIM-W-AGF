//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "task.hpp"

#include <CU/ngap/task.hpp>
#include <CU/f1ap/task.hpp>
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

using namespace std;

namespace nr::CU
{

void CURrcTask::receiveRrcSetupRequest(int duId, int gNB_DU_ID, string data)
{
    auto msg = split(data, '|');

    auto *ue = createUe(m_ueCtx.size());

    ue->gNB_DU_ID = stoi(msg.at(1));

    if (msg.at(2) == "TRUE")
    {
        ue->initialId = stoll(msg.at(3));
        ue->isInitialIdSTmsi = true;
    }
    else
    {
        ue->initialId = stoll(msg.at(3));
        ue->isInitialIdSTmsi = false;
    }

    ue->establishmentCause = stoll(msg.at(4));

    // Prepare RRC Setup
    m_logger->info("RRC Setup for UE[%d]", ue->ueId);

    string pdu = "RRCSetup|" + to_string(ue->gNB_DU_ID) + "|" + to_string(getNextTid());

    auto w = std::make_unique<NmCURrcToF1ap>(NmCURrcToF1ap::SEND_MESSAGE2);
    w->duId = duId;
    w->rrcChannel = rrc::RrcChannel::DL_CCCH;
    w->data = pdu;
    m_base->f1apTask->push(std::move(w));

    /*auto *pdu = asn::New<ASN_RRC_DL_CCCH_Message>();
    pdu->message.present = ASN_RRC_DL_CCCH_MessageType_PR_c1;
    pdu->message.choice.c1 = asn::NewFor(pdu->message.choice.c1);
    pdu->message.choice.c1->present = ASN_RRC_DL_CCCH_MessageType__c1_PR_rrcSetup;
    auto &rrcSetup = pdu->message.choice.c1->choice.rrcSetup = asn::New<ASN_RRC_RRCSetup>();
    rrcSetup->rrc_TransactionIdentifier = getNextTid();
    rrcSetup->criticalExtensions.present = ASN_RRC_RRCSetup__criticalExtensions_PR_rrcSetup;
    auto &rrcSetupIEs = rrcSetup->criticalExtensions.choice.rrcSetup = asn::New<ASN_RRC_RRCSetup_IEs>();

    ASN_RRC_CellGroupConfig masterCellGroup{};
    masterCellGroup.cellGroupId = 0;

    asn::SetOctetString(rrcSetupIEs->masterCellGroup,
                        rrc::encode::EncodeS(asn_DEF_ASN_RRC_CellGroupConfig, &masterCellGroup));



    sendRrcMessage(ueId, pdu);
    asn::Free(asn_DEF_ASN_RRC_DL_CCCH_Message, pdu);*/
}

//void CURrcTask::receiveRrcSetupComplete(int ueId, const ASN_RRC_RRCSetupComplete &msg)
//{
//    auto *ue = findUe(ueId);
//    if (!ue)
//        return;
//
//    auto setupComplete = msg.criticalExtensions.choice.rrcSetupComplete;
//
//    if (msg.criticalExtensions.choice.rrcSetupComplete)
//    {
//        // Handle received 5G S-TMSI if any
//        if (msg.criticalExtensions.choice.rrcSetupComplete->ng_5G_S_TMSI_Value)
//        {
//            ue->sTmsi = std::nullopt;
//
//            auto &sTmsiValue = msg.criticalExtensions.choice.rrcSetupComplete->ng_5G_S_TMSI_Value;
//            if (sTmsiValue->present == ASN_RRC_RRCSetupComplete_IEs__ng_5G_S_TMSI_Value_PR_ng_5G_S_TMSI)
//            {
//                ue->sTmsi = GutiMobileIdentity::FromSTmsi(asn::GetBitStringLong<48>(sTmsiValue->choice.ng_5G_S_TMSI));
//            }
//            else if (sTmsiValue->present == ASN_RRC_RRCSetupComplete_IEs__ng_5G_S_TMSI_Value_PR_ng_5G_S_TMSI_Part2)
//            {
//                if (ue->isInitialIdSTmsi)
//                {
//                    int64_t part2 = asn::GetBitStringLong<9>(sTmsiValue->choice.ng_5G_S_TMSI_Part2);
//                    ue->sTmsi = GutiMobileIdentity::FromSTmsi((part2 << 39) | (ue->initialId));
//                }
//            }
//        }
//    }
//
//    auto w = std::make_unique<NmCURrcToNgap>(NmCURrcToNgap::INITIAL_NAS_DELIVERY);
//    w->ueId = ueId;
//    w->pdu = asn::GetOctetString(setupComplete->dedicatedNAS_Message);
//    w->rrcEstablishmentCause = ue->establishmentCause;
//    w->sTmsi = ue->sTmsi;
//
//    m_base->ngapTask->push(std::move(w));
//}

} // namespace nr::CU