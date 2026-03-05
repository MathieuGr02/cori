//
// Created by mathieu on 2/18/26.
//

#ifndef CORI_CONFIG_H
#define CORI_CONFIG_H

#include "spdlog/common.h"
#include "types/Object.h"
#include "util/JsonDeserializable.h"

class Config:
    public JsonDeserializable<Config>
{

public:
    static Config fromJsonInternal(json j);

    spdlog::level::level_enum log_level;
    bool curl_verbose;
    std::optional<std::string> docker_api_version;

    std::vector<Object> components = {};

    void spawnComponent(Object* component);
    void spawnComponentsVec();
};


#endif //CORI_CONFIG_H