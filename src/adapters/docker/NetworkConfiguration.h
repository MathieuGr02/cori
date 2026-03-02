//
// Created by mathieu on 3/1/26.
//

#ifndef CORI_NETWORKCONFIGURATION_H
#define CORI_NETWORKCONFIGURATION_H
#include <string>

#include "../../util/JsonSerializable.h"


class NetworkConfiguration:
    public JsonSerializable
{
public:
    std::string name;

    json toJson() override;
};


#endif //CORI_NETWORKCONFIGURATION_H