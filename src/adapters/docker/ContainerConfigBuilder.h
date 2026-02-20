//
// Created by mathieu on 2/4/26.
//

#ifndef CORI_CONTAINERCONFIGBUILDER_H
#define CORI_CONTAINERCONFIGBUILDER_H

#include "PortMapping.h"

#include <nlohmann/json.hpp>

#include "ContainerConfig.h"
using json = nlohmann::json;

class ContainerConfigBuilder {

private:
    ContainerConfig container_config_;

public:
    ContainerConfigBuilder();

    ContainerConfig build();

    ContainerConfigBuilder& setHostName(std::string host_name);
    ContainerConfigBuilder& setDomainName(std::string domain_name);
    ContainerConfigBuilder& setExposedPorts(std::vector<PortMapping> exposed_ports);
    ContainerConfigBuilder& addExposedPort(PortMapping exposed_port);
    ContainerConfigBuilder& setEnv(std::map<std::string, std::string> envs);
    ContainerConfigBuilder& addEnv(std::string key, std::string value);
    ContainerConfigBuilder& setLabels(std::map<std::string, std::string> labels);
    ContainerConfigBuilder& addLabel(std::string key, std::string value);
    ContainerConfigBuilder& setCmd(std::string cmd);
    ContainerConfigBuilder& setImage(std::string image);
    ContainerConfigBuilder& setWorkingDir(std::string working_dir);
    ContainerConfigBuilder& setEntrypoint(std::string entrypoint);
    ContainerConfigBuilder& setOnBuild(std::string on_build);
    ContainerConfigBuilder& setStopSignal(std::string stop_signal);
    ContainerConfigBuilder& setStopTimeout(u_int64_t stop_timeout);
    ContainerConfigBuilder& setShell(std::string shell);
};

#endif