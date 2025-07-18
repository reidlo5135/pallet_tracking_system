cmake_minimum_required(VERSION 3.8)
project(pts_camera_streamer VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
  add_compile_options(-lopencv_core -lopencv_highgui  -lopencv_imgproc)


include_directories(
  include
  include/${PROJECT_NAME}
  ${OpenCV_INCLUDE_DIRS}
)

find_package(ament_cmake REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)

set(SOURCES
  src/application/image.cpp
  src/presentation/node.cpp
  src/main.cpp
)

set(DEPENDS
  ament_index_cpp
  rclcpp
  sensor_msgs
  cv_bridge
  image_transport
  OpenCV
)

set(EXEC_NAME
  ${PROJECT_NAME}
)

add_executable(${EXEC_NAME}
  ${SOURCES}
)

ament_target_dependencies(${EXEC_NAME}
  ${DEPENDS}
)

target_link_libraries(${EXEC_NAME}
  ament_index_cpp::ament_index_cpp
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  ${EXEC_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
