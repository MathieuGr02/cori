#include <fstream>
#include <curl/curl.h>

#include "spdlog/spdlog.h"
#include "src/Config.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#define DEBUG true

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    spdlog::set_level(spdlog::level::trace);
    spdlog::info("Reading config file");

    std::ifstream f("config.json");

    json data = json::parse(std::ifstream("config.json"));

    spdlog::info("Parsing config json to config");
    Config config = Config::fromJson(data);

    spdlog::set_level(config.log_level);

    std::vector<Spawnable*> objects_pointers = {};
    for (auto& object: config.components) {
        objects_pointers.push_back(&object);
    }

    spdlog::info("{}", objects_pointers.size());

    spdlog::info("Spawning objects");
    config.spawnComponentsVec();
    spdlog::info("Finished spawning objects");

    curl_global_cleanup();

    return 0;
}

