//
// Created by Hoonyong Park on 5/25/23.
//

#include "CU/sctpServer/sctp_task.hpp"

namespace nr::CU
{

class SctpServerHandler : public sctp::ISctpHandler
{
  private:
    SctpServerTask *const sctpServerTask;

  public:
    int clientId;

  public:
    SctpServerHandler(SctpServerTask *const sctpServerTask, int clientId) : sctpServerTask(sctpServerTask), clientId(clientId)
    {

    }

  private:
    void onAssociationSetup(int associationId, int inStreams, int outStreams) override
    {
        auto w = std::make_unique<NmCUSctp>(NmCUSctp::ASSOCIATION_SETUP);
        w->clientId = clientId;
        w->associationId = associationId;
        w->inStreams = inStreams;
        w->outStreams = outStreams;
        sctpServerTask->push(std::move(w));
    }

    void onAssociationShutdown() override
    {
        auto w = std::make_unique<NmCUSctp>(NmCUSctp::ASSOCIATION_SHUTDOWN);
        w->clientId = clientId;
        sctpServerTask->push(std::move(w));
    }

    void onMessage(const uint8_t *buffer, size_t length, uint16_t stream) override
    {
        auto *data = new uint8_t[length];
        std::memcpy(data, buffer, length);

        auto w = std::make_unique<NmCUSctp>(NmCUSctp::RECEIVE_MESSAGE);
        w->clientId = clientId;
        w->buffer = UniqueBuffer{data, length};
        w->stream = stream;
        sctpServerTask->push(std::move(w));
    }

    void onUnhandledNotification() override
    {
        auto w = std::make_unique<NmCUSctp>(NmCUSctp::UNHANDLED_NOTIFICATION);
        w->clientId = clientId;
        sctpServerTask->push(std::move(w));
    }

    void onConnectionReset() override
    {
        auto w = std::make_unique<NmCUSctp>(NmCUSctp::UNHANDLED_NOTIFICATION);
        w->clientId = clientId;
        sctpServerTask->push(std::move(w));
    }
};

[[noreturn]] static void ReceiverThread(std::pair<SctpServerTask *, sctp::ISctpHandler *> *args)
{
    SctpServerTask *serverTask = args->first;
    sctp::ISctpHandler *handler = args->second;

    delete args;

    int cfd = (serverTask->GetClient(((SctpServerHandler*)handler)->clientId))->cfd;

    sctp::SctpServer *server = serverTask->GetServer();

    while (true)
        server->receive(cfd, handler);
}

[[noreturn]] static void AccepterThread(SctpServerTask * ServerTask)
{
    SctpServerTask *serverTask = ServerTask;

    while (true)
    {
        int cfd = serverTask->GetServer()->Accept();
        int clientId = ServerTask->AddClient(cfd);
        serverTask->Logging(1, (std::string)"Sctp Connection Request received (ClientId: " + std::to_string(clientId) + (std::string)")");
    }
}

int SctpServerTask::AddClient(int cfd)
{
    ClientSock* clientSock = new ClientSock;
    clientSock->clientId = m_clients.size();
    clientSock->cfd = cfd;
    clientSock->associatedTask = (NtsTask*)m_base->f1apTask;
    clientSock->handler = new SctpServerHandler(this, clientSock->clientId);
    clientSock->receiverThread = new ScopedThread([](void *arg) { ReceiverThread(reinterpret_cast<std::pair<SctpServerTask *, sctp::ISctpHandler *> *>(arg)); },
                                                  new std::pair<SctpServerTask *, sctp::ISctpHandler *>(this, clientSock->handler));

    m_clients[clientSock->clientId] = clientSock;

    return clientSock->clientId;
}

SctpServerTask::ClientSock* SctpServerTask::GetClient(int Id)
{
    return this->m_clients[Id];
}

sctp::SctpServer* SctpServerTask::GetServer()
{
    return this->server;
}

SctpServerTask::SctpServerTask(TaskBase* base): m_base(base), server{}, m_logger{}, m_clients{}, accepterThread{}
{

    server = new sctp::SctpServer(m_base->config->f1apIp.c_str(), m_base->config->f1apPort, (int)sctp::PayloadProtocolId::F1AP);

    accepterThread = new ScopedThread([](void *arg) { AccepterThread(reinterpret_cast<SctpServerTask *>(arg)); }, this);

    m_logger = m_base->logBase->makeUniqueLogger("sctp-server");
}

void SctpServerTask::onStart()
{
    m_logger->info("Trying to start SCTP server... (%s:%d)", m_base->config->f1apIp.c_str(), (int)m_base->config->f1apPort);

}

void SctpServerTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::CU_SCTP: {
        if (typeid(*msg) == typeid(NmCUSctp))
        {
            auto &w = dynamic_cast<NmCUSctp &>(*msg);
            switch (w.present)
            {
                //        case NmCUSctp::CONNECTION_REQUEST: {
                //            receiveSctpConnectionSetupRequest(w.clientId, w.localAddress, w.localPort, w.remoteAddress,
                //                                              w.remotePort, w.ppid, w.associatedTask);
                //            break;
                //        }
            case NmCUSctp::CONNECTION_CLOSE: {
                receiveConnectionClose(w.clientId);
                break;
            }
            case NmCUSctp::ASSOCIATION_SETUP: {
                receiveAssociationSetup(w.clientId, w.associationId, w.inStreams, w.outStreams);
                break;
            }
            case NmCUSctp::ASSOCIATION_SHUTDOWN: {
                receiveAssociationShutdown(w.clientId);
                break;
            }
            case NmCUSctp::RECEIVE_MESSAGE: {
                receiveClientReceive(w.clientId, w.stream, std::move(w.buffer));
                break;
            }
            case NmCUSctp::SEND_MESSAGE: {
                receiveSendMessage(w.clientId, w.stream, std::move(w.buffer));
                break;
            }
            case NmCUSctp::UNHANDLED_NOTIFICATION: {
                receiveUnhandledNotification(w.clientId);
                break;
            }
            default:
                m_logger->unhandledNts(*msg);
                break;
            }
        }
        else
        {
            m_logger->err("%s", typeid(*msg).name());
            m_logger->err("%s", typeid(NmCUSctp).name());
        }

        break;
    }
    default:
        m_logger->unhandledNts(*msg);
        break;
    }
}

