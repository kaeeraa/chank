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

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

add_executable(main
    src/main.cpp
    src/app/ChatBox.h
    src/app/ChatBox.cpp
)

target_link_libraries(main PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

install(TARGETS main DESTINATION .)
