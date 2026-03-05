//
// Created by mathieu on 3/2/26.
//

#ifndef CORI_PORTBINDING_H
#define CORI_PORTBINDING_H
#include <cstdint>

#include "TransportLayerProtocols.h"


class PortBinding:
    public JsonDeserializable<PortBinding>,
    public JsonSerializable
{
    PortBinding();
    PortBinding(uint16_t port, TransportLayerProtocol protocol = TransportLayerProtocol::TCP, std::optional<uint16_t> hostPort = std::nullopt, std::optional<std::string> hostIp = std::nullopt);

    uint16_t port;
    TransportLayerProtocol transport_layer_protocol_ = TransportLayerProtocol::TCP;
    std::optional<uint16_t> hostPort;
    std::optional<std::string> hostIp;

    static PortBinding fromJsonInternal(json j);
    json toJson() override;
};


#endif //CORI_PORTBINDING_H