cmake_minimum_required(VERSION 3.24)
project(chank LANGUAGES CXX)

# *************************** #
# ** Project configuration ** #
# **         nodev         ** #
# *************************** #

set(BUILD_CLIENT ON)
set(BUILD_SERVER OFF)

# ************************* #
# ** Build configuration ** #
# **       devonly       ** #
# ************************* #
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-O2 -Wall -Wextra -Wpedantic)
endif()

include_directories(src)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

FetchContent_Declare(
  json
  URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(json)

if(BUILD_CLIENT)
  message(STATUS "Building client")
  find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)
  add_executable(chank
    # Entrypoint
    src/app/main.cpp

    # *** *.cpp *** #
    src/app/ChatManager.cpp

    # Layout
    src/app/layout/ChatBox.cpp

    # ***  *.h  *** #
    src/app/ChatManager.h

    # Layout
    src/app/layout/ChatBox.h
    src/app/layout/MessagesBox.h

    # Classes
    src/app/class/Message.h
    src/app/class/User.h
    src/app/class/Chat.h
  )

  target_link_libraries(chank PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
  target_link_libraries(chank PRIVATE nlohmann_json::nlohmann_json)

  install(TARGETS chank DESTINATION .)
endif()

if(BUILD_SERVER)
  message(STATUS "Building server")
  add_executable(chank_server
    # *** *.cpp *** #
    # Database
    src/server/database/Database.cpp

    # ***  *.h  *** #
    # Database
    includes/server/database/Database.h
  )

  target_link_libraries(chank_server PRIVATE nlohmann_json::nlohmann_json)

  install(TARGETS chank_server DESTINATION .)
endif()
