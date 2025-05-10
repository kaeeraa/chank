cmake_minimum_required(VERSION 3.12)
project(chank LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-O3 -Wall -Wextra -Wpedantic)
endif()

include_directories(src)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(main src/main.cpp)

install(TARGETS main DESTINATION .)
