//
// Created by mathieu on 1/29/26.
//

#include "ContainerInstance.h"

#include <iostream>

ContainerInstance::ContainerInstance() {
    this->id = std::string();
}

ContainerInstance ContainerInstance::fromJsonInternal(json json) {
    auto container = ContainerInstance();
    container.id = json["Id"];
    container.config = ContainerConfig::fromJson(json["Config"]);

    return container;
}
