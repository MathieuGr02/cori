//
// Created by mathieu on 2/28/26.
//

#ifndef CORI_NETWORKINGCONFIG_H
#define CORI_NETWORKINGCONFIG_H
#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <vector>

#include "../../util/JsonDeserializable.h"
#include "../../util/JsonSerializable.h"


class NetworkingConfig:
    public JsonDeserializable<NetworkingConfig>,
    public JsonSerializable {
public:
    //std::optional<EndpointIPAMConfig> ipamConfig;
    std::optional<std::vector<std::string>> links;
    std::optional<std::string> macAddress;
    std::optional<std::vector<std::string>> aliases;
    std::optional<std::map<std::string, std::string>> driverOpts;

    std::optional<std::int64_t> gwPriority;
    std::optional<std::string> networkID;
    std::optional<std::string> endpointID;
    std::optional<std::string> gateway;
    std::optional<std::string> ipAddress;
    std::optional<int> ipPrefixLen;
    std::optional<std::string> ipv6Gateway;
    std::optional<std::string> globalIPv6Address;
    std::optional<std::int64_t> globalIPv6PrefixLen;
    std::optional<std::vector<std::string>> dnsNames;

    static NetworkingConfig fromJsonInternal();
    json toJson() override;
};

#endif //CORI_NETWORKINGCONFIG_H