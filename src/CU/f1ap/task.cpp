//
// Created by Hoonyong Park on 5/20/23.
//

#include "task.hpp"

#include <utils/libc_error.hpp>

namespace nr::CU
{

F1apTask::F1apTask(TaskBase *base) : m_base{base}
{
    m_logger = m_base->logBase->makeUniqueLogger("f1ap");
}

void F1apTask::onStart()
{
    m_logger->info("Trying to start SCTP server... (%s:%d)", m_base->config->f1apIp.c_str(), (int)m_base->config->f1apPort);

    try
    {
        m_sctpServer = new SctpServerTask(m_base->config->f1apIp, m_base->config->f1apPort, this);
        m_sctpServer->start();
    }
    catch (const sctp::SctpError &e)
    {
        m_logger->err("F1AP/SCTP task could not be created. %s", e.what());
    }


}

void F1apTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;


}

void F1apTask::onQuit()
{
    m_sctpServer->quit();
    delete m_sctpServer;
}


}