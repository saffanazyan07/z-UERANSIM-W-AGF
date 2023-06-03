//
// Created by Hoonyong Park on 5/25/23.
//

#pragma once

#include <DU/nts.hpp>
#include <DU/types.hpp>


extern "C"
{
    struct ASN_F1AP_F1AP_PDU;
}

namespace nr::DU
{

class SctpTask;

class F1apTask : public NtsTask
{

  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;

    F1apCUContext *m_cuCtx;
    int cellId = 0;

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
    void createCUContext(const DUCUConfig &config);
    void deleteCUContext();
    std::string decode(const UniqueBuffer &buffer);


    /* Interface management */
    void handleAssociationSetup(int ascId, int inCount, int outCount);
    void handleAssociationShutdown();
    void sendF1SetupRequest();
    void receiveF1SetupResponse();

    /* Message transport */
    void handleSctpMessage(uint16_t stream, const UniqueBuffer &buffer);
    //void sendF1apNonUe(ASN_F1AP_F1AP_PDU *pdu);
    void sendF1apNonUe(std::string *pdu);

};

}
