//
// Created by Hoonyong Park on 6/3/23.
//

#include "task.hpp"

namespace nr::CU
{

std::string F1apTask::decode(const UniqueBuffer &buffer)
{
    char *tmp = new char[buffer.size()];

    for (int i = 0; i < (int)buffer.size(); i++)
    {
        tmp[i] = (buffer.data())[i];
    }

    tmp[buffer.size()] = '\0';

    std::string result(tmp);

    delete tmp;

    return result;
}


}