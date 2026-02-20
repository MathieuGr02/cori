//
// Created by mathieu on 2/5/26.
//

#ifndef CORI_TRANSPORTLAYERPROTOCOLS_H
#define CORI_TRANSPORTLAYERPROTOCOLS_H
#include <algorithm>
#include <string>
#include <nlohmann/detail/macro_scope.hpp>

#include "../util/JsonDeserializable.h"
#include "../util/JsonSerializable.h"

class TransportLayerProtocol:
    public JsonDeserializable<TransportLayerProtocol>,
    public JsonSerializable
{
public:
    enum Enum {
        TCP,
        UDP,
        SCTP
    };

    Enum value;

    TransportLayerProtocol(Enum value);

    static TransportLayerProtocol fromJsonInternal(json j);
    json toJson() override;
    std::string toString();
    static TransportLayerProtocol fromString(const std::string &s);
};

#endif //CORI_TRANSPORTLAYERPROTOCOLS_H