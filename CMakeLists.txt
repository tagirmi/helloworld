cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

configure_file(version.h.in version.h)

add_executable(${PROJECT_NAME}_cli main.cpp)

add_library(${PROJECT_NAME}_lib lib.cpp)

set_target_properties(${PROJECT_NAME}_cli ${PROJECT_NAME}_lib PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(${PROJECT_NAME}_cli ${PROJECT_NAME}_lib)

install(TARGETS ${PROJECT_NAME}_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT tagirmi@gmail.com)

include (CPack)

# unit tests
set(TEST_NAME test_lib)
include_directories(${GTEST_INCLUDE_DIR})
add_executable(${TEST_NAME}_cli test_lib.cpp)
target_link_libraries(${TEST_NAME}_cli ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
target_link_libraries(${TEST_NAME}_cli ${PROJECT_NAME}_lib ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(${TEST_NAME} ${TEST_NAME}_cli)
