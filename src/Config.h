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

    std::vector<Object> objects = {};

    void spawnObject(Spawnable* object);
    void spawnObjectVec(std::vector<Spawnable*> objects);
};


#endif //CORI_CONFIG_H