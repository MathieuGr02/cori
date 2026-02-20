//
// Created by mathieu on 2/5/26.
//

#include "ContainerConfig.h"

#include <iostream>
#include <sys/syslog.h>

#include "PortMapping.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/chrono.h"

json ContainerConfig::toJson() {
    json j;

    spdlog::debug("Parsing ContainerConfig to JSON");

    if (this->hostName.has_value()) { j["Hostname"] = this->hostName.value(); }

    if (this->domainName) { j["Domainname"] = this->domainName.value(); }

    if (this->user) { j["User"] = this->user.value(); }

    if (this->exposedPorts.has_value()) {
        for (auto &port: this->exposedPorts.value()) {
            std::string string_port = port.toString();

            j["ExposedPorts"][string_port] = json({});
        }
    }
    if (this->env) {
        std::vector<std::string> envs;
        for (std::map<std::string, std::string>::iterator it = this->env->begin(); it != this->env->end(); ++it) {
            envs.push_back(std::format("{}={}", it->first, it->second));
        }
        j["Env"] = envs;
    }

    if (this->cmd) { j["Cmd"] = this->cmd.value(); }

    if (this->image) { j["Image"] = this->image.value(); }

    if (this->workingDir) { j["WorkingDir"] = this->workingDir.value(); }

    if (this->entrypoint) { j["Entrypoint"] = this->entrypoint.value(); }

    if (this->networkDisabled) { j["NetworkDisabled"] = this->networkDisabled.value(); }

    if (this->onBuild) { j["OnBuild"] = this->onBuild.value(); }

    if (this->stopSignal) { j["StopSignal"] = this->stopSignal.value(); }

    if (this->stopTimeout) { j["StopTimeout"] = this->stopTimeout.value(); }

    if (this->shell) { j["Shell"] = this->shell.value(); }

    return j;
}

ContainerConfig ContainerConfig::fromJsonInternal(json j) {
    spdlog::debug("Parsing JSON to ContainerConfig");

    ContainerConfig config = ContainerConfig();
    config.hostName = j["Hostname"];
    config.domainName = j["Domainname"];
    config.user = j["User"];
    //config.exposedPorts = j["ExposedPorts"];
    //config.env = j["Env"];

    LOG_DEBUG

    if (j["Cmd"] != nullptr) {
        config.cmd = j["Cmd"];
    }
    else {
        config.cmd = std::nullopt;
    }

    config.image = j["Image"];
    config.workingDir = j["WorkingDir"];

    if (j["Entrypoint"] != nullptr) {
        config.entrypoint = j["Entrypoint"];
    }
    else {
        config.entrypoint = std::nullopt;
    }

    if (j["NetworkDisabled"] != nullptr) {
        config.networkDisabled = j["NetworkDisabled"];
    }
    else {
        config.networkDisabled = std::nullopt;
    }

    if (j["Labels"] != nullptr) {
        config.labels = j["Labels"];
    }
    else {
        config.labels = std::nullopt;
    }

    if (j["OnBuild"] != nullptr) {
        config.onBuild = j["ObBuild"];
    }
    else {
        config.onBuild = {};
    }

    if (j["Shell"] != nullptr) {
        config.shell = j["Shell"];
    }
    else {
        config.shell = {};
    }

    if (!j["StopSignal"].empty()) {
        config.stopSignal = j["StopSignal"];
    }

    config.stopTimeout = j["StopTimeout"];

    return config;
}
