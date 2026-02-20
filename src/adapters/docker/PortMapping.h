//
// Created by mathieu on 2/3/26.
//

#ifndef CORI_PORTS_H
#define CORI_PORTS_H
#include <string>
#include <nlohmann/json.hpp>

#include "TransportLayerProtocols.h"
#include "../Builder.h"
#include "../util/JsonDeserializable.h"
#include "../util/JsonSerializable.h"

using json = nlohmann::json;


class PortMapping:
    public JsonDeserializable<PortMapping>,
    public JsonSerializable
{
public:
    std::optional<std::string> IP;
    uint32_t privatePort;
    std::optional<u_int32_t> publicPort;
    TransportLayerProtocol type;

    PortMapping(
        uint32_t privatePort,
        std::optional<uint32_t> publicPort = std::nullopt,
        const std::optional<std::string>& IP = "localhost",
        const TransportLayerProtocol& type = TransportLayerProtocol::TCP
        );

    static PortMapping fromJsonInternal(json json);
    json toJson() override;

    std::string toString();
};

#endif //CORI_PORTS_H