//
// Created by mathieu on 2/27/26.
//

#include "HostConfig.h"

#include <iostream>

json HostConfig::toJson() {
    json j;

    if (this->cpuShares)              j["CpuShares"] = *this->cpuShares;
    if (this->memory)                 j["Memory"] = *this->memory;
    if (this->cgroupParent)           j["CgroupParent"] = *this->cgroupParent;
    if (this->blkioWeight)            j["BlkioWeight"] = *this->blkioWeight;
    if (this->cpuPeriod)              j["CpuPeriod"] = *this->cpuPeriod;
    if (this->cpuQuota)               j["CpuQuota"] = *this->cpuQuota;
    if (this->cpuRealtimePeriod)      j["CpuRealtimePeriod"] = *this->cpuRealtimePeriod;
    if (this->cpuRealtimeRuntime)     j["CpuRealtimeRuntime"] = *this->cpuRealtimeRuntime;
    if (this->cpusetCpus)             j["CpusetCpus"] = *this->cpusetCpus;
    if (this->cpusetMems)             j["CpusetMems"] = *this->cpusetMems;
    if (this->deviceCgroupRules)      j["DeviceCgroupRules"] = *this->deviceCgroupRules;
    if (this->memoryReservation)      j["MemoryReservation"] = *this->memoryReservation;
    if (this->memorySwap)             j["MemorySwap"] = *this->memorySwap;
    if (this->memorySwappiness)       j["MemorySwappiness"] = *this->memorySwappiness;
    if (this->nanoCpus)               j["NanoCpus"] = *this->nanoCpus;
    if (this->oomKillDisable)         j["OomKillDisable"] = *this->oomKillDisable;
    if (this->init)                   j["Init"] = *this->init;
    if (this->pidsLimit)              j["PidsLimit"] = *this->pidsLimit;
    if (this->cpuCount)               j["CpuCount"] = *this->cpuCount;
    if (this->cpuPercent)             j["CpuPercent"] = *this->cpuPercent;
    if (this->ioMaximumIOps)          j["MaximumIOps"] = *this->ioMaximumIOps;
    if (this->ioMaximumBandwith)      j["MaximumIOBps"] = *this->ioMaximumBandwith;
    if (this->binds)                  j["Binds"] = *this->binds;
    if (this->containerIDFile)        j["ContainerIDFile"] = *this->containerIDFile;
    if (this->networkMode)            j["NetworkMode"] = *this->networkMode;
    if (this->autoRemove)             j["AutoRemove"] = *this->autoRemove;
    if (this->volumeDriver)           j["VolumeDriver"] = *this->volumeDriver;
    if (this->volumesFrom)            j["VolumesFrom"] = *this->volumesFrom;
    if (this->capAdd)                 j["CapAdd"] = *this->capAdd;
    if (this->capDrop)                j["CapDrop"] = *this->capDrop;
    if (this->cgroupnsMode)           j["CgroupnsMode"] = *this->cgroupnsMode;
    if (this->dns)                    j["Dns"] = *this->dns;
    if (this->dnsOptions)             j["DnsOptions"] = *this->dnsOptions;
    if (this->dnsSearch)              j["DnsSearch"] = *this->dnsSearch;
    if (this->extraHosts)             j["ExtraHosts"] = *this->extraHosts;
    if (this->groupAdd)               j["GroupAdd"] = *this->groupAdd;
    if (this->ipcMode)                j["IpcMode"] = *this->ipcMode;
    if (this->cgroup)                 j["Cgroup"] = *this->cgroup;
    if (this->links)                  j["Links"] = *this->links;
    if (this->oomScoreAdj)            j["OomScoreAdj"] = *this->oomScoreAdj;
    if (this->pidMode)                j["PidMode"] = *this->pidMode;
    if (this->privileged)             j["Privileged"] = *this->privileged;
    if (this->publishAllPorts)        j["PublishAllPorts"] = *this->publishAllPorts;
    if (this->readOnlyRootfs)         j["ReadonlyRootfs"] = *this->readOnlyRootfs;
    if (this->securityOpt)            j["SecurityOpt"] = *this->securityOpt;
    if (this->utsMode)                j["UTSMode"] = *this->utsMode;
    if (this->usernsMode)             j["UsernsMode"] = *this->usernsMode;
    if (this->shmSize)                j["ShmSize"] = *this->shmSize;
    if (this->runtime)                j["Runtime"] = *this->runtime;
    if (this->isolation)              j["Isolation"] = *this->isolation;
    if (this->maskedPaths)            j["MaskedPaths"] = *this->maskedPaths;

    return j;
}

HostConfig HostConfig::fromJsonInternal(json j) {
    spdlog::trace("Parsing Json to HostConfig");

    HostConfig host_config = HostConfig();

    setField(j, "Privileged", &host_config.privileged);

    spdlog::trace("Finished parsing Json to HostConfig");

    return host_config;
}
