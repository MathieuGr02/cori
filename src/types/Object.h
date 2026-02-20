//
// Created by mathieu on 1/29/26.
//

#ifndef CORI_OBJECT_H
#define CORI_OBJECT_H
#include <string>

#include "Spawnable.h"
#include "../docker/ContainerInstance.h"


class Object:
    public Spawnable
{
public:
    std::string name;
    ContainerConfig container_config;
    ContainerInstance container_instance;


    void create() override;
    void setup() override;
    void deploy() override;

protected:
    void upload_files();
};


#endif //CORI_OBJECT_H