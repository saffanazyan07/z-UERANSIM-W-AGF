//
// Created by Hpoonyong Park on 6/3/23.
//

#pragma once

#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>

#include <DU/nts.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::DU
{

extern "C"
{
    struct ASN_RRC_BCCH_BCH_Message;
    struct ASN_RRC_BCCH_DL_SCH_Message;
    struct ASN_RRC_DL_CCCH_Message;
    struct ASN_RRC_DL_DCCH_Message;
    struct ASN_RRC_PCCH_Message;
    struct ASN_RRC_UL_CCCH_Message;
    struct ASN_RRC_UL_CCCH1_Message;
    struct ASN_RRC_UL_DCCH_Message;

    struct ASN_RRC_RRCSetupRequest;
    struct ASN_RRC_RRCSetupComplete;
    struct ASN_RRC_ULInformationTransfer;
}

class DURrcTask : public NtsTask
{
  private:
    TaskBase *m_base;
    DUConfig *m_config;
    std::unique_ptr<Logger> m_logger;

    std::unordered_map<int, RrcUeContext *> m_ueCtx;
    bool m_isBarred = true;
    bool m_cellReserved = false;
    UacAiBarringSet m_aiBarringSet = {};
    bool m_intraFreqReselectAllowed = true;

    friend class CUCmdHandler;

  public:
    explicit DURrcTask(TaskBase *base);
    ~DURrcTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;

  private:

    /* RRC channel send message */
    void sendRrcMessage(ASN_RRC_BCCH_BCH_Message *msg);
    void sendRrcMessage(ASN_RRC_BCCH_DL_SCH_Message *msg);
    void sendRrcMessage(int ueId, ASN_RRC_DL_CCCH_Message *msg);
    void sendRrcMessage(int ueId, ASN_RRC_DL_DCCH_Message *msg);
    void sendRrcMessage(ASN_RRC_PCCH_Message *msg);

    /* RRC channel receive message */
    void receiveRrcMessage(int ueId, ASN_RRC_BCCH_BCH_Message *msg);
    void receiveRrcMessage(int ueId, ASN_RRC_UL_CCCH_Message *msg);
    void receiveRrcMessage(int ueId, ASN_RRC_UL_CCCH1_Message *msg);
    void receiveRrcMessage(int ueId, ASN_RRC_UL_DCCH_Message *msg);

    /* System Information Broadcast related */
    void onBroadcastTimerExpired();
    void triggerSysInfoBroadcast();




};

}