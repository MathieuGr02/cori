//
// Created by mathieu on 2/3/26.
//

#include "PortMapping.h"

#include <format>

#include "spdlog/fmt/fmt.h"

PortMapping::PortMapping(const uint32_t privatePort, const std::optional<uint32_t> publicPort, const std::optional<std::string>& IP, const TransportLayerProtocol& type) : type(TransportLayerProtocol::TCP) {
    this->IP = IP;
    this->privatePort = privatePort;
    this->publicPort = publicPort;
    this->type = type;
}

PortMapping PortMapping::fromJsonInternal(json json) {
    auto port_mapping = PortMapping(
        json["PrivatePort"],
        json["PublicPort"],
        json["IP"],
        TransportLayerProtocol::fromJson(json)
        );
    return port_mapping;
}

json PortMapping::toJson() {
    json j;
    j["IP"] = this->IP.value();
    j["PrivatePort"] = this->privatePort;
    j["PublicPort"] = this->publicPort.value();
    j["type"] = this->type.toString();
    return j;
}

std::string PortMapping::toString() {
    if (publicPort.has_value()) {
        return std::format("{}:{}/{}", publicPort.value(), privatePort, type.toString());
    }
    return std::format("{}/{}", privatePort, type.toString());
}
