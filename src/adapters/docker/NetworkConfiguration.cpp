//
// Created by mathieu on 3/1/26.
//

#include "NetworkConfiguration.h"

json NetworkConfiguration::toJson() {
    json j;

    j["Name"] = this->name;

    return j;
}
