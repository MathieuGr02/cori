cmake_minimum_required(VERSION 4.1.2)
project(cori)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "" FORCE)

include(FetchContent)

# JSON Library
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

# Logging Library
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(spdlog)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

find_package(libssh REQUIRED)

set(CMAKE_CXX_STANDARD 26)

add_executable(cori main.cpp
        src/types/Object.cpp
        src/types/Object.h
        src/types/Store.cpp
        src/types/Store.h
        src/adapters/docker/ContainerInstance.cpp
        src/adapters/docker/ContainerInstance.h
        src/adapters/docker/Docker.cpp
        src/adapters/docker/Docker.h
        src/adapters/docker/PortMapping.cpp
        src/adapters/docker/PortMapping.h
        src/adapters/docker/ContainerConfigBuilder.cpp
        src/adapters/docker/ContainerConfigBuilder.h
        src/util/JsonSerializable.cpp
        src/util/JsonSerializable.h
        src/util/JsonDeserializable.cpp
        src/util/JsonDeserializable.h
        src/util/util.cpp
        src/util/util.h
        src/adapters/docker/TransportLayerProtocols.cpp
        src/adapters/docker/TransportLayerProtocols.h
        src/adapters/docker/State.cpp
        src/adapters/docker/State.h
        src/adapters/docker/ContainerConfig.cpp
        src/adapters/docker/ContainerConfig.h
        src/http/HttpResponse.cpp
        src/http/HttpResponse.h
        src/http/HttpStatus.cpp
        src/http/HttpStatus.h
        src/http/HttpRequest.cpp
        src/http/HttpRequest.h
        src/http/HttpRequestBuilder.cpp
        src/http/HttpRequestBuilder.h
        src/adapters/docker/exceptions/ContainerAlreadyExistsException.cpp
        src/adapters/docker/exceptions/ContainerAlreadyExistsException.h
        src/adapters/docker/exceptions/NoSuchImageException.cpp
        src/adapters/docker/exceptions/NoSuchImageException.h
        src/adapters/docker/exceptions/DockerException.cpp
        src/adapters/docker/exceptions/DockerException.h
        src/adapters/docker/exceptions/InvalidConfigException.cpp
        src/adapters/docker/exceptions/InvalidConfigException.h
        src/adapters/docker/exceptions/ContainerDoesntExistException.cpp
        src/adapters/docker/exceptions/ContainerDoesntExistException.h
        src/http/RequestMethod.cpp
        src/http/RequestMethod.h
        src/types/Spawnable.cpp
        src/types/Spawnable.h
        src/types/Uploader.cpp
        src/types/Uploader.h
        src/adapters/ssh/Ssh.cpp
        src/adapters/ssh/Ssh.h
        src/Config.cpp
        src/Config.h
        src/adapters/ssh/exceptions/SshConnectionException.cpp
        src/adapters/ssh/exceptions/SshConnectionException.h
        src/adapters/ssh/Ssh.cpp
        src/adapters/docker/ContainerConfig.h
        src/adapters/docker/HostConfig.cpp
        src/adapters/docker/HostConfig.h
        src/adapters/docker/NetworkingConfig.cpp
        src/adapters/docker/NetworkingConfig.h
        src/adapters/docker/NetworkConfiguration.cpp
        src/adapters/docker/NetworkConfiguration.h
        src/types/Node.cpp
        src/types/Node.h
)



target_link_libraries(cori PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(cori PRIVATE spdlog::spdlog)
target_link_libraries(cori PRIVATE ${CURL_LIBRARIES})
target_link_libraries(cori PRIVATE ssh)
target_include_directories(cori PRIVATE ${LIBSSH_LIBRARIES})
