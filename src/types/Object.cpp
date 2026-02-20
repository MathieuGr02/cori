//
// Created by mathieu on 1/29/26.
//

#include "Object.h"

#include "../docker/Docker.h"

void Object::create() {
    this->container_instance = Docker::createContainer(&this->container_config);
}

void Object::setup() {
    Docker::startContainer(this->container_instance.id);
}

void Object::deploy() {

}
