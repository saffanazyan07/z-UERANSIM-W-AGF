//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "server.hpp"
#include "internal.hpp"
#include <string.h>

#define RECEIVE_BUFFER_SIZE 8192u

namespace sctp
{

SctpServer::SctpServer(const std::string &address, uint16_t port, int ppid) : lfd(0), ppid(ppid)
{
    try
    {
        lfd = CreateSocket();
        BindSocket(lfd, address, port);
        SetInitOptions(lfd, 64, 64, 64, 10 * 1000);
        // SetEventOptions(sd);
        StartListening(lfd);
    }
    catch (const SctpError &e)
    {
        CloseSocket(lfd);
        throw;
    }
}

SctpServer::~SctpServer()
{
    CloseSocket(lfd);
}

int SctpServer::Accept()
{
    int cfd = sctp::Accept(lfd);

    SetEventOptions(cfd);

    return cfd;
}
void SctpServer::CloseSocket(int fd)
{
    sctp::CloseSocket(fd);
}

void SctpServer::send(int cfd, uint16_t stream, const uint8_t *buffer, size_t offset, size_t length)
{
    SendMessage(cfd, buffer + offset, length, static_cast<uint32_t>(ppid), stream);
}

void SctpServer::receive(int cfd, ISctpHandler *handler)
{
    ReceiveMessage(cfd, static_cast<uint32_t>(ppid), handler);
}

}