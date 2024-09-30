//
// Created by Hoonyong Park on 5/20/23.
//

#pragma once

#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>

#include <DU/nts.hpp>
#include <lib/sctp/sctp.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>
#include <utils/scoped_thread.hpp>

namespace nr::DU
{

class SctpTask : public NtsTask
{
  private:
    struct ClientEntry
    {
        int id;
        sctp::SctpClient *client;
        ScopedThread *receiverThread;
        sctp::ISctpHandler *handler;
        NtsTask *associatedTask;
    };

  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;
    std::unordered_map<int, ClientEntry *> m_clients;

    friend class DUCmdHandler;

  public:
    explicit SctpTask(TaskBase *base);
    ~SctpTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;

  private:
    static void DeleteClientEntry(ClientEntry *entry);

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
    void receiveSendMessage2(int clientId, uint16_t stream, OctetString buffer);
};

} // namespace nr::DU