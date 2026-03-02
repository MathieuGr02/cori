//
// Created by mathieu on 3/2/26.
//

#include "Node.h"

Node Node::fromJsonInternal(json j) {
    auto node = Node();

    setField(j, "Host", &node.host);
    setField(j, "Port", &node.port);
    setField(j, "Socket", &node.socket);

    return node;
}

json Node::toJson() {
    json j;

    setJson(j, "Host", &this->host);
    setJson(j, "Port", &this->port);
    setJson(j, "Socket", &this->socket);

    return j;
}
