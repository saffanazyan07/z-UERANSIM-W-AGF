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

}

void F1apTask::onLoop()
{

}

void F1apTask::onQuit()
{
    m_sctpServer->quit();
    delete m_sctpServer;
}


}