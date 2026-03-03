cmake_minimum_required(VERSION 3.20)

project(CrazyPing)

include(cmake/UpdateSubmodules.cmake)

# add_subdirectory(vendor/SDL2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)

set(CMAKE_GENERATOR_PLATFORM x64)

add_executable(CrazyPing src/main.c)


if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT chip8)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif ()

# target_link_libraries(CrazyPing)
# target_include_directories(CrazyPing PRIVATE vendor/SDL2/include)
