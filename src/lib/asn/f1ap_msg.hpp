//
// Created by Hoonyong Park on 5/31/23.
//

#pragma once

#include <type_traits>

extern "C"
{
    struct F1AP_PDU;
    struct InitiatingMessage;
    struct SuccessfulOutcome;
    struct UnsuccessfulOutcome;


    struct F1Reset;
    struct F1ResetAcknowledge;
    struct F1SetupFailure;
    struct F1SetupRequest;
    struct F1SetupResponse;
}

namespace asn::f1ap
{

enum class F1apMessageType
{
    F1Reset,
    F1ResetAcknowledge,
    F1SetupFailure,
    F1SetupRequest,
    F1SetupResponse,
};

template <F1apMessageType T>
struct F1apMessageEnumToType
{
};

template <>
struct F1apMessageEnumToType<F1apMessageType::F1Reset>
{
    typedef F1Reset T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::F1ResetAcknowledge>
{
    typedef F1ResetAcknowledge T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::F1SetupFailure>
{
    typedef F1SetupFailure T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::F1SetupRequest>
{
    typedef F1SetupRequest T;
};
template <>
struct F1apMessageEnumToType<F1apMessageType::F1SetupResponse>
{
    typedef F1SetupResponse T;
};

template <typename T>
struct F1apMessageTypeToEnum;

template <>
struct F1apMessageTypeToEnum<F1Reset>
{
    enum
    {
        V = (int)F1apMessageType::F1Reset
    };
};
template <>
struct F1apMessageTypeToEnum<F1ResetAcknowledge>
{
    enum
    {
        V = (int)F1apMessageType::F1ResetAcknowledge
    };
};
template <>
struct F1apMessageTypeToEnum<F1SetupFailure>
{
    enum
    {
        V = (int)F1apMessageType::F1SetupFailure
    };
};
template <>
struct F1apMessageTypeToEnum<F1SetupRequest>
{
    enum
    {
        V = (int)F1apMessageType::F1SetupRequest
    };
};
template <>
struct F1apMessageTypeToEnum<F1SetupResponse>
{
    enum
    {
        V = (int)F1apMessageType::F1SetupResponse
    };
};

template <typename T>
struct F1apMessageToIeType
{
    typedef typename std::remove_reference<decltype(*T{}.protocolIEs.list.array[0])>::type value;
};

template <typename T>
struct F1apMessageToIeUnionType
{
    typedef decltype(typename F1apMessageToIeType<T>::value{}.value.choice) value;
};



}