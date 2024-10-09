//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#pragma once

#include <lib/sctp/types.hpp>

#include <string>
#include <unordered_map>


namespace sctp
{

class SctpServer
{
  private:
    int lfd;
    int ppid;



  public:
    SctpServer(const std::string &address, uint16_t port, int ppid);
    ~SctpServer();

    int Accept();
    void CloseSocket(int fd);

    void receive(int cfd, ISctpHandler *handler);

    void send(int cfd, uint16_t stream, const uint8_t *buffer, size_t offset, size_t length);



    // TODO: Other functionalities
};

} // namespace sctp