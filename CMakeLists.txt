cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

add_executable(${PROJECT_NAME}_cli main.cpp)

add_library(${PROJECT_NAME}_lib lib.cpp)

set_target_properties(${PROJECT_NAME}_cli ${PROJECT_NAME}_lib PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(${PROJECT_NAME}_cli ${PROJECT_NAME}_lib)
