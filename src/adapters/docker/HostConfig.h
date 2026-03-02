//
// Created by mathieu on 2/27/26.
//

#ifndef CORI_HOSTCONFIG_H
#define CORI_HOSTCONFIG_H
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "../../util/JsonDeserializable.h"
#include "../../util/JsonSerializable.h"


class HostConfig:
    public JsonDeserializable<HostConfig>,
    public JsonSerializable
{
public:
    std::optional<uint8_t> cpuShares;
    std::optional<int64_t> memory;
    std::optional<std::string> cgroupParent;
    std::optional<uint8_t> blkioWeight;
    //std::optional<std::string> blkioWeightDevice;
    //std::optional<std::string> blkioDeviceReadBps;
    //std::optional<std::string> blkioDeviceWriteBps;
    //std::optional<std::string> blkioDeviceReadIOps;
    //std::optional<std::string> blkioDeviceWriteIOps;
    std::optional<int64_t> cpuPeriod;
    std::optional<int64_t> cpuQuota;
    std::optional<int64_t> cpuRealtimePeriod;
    std::optional<int64_t> cpuRealtimeRuntime;
    std::optional<std::string> cpusetCpus;
    std::optional<std::string> cpusetMems;
    //std::optional<std::string> Devices;
    std::optional<std::vector<std::string>> deviceCgroupRules;
    //std::optional<std::vector<std::string>> deviceRequests;
    std::optional<int64_t> memoryReservation;
    std::optional<int64_t> memorySwap;
    std::optional<int64_t> memorySwappiness;
    std::optional<int64_t> nanoCpus;
    std::optional<bool> oomKillDisable;
    std::optional<bool> init;
    std::optional<int64_t> pidsLimit;
    //std::optional<> ulimits;
    std::optional<int64_t> cpuCount;
    std::optional<int64_t> cpuPercent;
    std::optional<int64_t> ioMaximumIOps;
    std::optional<int64_t> ioMaximumBandwith;
    std::optional<std::vector<std::string>> binds;
    std::optional<std::string> containerIDFile;
    //std::optional<std::string> logConfig;
    std::optional<std::string> networkMode;
    //std::optional<std::string> portBindings;
    //std::optional<std::string> restartPolicy;
    std::optional<bool> autoRemove;
    std::optional<std::string> volumeDriver;
    std::optional<std::vector<std::string>> volumesFrom;
    //std::optional<std::vector<>> Mounts;
    //std::optional<std::vector<std::string>> consoleSize;
    //std::optional<std::vector<std::string>> annotations;
    std::optional<std::vector<std::string>> capAdd;
    std::optional<std::vector<std::string>> capDrop;
    std::optional<std::string> cgroupnsMode;
    std::optional<std::vector<std::string>> dns;
    std::optional<std::vector<std::string>> dnsOptions;
    std::optional<std::vector<std::string>> dnsSearch;
    std::optional<std::vector<std::string>> extraHosts;
    std::optional<std::vector<std::string>> groupAdd;
    std::optional<std::string> ipcMode;
    std::optional<std::string> cgroup;
    std::optional<std::vector<std::string>> links;
    std::optional<int> oomScoreAdj;
    std::optional<std::string> pidMode;
    std::optional<bool> privileged;
    std::optional<bool> publishAllPorts;
    std::optional<bool> readOnlyRootfs;
    std::optional<std::string> securityOpt;
    //std::optional<std::string> storageOpt;
    //std::optional<std::string> tmpfs;
    std::optional<std::string> utsMode;
    std::optional<std::string> usernsMode;
    std::optional<uint64_t> shmSize;
    //std::optional<std::string> sysctls;
    std::optional<std::string> runtime;
    std::optional<std::string> isolation;
    std::optional<std::vector<std::string>> maskedPaths;
    std::optional<std::vector<std::string>> readOnlyPaths;

    static HostConfig fromJsonInternal(json j);
    json toJson() override;
};


#endif //CORI_HOSTCONFIG_H