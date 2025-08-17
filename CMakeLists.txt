cmake_minimum_required(VERSION 3.16)
project(AprilTagUnityExt C)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Pull AprilTag as a subdirectory (CI will git clone into third_party/apriltag)
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/third_party/apriltag/CMakeLists.txt)
  message(WARNING "third_party/apriltag not found. CI workflow will clone it before build.")
endif()

# Disable apriltag extras we don't need to avoid install() issues on some platforms
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(BUILD_PYTHON_WRAPPER OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(APRILTAG_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(third_party/apriltag)

add_library(AprilTag SHARED
  src/unity_ext.c
)

target_include_directories(AprilTag PUBLIC
  third_party/apriltag
  third_party/apriltag/common
  third_party/apriltag/apriltag
  src
)

target_link_libraries(AprilTag PRIVATE apriltag)

set_target_properties(AprilTag PROPERTIES
  OUTPUT_NAME "AprilTag"
)


