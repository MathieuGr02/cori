//
// Created by mathieu on 2/27/26.
//

#include "HostConfig.h"

#include <iostream>

json HostConfig::toJson() {
    json j;

    spdlog::trace("Parsing HostConfig to json");

    j = setJson(j, "CpuShares", &this->cpuShares);
    j = setJson(j, "Memory", &this->memory);
    j = setJson(j, "CgroupParent", &this->cgroupParent);
    j = setJson(j, "BlkioWeight", &this->blkioWeight);
    j = setJson(j, "CpuPeriod", &this->cpuPeriod);
    j = setJson(j, "CpuQuota", &this->cpuQuota);
    j = setJson(j, "CpuRealtimePeriod", &this->cpuRealtimePeriod);
    j = setJson(j, "CpuRealtimeRuntime", &this->cpuRealtimeRuntime);
    j = setJson(j, "CpusetMems", &this->cpusetMems);
    j = setJson(j, "DeviceCgroupRules", &this->deviceCgroupRules);
    j = setJson(j, "MemoryReservation", &this->memoryReservation);
    j = setJson(j, "MemorySwap", &this->memorySwap);
    j = setJson(j, "MemorySwappiness", &this->memorySwappiness);
    j = setJson(j, "NanoCpus", &this->nanoCpus);
    j = setJson(j, "OomKillDisable", &this->oomKillDisable);
    j = setJson(j, "Init", &this->init);
    j = setJson(j, "PidsLimit", &this->pidsLimit);
    j = setJson(j, "CpuCount", &this->cpuCount);
    j = setJson(j, "CpuPercent", &this->cpuPercent);
    j = setJson(j, "MaximumIOps", &this->ioMaximumIOps);
    j = setJson(j, "MaximumIOBps", &this->ioMaximumBandwith);
    j = setJson(j, "Binds", &this->binds);
    j = setJson(j, "ContainerIDFile", &this->containerIDFile);
    j = setJson(j, "NetworkMode", &this->networkMode);
    j = setJson(j, "AutoRemove", &this->autoRemove);
    j = setJson(j, "VolumeDriver", &this->volumeDriver);
    j = setJson(j, "VolumesFrom", &this->volumesFrom);
    j = setJson(j, "CapAdd", &this->capAdd);
    j = setJson(j, "CapDrop", &this->capDrop);
    j = setJson(j, "CgroupnsMode", &this->cgroupnsMode);
    j = setJson(j, "Dns", &this->dns);
    j = setJson(j, "DnsOptions", &this->dnsOptions);
    j = setJson(j, "DnsSearch", &this->dnsSearch);
    j = setJson(j, "GroupAdd", &this->groupAdd);
    j = setJson(j, "IpcMode", &this->ipcMode);
    j = setJson(j, "Cgroup", &this->cgroup);
    j = setJson(j, "Links", &this->links);
    j = setJson(j, "OomScoreAdj", &this->oomScoreAdj);
    j = setJson(j, "PidMode", &this->pidMode);
    j = setJson(j, "Privileged", &this->privileged);
    j = setJson(j, "PublishAllPorts", &this->publishAllPorts);
    j = setJson(j, "ReadonlyRootfs", &this->readOnlyRootfs);
    j = setJson(j, "SecurityOpt", &this->securityOpt);
    j = setJson(j, "UTSMode", &this->utsMode);
    j = setJson(j, "UsernsMode", &this->usernsMode);
    j = setJson(j, "ShmSize", &this->shmSize);
    j = setJson(j, "Runtime", &this->runtime);
    j = setJson(j, "Isolation", &this->isolation);
    j = setJson(j, "MaskedPaths", &this->maskedPaths);

    spdlog::trace("Finished parsing HostConfig to json");

    return j;
}

HostConfig HostConfig::fromJsonInternal(json j) {
    spdlog::trace("Parsing Json to HostConfig");

    HostConfig host_config = HostConfig();

    setField(j, "Privileged", &host_config.privileged);

    spdlog::trace("Finished parsing Json to HostConfig");

    return host_config;
}
