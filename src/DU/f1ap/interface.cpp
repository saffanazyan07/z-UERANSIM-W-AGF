//
// Created by Hoonyong Park on 5/30/23.
//

#include "task.hpp"
#include "utils.hpp"

//#include <DU/app/task.hpp>
//#include <DU/rrc/task.hpp>
#include <DU/sctp/task.hpp>

#include <asn/f1ap/F1AP-PDU.h>
#include <asn/f1ap/F1SetupRequest.h>
#include <asn/f1ap/InitiatingMessage.h>
#include <asn/f1ap/ProtocolIE-Field.h>
#include <asn/f1ap/TransactionID.h>

namespace nr::DU
{
    void F1apTask::handleAssociationSetup(int ascId, int inCount, int outCount)
    {
        auto *cu = m_cuCtx;
        if (cu != nullptr)
        {
            cu->association.associationId = 0;
            cu->association.inStreams = inCount;
            cu->association.outStreams = outCount;

            sendF1SetupRequest();
        }
    }

    void F1apTask::handleAssociationShutdown()
    {
        auto *cu = m_cuCtx;
        if (cu == nullptr)
            return;

        m_logger->err("Association terminated for CU[%d]", 0);
        m_logger->debug("Removing CU context[%d]", 0);

        cu->state = ECUState::NOT_CONNECTED;

        auto w = std::make_unique<NmDUSctp>(NmDUSctp::CONNECTION_CLOSE);
        w->clientId = 0;
        m_base->sctpTask->push(std::move(w));

        deleteCUContext();
    }

    void F1apTask::sendF1SetupRequest()
    {
        m_logger->debug("Sending F1 Setup Request");

        auto *cu = m_cuCtx;
        if (cu == nullptr)
            return;

        cu->state = ECUState::WAITING_F1_SETUP;

        auto *transcationId = asn::New<TransactionID_t>();
        *transcationId = 1;

        auto *ietTranscationId = asn::New<F1SetupRequestIEs>();





//        auto *pdu = asn::f1ap::NewMessagePdu<F1SetupRequest>(
//            {ieGlobalCUId, ieRanNodeName, ieSupportedTaList, iePagingDrx});

        //sendF1apNonUe(pdu);
    }


}