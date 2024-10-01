//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#pragma once

#include <string>

namespace nr::w_agf::tun
{

int TunAllocate(const char *namePrefix, std::string &allocatedName, std::string &error);
bool TunConfigure(const std::string &tunName, const std::string &ipAddress, int mtu, bool configureRouting, std::string &error);

} // namespace nr::w_agf::tun