void SctpServerTask::onQuit()
{
    delete server;
}

void SctpServerTask::DeleteClientEntry(ClientSock *entry)
{
    entry->associatedTask = nullptr;
    delete entry->receiverThread;
    delete entry->handler;
    delete entry;
}

void SctpServerTask::receiveAssociationSetup(int clientId, int associationId, int inStreams, int outStreams)
{
    m_logger->debug("SCTP association setup ascId[%d]", associationId);

    ClientSock *entry = m_clients[clientId];
    if (entry == nullptr)
    {
        m_logger->warn("Client entry not found for id: %d", clientId);
        return;
    }

    // Notify the relevant task
    auto msg = std::make_unique<NmCUSctp>(NmCUSctp::ASSOCIATION_SETUP);
    msg->clientId = clientId;
    msg->associationId = associationId;
    msg->inStreams = inStreams;
    msg->outStreams = outStreams;
    entry->associatedTask->push(std::move(msg));
}

void SctpServerTask::receiveAssociationShutdown(int clientId)
{
    m_logger->debug("SCTP association shutdown (clientId: %d)", clientId);

    ClientSock *entry = m_clients[clientId];
    if (entry == nullptr)
    {
        m_logger->warn("Client entry not found for id: %d", clientId);
        return;
    }

    // Notify the relevant task
    auto msg = std::make_unique<NmCUSctp>(NmCUSctp::ASSOCIATION_SHUTDOWN);
    msg->clientId = clientId;
    entry->associatedTask->push(std::move(msg));
}

void SctpServerTask::receiveClientReceive(int clientId, uint16_t stream, UniqueBuffer &&buffer)
{
    ClientSock *entry = m_clients[clientId];
    if (entry == nullptr)
    {
        m_logger->warn("Client entry not found for id: %d", clientId);
        return;
    }

    // Notify the relevant task
    auto msg = std::make_unique<NmCUSctp>(NmCUSctp::RECEIVE_MESSAGE);
    msg->clientId = clientId;
    msg->stream = stream;
    msg->buffer = std::move(buffer);
    entry->associatedTask->push(std::move(msg));
}

void SctpServerTask::receiveUnhandledNotification(int clientId)
{
    // NOTE: For unhandled notifications, "clientId" may be invalid for some notifications.
    // Because some notification may be received after shutdown.

    // Print warning
    m_logger->warn("Unhandled SCTP notification received");
}

void SctpServerTask::receiveConnectionClose(int clientId)
{
    ClientSock *entry = m_clients[clientId];
    if (entry == nullptr)
    {
        m_logger->warn("Client entry not found for id: %d", clientId);
        return;
    }

    server->CloseSocket(entry->cfd);
    DeleteClientEntry(entry);
}

void SctpServerTask::receiveSendMessage(int clientId, uint16_t stream, UniqueBuffer &&buffer)
{
    ClientSock *entry = m_clients[clientId];
    if (entry == nullptr)
    {
        m_logger->warn("Client entry not found for id: %d", clientId);
        return;
    }

#ifdef MOCKED_PACKETS
    {
        std::string ss = MOCK_LIST[++MOCK_INDEX];
        OctetString data = OctetString::FromHex(ss);
        auto *copy = new uint8_t[data.length()];
        std::memcpy(copy, data.data(), data.length());
        receiveClientReceive(clientId, 0, copy, data.length());
    }
#else
    server->send(entry->cfd, stream, buffer.data(), 0, buffer.size());
#endif
}

void SctpServerTask::Logging(int type, std::string msg)
{
    if (type == 1) //Info
        m_logger->info(msg);
    else if (type == 2) //Debug
        m_logger->debug(msg);
    else if (type == 3) //Warning
        m_logger->warn(msg);
    else
        m_logger->err(msg);
}

}
