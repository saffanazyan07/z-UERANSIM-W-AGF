//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "task.hpp"

#include <sstream>

namespace nr::CU
{

int CURrcTask::getNextTid()
{
    m_tidCounter++;
    m_tidCounter %= 4;
    return m_tidCounter;
}

std::vector<std::string> CURrcTask::split(std::string input, char delimiter)
{
    std::vector<std::string> answer;
    std::stringstream ss(input);
    std::string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}

std::string CURrcTask::Merge(std::vector<std::string> vec)
{
    std::string result = "";

    for (std::string &s : vec)
    {
        result = result + s + "|";
    }

    result = result.substr(0, result.length() - 1);

    return result;
}

} // namespace nr::CU