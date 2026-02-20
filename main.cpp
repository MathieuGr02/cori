#include <iostream>

#include "spdlog/spdlog.h"
#include "src/docker/ContainerConfigBuilder.h"
#include "src/docker/Docker.h"

int main() {
    spdlog::set_level(spdlog::level::debug);

    auto port = PortMapping(9000);

    ContainerConfig config = ContainerConfigBuilder()
        .setImage("nginx:alpine")
        .setHostName("nginx")
        .addExposedPort(port)
        .build();

    ContainerInstance container_instance = Docker::createContainer(&config);
    Docker::startContainer(container_instance.id);

    return 0;
}
