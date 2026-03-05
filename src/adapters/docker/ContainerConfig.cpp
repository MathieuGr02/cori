//
// Created by mathieu on 2/5/26.
//

#include "ContainerConfig.h"

#include <iostream>
#include <sys/syslog.h>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/chrono.h"

json ContainerConfig::toJson() {
    json j;

    spdlog::trace("Parsing ContainerConfig to Json");

    j = setJson(j, "Hostname", &this->hostName);
    j = setJson(j, "Domainname", &this->domainName);
    j = setJson(j, "User", &this->user);

    /*
    if (this->exposedPorts.has_value()) {
        for (auto &port: this->exposedPorts.value()) {
            std::string string_port = port.toString();

            j["ExposedPorts"][string_port] = json({});
        }
    }
    */

    j = setJson(j, "Env", &this->env);
    j = setJson(j, "Cmd", &this->cmd);
    j = setJson(j, "Image", &this->image);
    j = setJson(j, "WorkingDir", &this->workingDir);
    j = setJson(j, "Entrypoint", &this->entrypoint);
    j = setJson(j, "NetworkDisabled", &this->networkDisabled);
    j = setJson(j, "OnBuild", &this->onBuild);
    j = setJson(j, "StopSignal", &this->stopSignal);
    j = setJson(j, "StopTimeout", &this->stopTimeout);
    j = setJson(j, "Shell", &this->shell);
    j = setJson(j, "StopTimeout", &this->stopTimeout);

    if (this->hostConfig) {
        j["HostConfig"] = this->hostConfig.value().toJson();
    }

    if (this->volumes) {
        for (const auto& volume: this->volumes.value()) {
            j["Volumes"][volume] = json::object();
        }
    }

    if (!this->networks.empty()) {
        for (auto network: this->networks) {
            if (network.second) {
                j["NetworkingConfig"]["EndpointsConfig"][network.first] = network.second.value().toJson();
            }
            else {
                j["NetworkingConfig"]["EndpointsConfig"][network.first] = json::object();
            }
        }
    }

    j = setJson(j, "AttachStderr", &this->attachStderr);
    j = setJson(j, "AttachStdin", &this->attachStdin);
    j = setJson(j, "AttachStdout", &this->attachStdout);

    spdlog::trace("Finished parsing ContainerConfig to Json");

    return j;
}

ContainerConfig ContainerConfig::fromJsonInternal(json j) {
    spdlog::trace("Parsing Json to ContainerConfig");

    ContainerConfig config = ContainerConfig();

    setField(j, "Name", &config.name);
    setField(j, "Platform", &config.platform);
    setField(j, "Hostname", &config.hostName);
    setField(j, "Domainname", &config.domainName);
    setField(j, "User", &config.user);
    setField(j, "Image", &config.image);
    setField(j, "WorkingDir", &config.workingDir);
    //setField(j, "HostConfig", &config.hostConfig);

    if (j.contains("HostConfig")) {
        config.hostConfig = HostConfig::fromJson(j["HostConfig"]);
    }

    //cFieldg.exposedPorts = j["ExposedPorts"];
    setField(j, "Env", &config.env);
    setField(j, "Cmd", &config.cmd);
    setField(j, "Entrypoint", &config.entrypoint);
    setField(j, "NetworkDisabled", &config.networkDisabled);
    setField(j, "Labels", &config.labels);
    setField(j, "OnBuild", &config.onBuild);
    setField(j, "Shell", &config.shell);
    setField(j, "StopSignal", &config.stopSignal);
    setField(j, "StopTimeout", &config.stopTimeout);

    spdlog::trace("Finished parsing Json to ContainerConfig");

    return config;
}
