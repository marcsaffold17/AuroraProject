cmake_minimum_required(VERSION 3.26)
project(Aurora9)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/Catch2-devel)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

include_directories(${CMAKE_SOURCE_DIR})
# each unit test file needs its own executable
add_executable(Aurora9 main.cpp)
add_executable(jsonTest tests/jsonTest.cpp)
target_link_libraries(jsonTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(jsonTest PRIVATE nlohmann_json::nlohmann_json)

include(CTest)
add_test(NAME jsonParseTest COMMAND jsonParseTest)