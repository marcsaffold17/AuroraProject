cmake_minimum_required(VERSION 3.26)
project(Aurora9)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "The compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "The compiler id: ${CMAKE_CXX_COMPILER_ID}")

if ((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR ((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") AND NOT (MINGW)))
    # using GCC or CLANG

    # this check also watches to see if the GNU compiler is MinGW-based (sanitizers aren't working great on
    # that at the moment so will not enable sanitizer if that's the case if the compiler is a MinGW GNU compiler)

    # Both, GCC and Clang support the same option set
    # We first turn on Warnings
    # --> https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
    #
    # -Wall stands for All Warnings
    # -Wextra pushes that a bit further
    # -pedantic sets the compiler to use strict ISO C++
    # -Werror treats all warnings as errors so you have to fix them
    #    this last option has been commented out to make things a little easier
    add_compile_options(-Wall -Wextra -pedantic) # -Werror)

    # Sanitizer options
    # The following will turn on Debugging (-g flag) and the Address Sanitizer
    # which is turned on with the -fsanitize=address option to the compiler.
    add_compile_options(-g -fsanitize=address,undefined)

    # When we turn on the sanitizer, you also need to instruct the linker that it
    # will be used which happens with the following link option command.
    add_link_options(-g -fsanitize=address,undefined)

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    # MSVC uses a different warning flags
    add_compile_options(/W4 /WX)
    add_compile_options(/fsanitize=address /MTd)

endif()


add_subdirectory(lib/Catch2-devel)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

include_directories(${CMAKE_SOURCE_DIR})
# each unit test file needs its own executable
add_executable(Aurora9 main.cpp IAlertReader.h AlertReader_JSON.h AlertReader_JSON.cpp alertReaderFactory.h alertReaderFactory.cpp Plasma_Obs.cpp plasmaReaderFactory.h)

add_executable(jsonTest tests/jsonTest.cpp)
add_executable(Alert_tests tests/Alert_tests.cpp IAlertReader.h AlertReader_JSON.h AlertReader_JSON.cpp alertReaderFactory.h alertReaderFactory.cpp)
add_executable(Plasma_tests tests/Plasma_tests.cpp Plasma_Obs.cpp Plasma_Obs.h plasmaReaderFactory.h PlasmaReader_JSON.cpp PlasmaReader_JSON.h)
target_link_libraries(jsonTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(jsonTest PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Alert_tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Alert_tests PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Plasma_tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Plasma_tests PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Aurora9 PRIVATE nlohmann_json::nlohmann_json)

include(CTest)
add_test(NAME jsonParseTest COMMAND jsonParseTest)
add_test(NAME Alert_tests COMMAND Alert_tests)
add_test(NAME Plasma_tests COMMAND Plasma_tests)