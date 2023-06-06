//
// Created by Hoonyong Park on 6/4/23.
//

#include "task.hpp"

#include <CU/rrc/task.hpp>

using namespace std;

namespace nr::CU
{

void F1apTask::receiveRrc_UL_CCCH_Message(int duId, std::string pdu)
{
    auto *du = findDuContext(duId);
    if (du == nullptr)
        return;

    auto w = std::make_unique<NmCUF1apToRrc>(NmCUF1apToRrc::RECEIVE_CCCH_Message);
    w->duId = duId;
    w->gNB_DU_ID = du->gNB_DU_ID;
    w->data = pdu;
    m_base->rrcTask->push(std::move(w));
}

void F1apTask::receiveRrc_UL_DCCH_Message(int duId, std::string pdu)
{
    auto *du = findDuContext(duId);
    if (du == nullptr)
        return;

    auto w = std::make_unique<NmCUF1apToRrc>(NmCUF1apToRrc::RECEIVE_DCCH_Message);
    w->duId = duId;
    w->gNB_DU_ID = du->gNB_DU_ID;
    w->data = pdu;
    m_base->rrcTask->push(std::move(w));
}

}
