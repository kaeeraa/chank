cmake_minimum_required(VERSION 3.24)
project(chank LANGUAGES CXX)

include(FetchContent)

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

FetchContent_Declare(
  json
  URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(json)

add_executable(main
  src/main.cpp
  src/app/ChatBox.h
  src/app/ChatBox.cpp
)

target_link_libraries(main PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)

install(TARGETS main DESTINATION .)
