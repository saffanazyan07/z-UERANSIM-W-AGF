//
// Created by Hoonyong Park on 5/20/23.
// Edited by Zyzy on 9/30/24
//

#include <chrono> //zy
#include <iostream> 
#include <stdexcept>
#include <unordered_map>
#include <thread>

#include <unistd.h>

#include <w_agf/w_agf.hpp> //zy
#include <lib/app/base_app.hpp>
#include <lib/app/cli_base.hpp>
#include <lib/app/cli_cmd.hpp>
#include <lib/app/proc_table.hpp>
#include <lib/app/ue_ctl.hpp> //zy
#include <utils/common.hpp> //zy
#include <utils/concurrent_map.hpp>
#include <utils/constants.hpp>
#include <utils/io.hpp>
#include <utils/options.hpp>
#include <utils/yaml_utils.hpp>
#include <yaml-cpp/yaml.h>

static app::CliServer *g_cliServer = nullptr;
static nr::w_agf::w_agfConfig *g_refConfig = nullptr;
static ConcurrentMap<std::string, nr::w_agf::UserEquipment *> g_ueMap{};
static std::unordered_map<std::string, nr::w_agf::AccessGatewayFunction *> g_w_agfMap{};
static app::CliResponseTask *g_cliRespTask = nullptr;

static struct Options
{
    std::string configFile{};
    bool noRoutingConfigs{};
    bool disableCmd{};
    std::string imsi{};
    int count{};
    int tempo{};
} g_options{};
//zy
static nr::w_agf::w_agfConfig *ReadConfigYaml()
{
    auto *result = new nr::w_agf::w_agfConfig();
    auto config = YAML::LoadFile(g_options.configFile);

    result->plmn.mcc = yaml::GetInt32(config, "mcc", 1, 999);
    yaml::GetString(config, "mcc", 3, 3);
    result->plmn.mnc = yaml::GetInt32(config, "mnc", 0, 999);
    result->plmn.isLongMnc = yaml::GetString(config, "mnc", 2, 3).size() == 3;

    result->nci = yaml::GetInt64(config, "w_agf_ID", 0, 0xFFFFFFFFFll); //w_agf config
    result->DUIdLength = yaml::GetInt32(config, "idLength", 22, 32); //w_agf config
    result->tac = yaml::GetInt32(config, "tac", 0, 0xFFFFFF); 

    result->linkIp = yaml::GetIp(config, "linkIp");
    result->f1apIp = yaml::GetIp(config, "f1apIp");
    result->gtpIp = yaml::GetIp(config, "gtpIp");

    if (yaml::HasField(config, "gtpAdvertiseIp"))
        result->gtpAdvertiseIp = yaml::GetIp(config, "gtpAdvertiseIp");

    result->ignoreStreamIds = yaml::GetBool(config, "ignoreStreamIds");
    result->pagingDrx = EPagingDrx::V128;
    result->name = "UERANSIM-CU-" + std::to_string(result->plmn.mcc) + "-" + std::to_string(result->plmn.mnc) + "-" +
                   std::to_string(result->getDUId()); // NOTE: Avoid using "/" dir separator character.

    for (auto &cuConfig : yaml::GetSequence(config, "cuConfigs"))
    {
        nr::w_agf::DUCUConfig c{};
        c.address = yaml::GetIp(cuConfig, "address");
        c.port = static_cast<uint16_t>(yaml::GetInt32(cuConfig, "port", 1024, 65535));
        result->cuConfigs.push_back(c);
    }

    for (auto &nssai : yaml::GetSequence(config, "slices"))
    {
        SingleSlice s{};
        s.sst = yaml::GetInt32(nssai, "sst", 0, 0xFF);
        if (yaml::HasField(nssai, "sd"))
            s.sd = octet3{yaml::GetInt32(nssai, "sd", 0, 0xFFFFFF)};
        result->nssai.slices.push_back(s);
    }

    return result;
}

static void ReadOptions(int argc, char **argv)
{
    opt::OptionsDescription desc{cons::Project,
                                 cons::Tag,
                                 "5G-SA nr-DU implementation",
                                 cons::Owner,
                                 "nr-DU",
                                 {"-c <config-file> [option...]"},
                                 {},
                                 true,
                                 false};

    opt::OptionItem itemConfigFile = {'c', "config", "Use specified configuration file for nr-DU", "config-file"};
    opt::OptionItem itemDisableCmd = {'l', "disable-cmd", "Disable command line functionality for this instance",
                                      std::nullopt};

    desc.items.push_back(itemConfigFile);
    desc.items.push_back(itemDisableCmd);

    opt::OptionsResult opt{argc, argv, desc, false, nullptr};

    if (opt.hasFlag(itemDisableCmd))
        g_options.disableCmd = true;
    g_options.configFile = opt.getOption(itemConfigFile);

    try
    {
        g_refConfig = ReadConfigYaml();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        exit(1);
    }
}

static void ReceiveCommand(app::CliMessage &msg)
{
    if (msg.value.empty())
    {
        g_cliServer->sendMessage(app::CliMessage::Result(msg.clientAddr, ""));
        return;
    }

    std::vector<std::string> tokens{};

    auto exp = opt::PerformExpansion(msg.value, tokens);
    if (exp != opt::ExpansionResult::SUCCESS)
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, "Invalid command: " + msg.value));
        return;
    }

    if (tokens.empty())
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, "Empty command"));
        return;
    }

    std::string error{}, output{};
    auto cmd = app::ParseDUCliCommand(std::move(tokens), error, output);
    if (!error.empty())
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, error));
        return;
    }
    if (!output.empty())
    {
        g_cliServer->sendMessage(app::CliMessage::Result(msg.clientAddr, output));
        return;
    }
    if (cmd == nullptr)
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, ""));
        return;
    }

    if (g_w_agfMap.count(msg.nodeName) == 0)
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, "Node not found: " + msg.nodeName));
        return;
    }

    //auto *DU = g_w_agfMap[msg.nodeName];
    //DU->pushCommand(std::move(cmd), msg.clientAddr);
}

static void Loop()
{
    if (!g_cliServer)
    {
        ::pause();
        return;
    }

    auto msg = g_cliServer->receiveMessage();
    if (msg.type == app::CliMessage::Type::ECHO)
    {
        g_cliServer->sendMessage(msg);
        return;
    }

    if (msg.type != app::CliMessage::Type::COMMAND)
        return;

    if (msg.value.size() > 0xFFFF)
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, "Command is too large"));
        return;
    }

    if (msg.nodeName.size() > 0xFFFF)
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, "Node name is too large"));
        return;
    }

    ReceiveCommand(msg);
}

int main(int argc, char **argv)
{
    app::Initialize();
    ReadOptions(argc, argv);

    std::cout << cons::Name << std::endl;

    if (!g_options.disableCmd)
    {
        g_cliServer = new app::CliServer{};
        g_cliRespTask = new app::CliResponseTask(g_cliServer);
    }

    auto *DU = new nr::w_agf::AccessGatewayFunction(g_refConfig, nullptr, g_cliRespTask);
    g_w_agfMap[g_refConfig->name] = DU;

    if (!g_options.disableCmd)
    {
        app::CreateProcTable(g_w_agfMap, g_cliServer->assignedAddress().getPort());
        g_cliRespTask->start();
    }

    DU->start();

    while (true)
        Loop();
}
