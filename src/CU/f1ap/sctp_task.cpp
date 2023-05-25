//
// Created by Hoonyong Park on 5/25/23.
//

#include "sctp_task.hpp"

namespace nr::CU
{

SctpServerTask::SctpServerTask(const std::string &address, uint16_t port, NtsTask *targetTask): targetTask(targetTask), server{}
{
    server = new sctp::SctpServer(address, port);
    server->start();
}

void SctpServerTask::onStart()
{

}

void SctpServerTask::onLoop()
{

}

void SctpServerTask::onQuit()
{
    delete server;
}



}
