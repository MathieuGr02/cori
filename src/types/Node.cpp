//
// Created by mathieu on 3/2/26.
//

#include "Node.h"

Node Node::fromJsonInternal(json j) {
    spdlog::trace("Parsing Json to Node");

    auto node = Node();

    setField(j, "Host", &node.host);
    setField(j, "Port", &node.port);
    setField(j, "Socket", &node.socket);

    spdlog::trace("Finished parsing Json to Node");

    return node;
}

json Node::toJson() {
    spdlog::trace("Parsing Node to Json");

    json j;

    setJson(j, "Host", &this->host);
    setJson(j, "Port", &this->port);
    setJson(j, "Socket", &this->socket);

    spdlog::trace("Finished parsing Node to Json");

    return j;
}
