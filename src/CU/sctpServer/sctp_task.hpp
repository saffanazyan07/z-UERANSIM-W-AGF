//
// Created by Hoonyong Park on 5/25/23.
//

#pragma once

#include "CU/nts.hpp"
#include "CU/types.hpp"
#include "utils/logger.hpp"
#include "utils/nts.hpp"

namespace nr::CU
{

class SctpServerTask : public NtsTask
{
  private:
    struct ClientSock
    {
        int clientId;
        int cfd;
        ScopedThread *receiverThread;
        NtsTask* associatedTask;
        sctp::ISctpHandler *handler;
    };

    TaskBase *m_base;
    sctp::SctpServer *server;
    std::unique_ptr<Logger> m_logger;
    std::unordered_map<int, ClientSock *> m_clients;
    ScopedThread *accepterThread;

    friend class CUCmdHandler;

  public:
    SctpServerTask(TaskBase *m_base);
    ClientSock* GetClient(int);
    sctp::SctpServer* GetServer();
    int AddClient(int cfd);
    void Logging(int type, std::string msg);

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;

  private:
    static void DeleteClientEntry(ClientSock *entry);

  private:
    void receiveSctpConnectionSetupRequest(int clientId, const std::string &localAddress, uint16_t localPort,
                                           const std::string &remoteAddress, uint16_t remotePort,
                                           sctp::PayloadProtocolId ppid, NtsTask *associatedTask);
    void receiveAssociationSetup(int clientId, int associationId, int inStreams, int outStreams);
    void receiveAssociationShutdown(int clientId);
    void receiveClientReceive(int clientId, uint16_t stream, UniqueBuffer &&buffer);
    void receiveUnhandledNotification(int clientId);
    void receiveConnectionClose(int clientId);
    void receiveSendMessage(int clientId, uint16_t stream, UniqueBuffer &&buffer);
};

}

