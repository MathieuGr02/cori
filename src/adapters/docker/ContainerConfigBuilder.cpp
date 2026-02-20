//
// Created by mathieu on 2/4/26.
//

#include "ContainerConfigBuilder.h"

#include <iostream>

#include "../util/util.h"

ContainerConfigBuilder::ContainerConfigBuilder() {}

ContainerConfig ContainerConfigBuilder::build() {
    return this->container_config_;
}

ContainerConfigBuilder& ContainerConfigBuilder::setHostName(std::string host_name) {
    this->container_config_.hostName = host_name;
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setDomainName(std::string domain_name) {
    this->container_config_.domainName = domain_name;
    return *this;
}

ContainerConfigBuilder &ContainerConfigBuilder::setExposedPorts(std::vector<PortMapping> exposed_ports) {
    this->container_config_.exposedPorts = exposed_ports;
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::addExposedPort(PortMapping exposed_port) {
    if (this->container_config_.exposedPorts.has_value()) {
        this->container_config_.exposedPorts.value().push_back(exposed_port);
    }
    else {
        this->container_config_.exposedPorts = { exposed_port };
    }
    return *this;
}

ContainerConfigBuilder &ContainerConfigBuilder::setEnv(std::map<std::string, std::string> envs) {
    this->container_config_.env = envs;
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::addEnv(std::string key, std::string value) {
    if (this->container_config_.env.has_value()) {
        this->container_config_.env.value()[key] = value;
    }
    else {
        this->container_config_.env = std::map<std::string, std::string>{{key, value}};
    }
    return *this;
}

ContainerConfigBuilder &ContainerConfigBuilder::setLabels(std::map<std::string, std::string> labels) {
    this->container_config_.labels = labels;
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::addLabel(std::string key, std::string value) {
    if (this->container_config_.labels.has_value()) {
        this->container_config_.labels.value()[key] = value;
    }
    else {
        this->container_config_.labels = std::map<std::string, std::string>{{key, value}};
    }
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setCmd(std::string cmd) {
    this->container_config_.cmd = split(cmd, " ");
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setImage(std::string image) {
    this->container_config_.image = image;
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setWorkingDir(std::string working_dir) {
    this->container_config_.workingDir = working_dir;
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setEntrypoint(std::string entrypoint) {
    this->container_config_.entrypoint = split(entrypoint, " ");
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setOnBuild(std::string on_build) {
    this->container_config_.onBuild = split(on_build, " ");
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setStopSignal(std::string stop_signal) {
    this->container_config_.stopSignal = stop_signal;
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setStopTimeout(u_int64_t stop_timeout) {
    this->container_config_.stopTimeout = stop_timeout;
    return *this;
}

ContainerConfigBuilder& ContainerConfigBuilder::setShell(std::string shell) {
    this->container_config_.shell = split(shell, " ");
    return *this;
}