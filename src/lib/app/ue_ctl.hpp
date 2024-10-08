//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#pragma once

namespace nr::w_agf
{

class UserEquipment;

}

namespace app
{

class IUeController
{
  public:
    virtual void performSwitchOff(nr::w_agf::UserEquipment *ue) = 0;
};

} // namespace app
