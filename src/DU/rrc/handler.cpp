//
// Created by Hoonyong Park on 6/3/23.
//

#include "task.hpp"

#include <lib/rrc/encode.hpp>

#include <asn/rrc/ASN_RRC_DL-CCCH-Message.h>
#include <asn/rrc/ASN_RRC_DL-DCCH-Message.h>
#include <asn/rrc/ASN_RRC_RRCSetup-IEs.h>
#include <asn/rrc/ASN_RRC_RRCSetup.h>
#include <asn/rrc/ASN_RRC_CellGroupConfig.h>

using namespace std;

namespace nr::DU
{



void DURrcTask::releaseConnection(int ueId)
{
    /*m_logger->info("Releasing RRC connection for UE[%d]", ueId);

    // Send RRC Release message
    auto *pdu = asn::New<ASN_RRC_DL_DCCH_Message>();
    pdu->message.present = ASN_RRC_DL_DCCH_MessageType_PR_c1;
    pdu->message.choice.c1 = asn::NewFor(pdu->message.choice.c1);
    pdu->message.choice.c1->present = ASN_RRC_DL_DCCH_MessageType__c1_PR_rrcRelease;
    auto &rrcRelease = pdu->message.choice.c1->choice.rrcRelease = asn::New<ASN_RRC_RRCRelease>();
    rrcRelease->rrc_TransactionIdentifier = getNextTid();
    rrcRelease->criticalExtensions.present = ASN_RRC_RRCRelease__criticalExtensions_PR_rrcRelease;
    rrcRelease->criticalExtensions.choice.rrcRelease = asn::New<ASN_RRC_RRCRelease_IEs>();

    sendRrcMessage(ueId, pdu);
    asn::Free(asn_DEF_ASN_RRC_DL_DCCH_Message, pdu);

    // Delete UE RRC context
    m_ueCtx.erase(ueId);*/
}

void DURrcTask::handleDownlinkRrcTransfer(vector<string> msg)
{
    if (msg.at(1) == "DL_CCCH")
    {
        handleDLCCCHMessage(vector<string>(msg.begin() + 2, msg.begin() + msg.size()));
    }
    else if (msg.at(1) == "DL_DCCH")
    {
        handleDLDCCHMessage(vector<string>(msg.begin() + 2, msg.begin() + msg.size() + 1));
    }
}

void DURrcTask::handleDLCCCHMessage(vector<string> msg)
{
    auto ue = findUe(stoi(msg.at(1)));
    if (ue == nullptr)
    {
        return;
    }

    if (msg.front() == "RRCSetup")
    {
        sendRRCSetup(msg);
    }
}
void DURrcTask::handleDLDCCHMessage(vector<string> msg)
{

}

void DURrcTask::sendRRCSetup(std::vector<std::string> msg)
{
    int ueId = stoi(msg.at(1));
    auto *pdu = asn::New<ASN_RRC_DL_CCCH_Message>();
    pdu->message.present = ASN_RRC_DL_CCCH_MessageType_PR_c1;
    pdu->message.choice.c1 = asn::NewFor(pdu->message.choice.c1);
    pdu->message.choice.c1->present = ASN_RRC_DL_CCCH_MessageType__c1_PR_rrcSetup;
    auto &rrcSetup = pdu->message.choice.c1->choice.rrcSetup = asn::New<ASN_RRC_RRCSetup>();
    rrcSetup->rrc_TransactionIdentifier = stoi(msg.at(2));
    rrcSetup->criticalExtensions.present = ASN_RRC_RRCSetup__criticalExtensions_PR_rrcSetup;
    auto &rrcSetupIEs = rrcSetup->criticalExtensions.choice.rrcSetup = asn::New<ASN_RRC_RRCSetup_IEs>();

    ASN_RRC_CellGroupConfig masterCellGroup{};
    masterCellGroup.cellGroupId = 0;

    asn::SetOctetString(rrcSetupIEs->masterCellGroup,
                        rrc::encode::EncodeS(asn_DEF_ASN_RRC_CellGroupConfig, &masterCellGroup));



    sendRrcMessage(ueId, pdu);
    asn::Free(asn_DEF_ASN_RRC_DL_CCCH_Message, pdu);
}




}