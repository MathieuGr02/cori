//
// Created by mathieu on 1/29/26.
//

#ifndef CORI_CONTAINER_H
#define CORI_CONTAINER_H
#include <string>

#include <nlohmann/json.hpp>

#include "ContainerConfig.h"
#include "../../util/JsonDeserializable.h"
using json = nlohmann::json;

class ContainerInstance : public JsonDeserializable<ContainerInstance> {
public:
    std::string id;
    ContainerConfig config;

public:
    ContainerInstance();

    static ContainerInstance fromJsonInternal(json json);
};


#endif //CORI_CONTAINER_H