cmake_minimum_required(VERSION 3.12)
project(nix-package-template_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-O3 -Wall -Wextra -Wpedantic)
endif()

add_executable(main main.cpp)

install(TARGETS main DESTINATION .)
