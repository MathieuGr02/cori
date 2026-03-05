//
// Created by mathieu on 2/18/26.
//

#include "Config.h"

#include <iostream>

Config Config::fromJsonInternal(json j) {
    spdlog::trace("Parsing Json to Config");

    auto config = Config();

    if (j.contains("LogLevel")) {
        std::string level = j["LogLevel"];
        std::transform(level.begin(), level.end(), level.begin(),
            [](unsigned char c){ return std::tolower(c); });

        if (level == "trace") {
            config.log_level = spdlog::level::trace;
        }
        else if (level == "debug") {
            config.log_level = spdlog::level::debug;
        }
        else if (level == "info") {
            config.log_level = spdlog::level::info;
        }
        else if (level == "warn") {
            config.log_level = spdlog::level::warn;
        }
        else if (level == "error") {
            config.log_level = spdlog::level::err;
        }
        else if (level == "critical") {
            config.log_level = spdlog::level::critical;
        }
        else if (level == "off") {
            config.log_level = spdlog::level::off;
        }
    }

    setField(j, "CurlVerbose", &config.curl_verbose, false);
    setField(j, "DockerAPIVersion", &config.docker_api_version);

    for (const auto& value: j["Objects"]) {
        auto object = Object::fromJson(value);

        if (config.docker_api_version.has_value()) {
            object.docker.setVersion(config.docker_api_version.value());
        }

        config.components.push_back(object);

    }

    spdlog::trace("Finished parsing Json to Config");

    return config;
}

void Config::spawnComponent(Object* component) {
    component->create();
    component->setup();
    component->deploy();
}

void Config::spawnComponentsVec() {
    spdlog::debug("Spawning vector of components");
    for (auto& object: this->components) {
        this->spawnComponent(&object);
    }
}
