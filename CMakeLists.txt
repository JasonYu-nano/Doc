cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)


set(PROJECT_ABSOLUTE_SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/../)

include(${PROJECT_ABSOLUTE_SOURCE_DIR}/Conan/conan.cmake)

project(Interview)

include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/Src/")

add_subdirectory(Src)
add_subdirectory(Test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)