//
// Created by mathieu on 2/3/26.
//

#ifndef CORI_JSONSERIALIZABLE_H
#define CORI_JSONSERIALIZABLE_H
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class JsonSerializable {
public:
    virtual ~JsonSerializable() = default;

    virtual json toJson() = 0;
};


#endif //CORI_JSONSERIALIZABLE_H