
//
// Created by mathieu on 1/29/26.
//

#include "Docker.h"

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

#include <spdlog/spdlog.h>

#include "NetworkConfiguration.h"
#include "../../http/HttpRequestBuilder.h"
#include "../../http/HttpResponse.h"
#include "exceptions/ContainerAlreadyExistsException.h"
#include "exceptions/ContainerDoesntExistException.h"
#include "exceptions/DockerException.h"
#include "exceptions/InvalidConfigException.h"
#include "exceptions/NoSuchImageException.h"

class ContainerConfigBuilder;
using json = nlohmann::json;

std::vector<ContainerConfig> Docker::listContainers() {
    HttpResponse result = sendRequest(GET, "/containers/json");
    json body = json::parse(result.getBody());
    std::vector<ContainerConfig> containers;
    for (const auto& item: body) {
        containers.push_back(ContainerConfig::fromJson(item));
    }

    return containers;
}

ContainerInstance Docker::getContainer(std::string id) {
    spdlog::info("Getting container. Id: {}", id);
    const std::string endpoint = std::format("/containers/{}/json", id);
    HttpResponse result = sendRequest(GET, endpoint);

    if (!result.success()) {
        switch (result.getStatusCode()) {
            case NotFound:
                throw ContainerDoesntExistException();
            default:
                throw DockerException();
        }
    }

    json body = json::parse(result.getBody());
    return ContainerInstance::fromJson(body);
}

ContainerInstance Docker::createContainer(ContainerConfig *container) {
    spdlog::info("Creating container. Name: {}", container->hostName.value());
    HttpResponse result = sendRequest(POST, "/containers/create",  container->toJson().dump());

    if (!result.success()) {
        spdlog::error("{}", static_cast<int>(result.getStatusCode()));
        switch (result.getStatusCode()) {
            case NotFound: {
                std::string image = "null";
                if (container->image.has_value()) {
                    image = container->image.value();
                }
                throw NoSuchImageException(image);
            }
            case BadRequest: {
                throw InvalidConfigException();
            }
            case Conflict: {
                throw ContainerAlreadyExistsException("Container Already exists");
            }
            default:
                throw DockerException();
        }
    }

    json body = json::parse(result.getBody());
    spdlog::debug("Successfully created container. Name: {}", container->hostName.value());
    return getContainer(body["Id"]);
}

void Docker::startContainer(std::string id) {
    spdlog::info("Starting container. Id: {}", id);
    const std::string endpoint = std::format("/containers/{}/start", id);
    HttpResponse response = sendRequest(POST, endpoint);

    switch (response.getStatusCode()) {
        //case NotFound
    }
}

void Docker::stopContainer(std::string id) {
    spdlog::info("Stopping container. Id {}", id);
    const std::string endpoint = std::format("/containers/{}/stop", id);
    sendRequest(POST, endpoint);
}

void Docker::deleteContainer(std::string id) {
    spdlog::info("Deleting container. Id: {}", id);
    const std::string endpoint = std::format("/containers/{}", id);
    sendRequest(DELETE, endpoint);
}

void Docker::killContainer(std::string id) {
    spdlog::info("Killing container. Id: {}", id);
    const std::string endpoint = std::format("/containers/{}/kill", id);
    sendRequest(POST, endpoint);
}

/* Network */

void Docker::createNetwork(NetworkConfiguration network_configuration) {
    spdlog::info("Creating network. Name: {}", network_configuration.name);
    sendRequest(POST, "/networks/create", network_configuration.toJson().dump());
}

HttpResponse Docker::sendRequest(const RequestMethod method, const std::string &endpoint, const std::optional<std::string> &body) {
    std::string URL = "http://localhost" + endpoint;
    spdlog::debug("Sending request to docker socket. URL: {}", URL);

    CURL* curl;
    auto request_builder = HttpRequestBuilder()
        .method(method)
        .addHeader("Accept: application/json")
        .setURL(URL);

    if (this->socket.has_value()) {
        spdlog::debug("Using docker socket: {}", this->socket.value());
        request_builder = request_builder.setUnixSocket(this->socket.value());
    }

    if (body.has_value()) {
        spdlog::debug(body.value());
        request_builder = request_builder
            .addHeader("Content-Type: application/json")
            .setBody(body.value());
    }

    return request_builder
        .build()
        .send();
}
