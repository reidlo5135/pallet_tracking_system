cmake_minimum_required(VERSION 3.15)
project(pts_mqtt VERSION 2.0.2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
    include/
    include/${PROJECT_NAME}
)

add_library(${PROJECT_NAME} STATIC
    src/pts_mqtt/client.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

find_package(PahoMqttCpp REQUIRED)
find_library(PAHO_MQTT_C_LIB
    NAMES paho-mqtt3as
    PATHS
        ${CMAKE_SOURCE_DIR}/../vcpkg_installed/x64-windows/lib
        C:/vcpkg/installed/x64-windows/lib
        C:/vcpkg/packages/paho-mqtt_x64-windows/lib
    NO_DEFAULT_PATH
)

target_link_libraries(pts_mqtt
    PahoMqttCpp::paho-mqttpp3
    ${PAHO_MQTT_C_LIB}
)

add_executable(mqtt_main
    src/main.cpp
)

target_link_libraries(mqtt_main
    ${PROJECT_NAME}
)