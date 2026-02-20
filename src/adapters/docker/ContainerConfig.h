//
// Created by mathieu on 2/5/26.
//

#ifndef CORI_CONTAINERCONFIG_H
#define CORI_CONTAINERCONFIG_H
#include <map>
#include <optional>
#include <string>
#include <vector>

#include "../../util/JsonDeserializable.h"
#include "../../util/JsonSerializable.h"


class PortMapping;

class ContainerConfig:
    public JsonDeserializable<ContainerConfig>,
    public JsonSerializable
{
public:
    std::optional<std::string> hostName;
    std::optional<std::string> domainName;
    std::optional<std::string> user;
    std::optional<std::vector<PortMapping>> exposedPorts;
    std::optional<std::map<std::string, std::string>> env;
    std::optional<std::vector<std::string>> cmd;
    //std::string healthcheck;
    std::optional<std::string> image;
    //std::string volumes; //REQUIRES VOLUME OBJECT
    std::optional<std::string> workingDir;
    std::optional<std::vector<std::string>> entrypoint;
    std::optional<bool> networkDisabled = false;
    std::optional<std::vector<std::string>> onBuild;
    std::optional<std::map<std::string, std::string>> labels;
    std::optional<std::string> stopSignal;
    std::optional<u_int64_t> stopTimeout = 10;
    std::optional<std::vector<std::string>> shell;
    // hostConfig; //REQUIRES HOSTCONFIG OBJECT
    // networkingConfig //REQUIRES NETWORKINGCONFIG OBJECT

    static ContainerConfig fromJsonInternal(json j);
    json toJson() override;
};


#endif //CORI_CONTAINERCONFIG_H