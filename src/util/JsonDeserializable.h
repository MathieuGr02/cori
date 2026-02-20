//
// Created by mathieu on 2/4/26.
//

#ifndef CORI_JSONDESERIALIZABLE_H
#define CORI_JSONDESERIALIZABLE_H

#include <nlohmann/json.hpp>

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
};


#endif //CORI_JSONDESERIALIZABLE_H