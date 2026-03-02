//
// Created by mathieu on 2/3/26.
//

#ifndef CORI_JSONSERIALIZABLE_H
#define CORI_JSONSERIALIZABLE_H
#include <nlohmann/json.hpp>

#include "spdlog/spdlog.h"

using json = nlohmann::json;

class JsonSerializable {
public:
    virtual ~JsonSerializable() = default;

    virtual json toJson() = 0;

    template <typename T>
    static json setJson(json j, const std::string &key, std::optional<T>* field) {
        if (field->has_value()) {
            spdlog::trace("Setting value {}", key);
            j[key] = field->value();
        }

        return j;
    }

    static json setJson(json j, const std::string &key, std::optional<JsonSerializable*>* field) {
        if (field->has_value()) {
            j[key] = field->value()->toJson();
        }

        return j;
    }
};


#endif //CORI_JSONSERIALIZABLE_H