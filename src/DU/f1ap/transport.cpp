//
// Created by ubuntu on 5/30/23.
//

#include "task.hpp"
#include "encode.hpp"

#include <DU/sctp/task.hpp>
#include <DU/nts.hpp>

#include <asn/f1ap/F1AP-PDU.h>

namespace nr::DU
{

void F1apTask::handleSctpMessage(uint16_t stream, const UniqueBuffer &buffer)
{

}

void F1apTask::sendF1apNonUe(ASN_F1AP_F1AP_PDU *pdu)
{
    auto *cu = m_cuCtx;
    if (cu == nullptr)
    {
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        return;
    }

    char errorBuffer[1024];
    size_t len;

    if (asn_check_constraints(&asn_DEF_F1AP_PDU, pdu, errorBuffer, &len) != 0)
    {
        m_logger->err("F1AP PDU ASN constraint validation failed");
        asn::Free(asn_DEF_F1AP_PDU, pdu);
        return;
    }

    ssize_t encoded;
    uint8_t *buffer;
    if (!f1ap_encode::Encode(asn_DEF_F1AP_PDU, pdu, encoded, buffer))
        m_logger->err("F1AP APER encoding failed");
    else
    {
        auto msg = std::make_unique<NmDUSctp>(NmDUSctp::SEND_MESSAGE);
        msg->clientId = 0;
        msg->stream = 0;
        msg->buffer = UniqueBuffer{buffer, static_cast<size_t>(encoded)};
        m_base->sctpTask->push(std::move(msg));

        if (m_base->nodeListener)
        {
            std::string xer = f1ap_encode::EncodeXer(asn_DEF_F1AP_PDU, pdu);
            if (xer.length() > 0)
            {
                m_base->nodeListener->onSend(app::NodeType::DU, m_base->config->name, app::NodeType::CU, cu->CUName,
                                             app::ConnectionType::F1AP, xer);
            }
        }
    }

    asn::Free(asn_DEF_F1AP_PDU, pdu);
}

}