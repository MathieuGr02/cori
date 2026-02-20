//
// Created by mathieu on 2/5/26.
//

#include "TransportLayerProtocols.h"

TransportLayerProtocol::TransportLayerProtocol(Enum value) {
    this->value = value;
}

std::string TransportLayerProtocol::toString() {
    switch (this->value) {
        case TCP:
            return "tcp";
        case UDP:
            return "udp";
        case SCTP:
            return "sctp";
    }
}

TransportLayerProtocol TransportLayerProtocol::fromString(const std::string &s) {
    // TODO: FOR INVALID STRING
    if (s == "tcp") { return TCP; }
    if (s == "udp") { return UDP; }
    if (s == "sctp") { return SCTP; }
}

TransportLayerProtocol TransportLayerProtocol::fromJsonInternal(json j) {
    return fromString(j["Type"]);
}

json TransportLayerProtocol::toJson() {
    return this->toString();
}
