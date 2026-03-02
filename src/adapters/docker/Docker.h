//
// Created by mathieu on 1/29/26.
//

#ifndef CORI_CLIENT_H
#define CORI_CLIENT_H
#include <string>

#include <nlohmann/json.hpp>

#include "ContainerInstance.h"
#include "NetworkConfiguration.h"
#include "../../http/HttpResponse.h"
#include "../../http/RequestMethod.h"

using json = nlohmann::json;

class Docker {
private:
    std::optional<std::string> host;
    std::optional<__uint16_t> port;
    std::optional<std::string> socket;
public:
    Docker(): socket("/var/run/docker.sock") {}
    Docker(std::string socket): socket(socket) {}
    Docker(std::string host, __uint16_t port): host(host), port(port) {}


    // /containers
    std::vector<ContainerConfig> listContainers();
    ContainerInstance createContainer(ContainerConfig *container);
    void listContainerProcesses(std::string id);
    void getContainerLogs(std::string id);
    ContainerInstance getContainer(std::string id);
    void startContainer(std::string id);
    void stopContainer(std::string id);
    void deleteContainer(std::string id);
    void killContainer(std::string id);

    // /images

    // /networks
    void listNetworks();
    void deletenetwork();
    void createNetwork(NetworkConfiguration network_configuration);
    void addContainerToNetwork();
    void removeContainerFromNetwork();

    // /volumes

private:
    HttpResponse sendRequest(RequestMethod method, const std::string &endpoint, const std::optional<std::string> &body = std::nullopt);
};


#endif //CORI_CLIENT_H