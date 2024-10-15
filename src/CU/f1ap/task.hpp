//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include "CU/sctpServer/sctp_task.hpp"

#include <CU/nts.hpp>
#include <CU/types.hpp>
#include <lib/app/monitor.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::CU
{

class F1apTask : public NtsTask
{
  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;
    std::unordered_map<int, F1apDuContext *> m_duCtx;


    friend class CUCmdHandler;

  public:
    explicit F1apTask(TaskBase *base);
    ~F1apTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;

  private:
    /* Utility functions */
    void createDuContext(int ctxId, int duId/*, int cellId */);
    F1apDuContext* findDuContext(int ctxId);
    std::string decode(const UniqueBuffer &buffer);
    void deleteDuContext(int duId);
    std::vector<std::string> split(std::string input, char delimiter);
    std::string Merge(std::vector<std::string> vec);

    /* Interface management */
    void handleAssociationSetup(int cuId, int inCount, int outCount);
    void handleAssociationShutdown(int duId);
    void receiveF1SetupRequest(int duId, int gNB_DU_ID /*, int cellId */);
    void sendF1SetupResponse(int duId);
    void sendDLRrcMessageTransfer(int duId, rrc::RrcChannel rrcChannel, std::string msg);

    /* Message transport */
    void handleSctpMessage(int duId, uint16_t stream, const UniqueBuffer &buffer);
    void sendF1ap(int duId, std::string *pdu);

    /* RRC Message Handling */
    void receiveRrc_UL_CCCH_Message(int duId, std::string pdu);
    void receiveRrc_UL_DCCH_Message(int duId, std::string pdu);

};
}