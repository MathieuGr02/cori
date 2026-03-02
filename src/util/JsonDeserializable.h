//
// Created by mathieu on 2/4/26.
//

#ifndef CORI_JSONDESERIALIZABLE_H
#define CORI_JSONDESERIALIZABLE_H

#include <nlohmann/json.hpp>

#include "spdlog/spdlog.h"

using json = nlohmann::json;

template <typename T>
class JsonDeserializable {
public:
    virtual ~JsonDeserializable() = default;

    static T fromJson(json j) {
        return T::fromJsonInternal(j);
    }

    static std::vector<T> fromJsonList(json j) {
        std::vector<T> items;
        for (auto &item: j) {
            items.push_back(T::fromJsonInternal(item));
        }

        return items;
    }

    // Set field to value of JSON field if present, otherwise default value;
    template <typename S>
    static void setField(json &j, const std::string &key, S *field, S default_value = S{}) {
        if (j.contains(key) && !j[key].is_null()) {
            spdlog::trace("Setting field. Key: {}", key);
            *field = j[key];
        }
        else {
            *field = default_value;
        }
    }

    static void setField(json &j, const std::string &key, std::string* field, const std::string &default_value) {
        if (j.contains(key)) {
            *field = j[key];
        }
        else {
            *field = default_value;
        }
    }
};


#endif //CORI_JSONDESERIALIZABLE_H