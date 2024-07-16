cmake_minimum_required(VERSION 3.30.0)
project(testerrormanager)
add_executable(testerrormanager test.cpp)
target_link_directories(testerrormanager PRIVATE ${CMAKE_SOURCE_DIR}/../src/build/) # this needs at least version 3.13.0 of cmake
target_link_libraries(testerrormanager errormanager)