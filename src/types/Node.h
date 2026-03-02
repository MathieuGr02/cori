//
// Created by mathieu on 3/2/26.
//

#ifndef CORI_NODE_H
#define CORI_NODE_H
#include <optional>
#include <string>

#include "../util/JsonDeserializable.h"
#include "../util/JsonSerializable.h"


class Node:
    public JsonDeserializable<Node>,
    public JsonSerializable
{
public:
    std::optional<std::string> host;
    std::optional<__uint16_t> port;
    std::optional<std::string> socket;

    Node() {}

    static Node fromJsonInternal(json j);
    json toJson() override;
};


#endif //CORI_NODE_H