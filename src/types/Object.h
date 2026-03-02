//
// Created by mathieu on 1/29/26.
//

#ifndef CORI_OBJECT_H
#define CORI_OBJECT_H
#include <string>

#include "Node.h"
#include "Spawnable.h"
#include "../adapters/docker/ContainerInstance.h"
#include "../adapters/docker/Docker.h"


class Object:
    public Spawnable,
    public JsonDeserializable<Object>
{
public:
    Object(): docker(Docker()) {}

    std::string name;

    Docker docker;

    Node node;
    ContainerConfig container_config;
    ContainerInstance container_instance;

    void create() override;
    void setup() override;
    void deploy() override;

    static Object fromJsonInternal(json j);

protected:
    void upload_files();
};


#endif //CORI_OBJECT_H