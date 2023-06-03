//
// Created by ubuntu on 5/30/23.
//

#include "task.hpp"

#include <DU/sctp/task.hpp>
#include <DU/nts.hpp>

#include <sstream>

using namespace std;

namespace nr::DU
{

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}


void F1apTask::handleSctpMessage(uint16_t stream, const UniqueBuffer &buffer)
{
    auto pdu = decode(buffer);
    if (pdu == "")
    {
        m_logger->err("Decoding failed for SCTP message");
        //sendErrorIndication(amfId, NgapCause::Protocol_transfer_syntax_error);
        return;
    }
    else
        m_logger->debug("Received From CU :%s", pdu.c_str());

    vector<string> msg = split(pdu, '|');

    if (msg.front() == "F1SetupResponse")
    {
        m_logger->debug("F1 Setup Response received From CU");
        receiveF1SetupResponse();
    }
}

void F1apTask::sendF1apNonUe(std::string *pdu)
{
    auto *cu = m_cuCtx;
    if (cu == nullptr)
    {
        delete pdu;
        return;
    }

    auto buffer = pdu->c_str();
    auto msg = std::make_unique<NmDUSctp>(NmDUSctp::SEND_MESSAGE);
    msg->clientId = 0;
    msg->stream = 0;
    msg->buffer = UniqueBuffer{(uint8_t *)buffer, pdu->length()};
    m_base->sctpTask->push(std::move(msg));

    if (m_base->nodeListener)
    {
        if ((*pdu).length() > 0)
        {
            m_base->nodeListener->onSend(app::NodeType::DU, m_base->config->name, app::NodeType::CU, cu->CUName,
                                         app::ConnectionType::F1AP, *pdu);
        }
    }


    //delete pdu;
}

}