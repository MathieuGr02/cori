//
// Created by mathieu on 1/29/26.
//

#include "Object.h"

#include "Node.h"
#include "../adapters/docker/Docker.h"

void Object::create() {
    spdlog::debug("Starting object create");

    this->container_instance = this->docker.createContainer(&this->container_config);

    spdlog::debug("Finished object create");
}

void Object::setup() {
    spdlog::debug("Starting object setup");
    this->docker.startContainer(this->container_instance.id);
    spdlog::debug("Finished object setup");
}

void Object::deploy() {
    spdlog::debug("Starting object deploy");
    spdlog::debug("Finished object deploy");

}

Object Object::fromJsonInternal(json j) {
    Object object = Object();

    object.node = Node::fromJson(j["Node"]);
    object.container_config = ContainerConfig::fromJson(j["ContainerConfig"]);

    if (object.node.socket) {
        object.docker = Docker(object.node.socket.value());
    }

    spdlog::debug("Finished parsing object");
    return object;
}
