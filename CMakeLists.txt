cmake_minimum_required(VERSION 3.10)

project(cliengine-precompiler VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch nlohmann/json
include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(nlohmann_json)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADERS
    ${INCLUDE_DIR}/cliengine-preprocessor/Generator.hpp
)


set(SOURCES 
    ${SRC_DIR}/main.cpp 
    ${SRC_DIR}/Generator.cpp
)

add_executable(cliengine-precompiler ${SOURCES})

target_include_directories(cliengine-precompiler PUBLIC ${INCLUDE_DIR})
target_link_libraries(cliengine-precompiler PRIVATE nlohmann_json::nlohmann_json)
