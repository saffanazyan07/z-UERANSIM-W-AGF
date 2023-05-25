//
// Created by Hoonyong Park on 5/25/23.
//

#include <CU/nts.hpp>
#include <CU/types.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::CU
{

class SctpServerTask : public NtsTask
{
  private:
    NtsTask *targetTask;
    sctp::SctpServer *server;

    friend class CUCmdHandler;

  public:
    SctpServerTask(const std::string &address, uint16_t port, NtsTask *targetTask);

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;


};

}

