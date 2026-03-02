//
// Created by mathieu on 2/18/26.
//

#include "Config.h"

#include <iostream>

Config Config::fromJsonInternal(json j) {
    auto config = Config();

    setField(j, "LogLevel", &config.log_level, spdlog::level::info);
    setField(j, "CurlVerbose", &config.curl_verbose, false);

    for (const auto& value: j["Objects"]) {
        std::cout << value << std::endl;
        config.objects.push_back(Object::fromJson(value));
    }

    spdlog::debug("Finished parsing config");
    return config;
}

void Config::spawnObject(Spawnable *object) {
    object->create();
    object->setup();
    object->deploy();
}

void Config::spawnObjectVec(std::vector<Spawnable *> objects) {
    for (auto& object: objects) {
        this->spawnObject(object);
    }
}
