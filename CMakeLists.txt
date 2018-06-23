cmake_minimum_required(VERSION 3.2)

project(helloworld)

add_executable(${PROJECT_NAME} main.cpp)

#add_library(helloworld lib.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
