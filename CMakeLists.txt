cmake_minimum_required(VERSION 4.1.2)
project(cori LANGUAGES CXX)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(spdlog)

find_package(CURL REQUIRED)
find_package(libssh REQUIRED)

add_subdirectory(src)
add_subdirectory(cli)

target_include_directories(cori_lib PUBLIC include)
target_link_libraries(cori_cli PUBLIC cori_lib)