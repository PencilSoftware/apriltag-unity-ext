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
set(ENABLE_WERROR OFF CACHE BOOL "" FORCE)

if(APPLE)
  # Avoid iOS treating certain warnings as errors in third_party sources
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-error=shorten-64-to-32")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=shorten-64-to-32")
endif()

add_subdirectory(third_party/apriltag)

# Build static lib on iOS, shared elsewhere
set(LIB_TYPE SHARED)
if(APPLE AND CMAKE_SYSTEM_NAME STREQUAL "iOS")
  set(LIB_TYPE STATIC)
endif()

add_library(AprilTag ${LIB_TYPE}
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


