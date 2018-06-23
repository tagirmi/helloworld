cmake_minimum_required(VERSION 3.2)

project(helloworld)
add_executable(helloworld "main.cpp")

set_target_properties(helloworld PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)