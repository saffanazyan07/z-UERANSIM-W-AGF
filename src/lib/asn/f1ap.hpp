//
// Created by Hoonyong Park on 5/31/23.
//

#pragma once

#include "f1ap_msg.hpp"

#include <algorithm>
#include <exception>
#include <functional>
#include <vector>

#include <asn_SEQUENCE_OF.h>
#include <asn_application.h>

namespace asn::f1ap
{

F1AP_PDU *F1apPduFromPduDescription(InitiatingMessage *desc);
F1AP_PDU *F1apPduFromPduDescription(SuccessfulOutcome *desc);
F1AP_PDU *F1apPduFromPduDescription(UnsuccessfulOutcome *desc);

int GetPduDescription(F1apMessageType messageType);
int GetProcedureCode(F1apMessageType messageType);
int GetProcedureCriticality(F1apMessageType messageType);
int GetProcedurePresent(F1apMessageType messageType);

void *NewDescFromMessageType(F1apMessageType type, void *&pOutDescription);

template <typename TMessage>
inline void AddProtocolIe(TMessage &msg, typename F1apMessageToIeType<TMessage>::value *element)
{
    ASN_SEQUENCE_ADD(&msg.protocolIEs.list, element);

    // Protocol IE fields must be sorted according to ASN definition order.
    // Using 'present' here because it is consistent with ASN definition order;
    // This is not a constant-time operation.
    std::stable_sort(
        msg.protocolIEs.list.array, msg.protocolIEs.list.array + msg.protocolIEs.list.count,
        [](typename F1apMessageToIeType<TMessage>::value *a, typename F1apMessageToIeType<TMessage>::value *b) {
            return a->value.present < b->value.present;
        });
}

template <typename T>
inline F1AP_PDU *NewMessagePdu(std::vector<typename F1apMessageToIeType<T>::value *> ies)
{
    auto msgType = static_cast<F1apMessageType>(F1apMessageTypeToEnum<T>::V);

    void *pDescription = nullptr;
    void *pMessage = NewDescFromMessageType(msgType, pDescription);

    for (auto &ie : ies)
        AddProtocolIe(*reinterpret_cast<T *>(pMessage), ie);

    int desc = GetPduDescription(msgType);
    switch (desc)
    {
    case 0:
        return F1apPduFromPduDescription(reinterpret_cast<InitiatingMessage *>(pDescription));
    case 1:
        return F1apPduFromPduDescription(reinterpret_cast<SuccessfulOutcome *>(pDescription));
    case 2:
        return F1apPduFromPduDescription(reinterpret_cast<UnsuccessfulOutcome *>(pDescription));
    default:
        std::terminate();
    }
}

template <typename T>
inline typename asn::f1ap::F1apMessageToIeUnionType<T>::value *GetProtocolIe(T *msg, int id, int order = 0)
{
    int found = -1;

    for (int i = 0; i < msg->protocolIEs.list.count; i++)
    {
        auto &item = msg->protocolIEs.list.array[i];
        if (item->id == id)
        {
            found++;
            if (order == found)
                return (typename asn::f1ap::F1apMessageToIeUnionType<T>::value *)(&item->value.choice);
        }
    }

    return nullptr;
}

bool IsProtocolIeUsable(const F1AP_PDU &pdu, const asn_TYPE_descriptor_t &ieType);

void *FindProtocolIeInPdu(const F1AP_PDU &pdu, const asn_TYPE_descriptor_t &ieType, int protocolIeId);

bool AddProtocolIeIfUsable(const F1AP_PDU &pdu, const asn_TYPE_descriptor_t &ieType, int protocolIeId,
                           int criticality, const std::function<void(void *)> &ieCreator);

} // namespace asn::f1ap