//
// Created by mathieu on 1/29/26.
//

#ifndef CORI_CLIENT_H
#define CORI_CLIENT_H
#include <string>

#include <nlohmann/json.hpp>

#include "ContainerInstance.h"
#include "../../http/HttpResponse.h"
#include "../../http/RequestMethod.h"

using json = nlohmann::json;

class Docker {

public:
    // /containers
    static std::vector<ContainerConfig> listContainers();
    static ContainerInstance createContainer(ContainerConfig *container);
    static void listContainerProcesses(std::string id);
    static void getContainerLogs(std::string id);
    static ContainerInstance getContainer(std::string id);
    static void startContainer(std::string id);
    static void stopContainer(std::string id);
    static void deleteContainer(std::string id);
    static void killContainer(std::string id);

    // /images

    // /networks
    static void listNetworks();
    static void deletenetwork();
    static void createNetwork();
    static void addContainerToNetwork();
    static void removeContainerFromNetwork();

    // /volumes

private:
    HttpResponse<json> static sendRequest(RequestMethod method, const std::string &endpoint, const std::optional<std::string> &body = std::nullopt);
};


#endif //CORI_CLIENT_H