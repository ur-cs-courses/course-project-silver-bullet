cmake_minimum_required(VERSION 3.16)
project(libhello)

include(dependencies.cmake)

add_library(libhello
  src/hello.cpp
)

target_include_directories(libhello
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(libhello
  fmt::fmt
)

add_subdirectory(app)
