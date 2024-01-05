cmake_minimum_required(VERSION 3.18)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(base64)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(LIB_SOURCES src/base64.c)

add_library(base64 ${LIB_SOURCES})

enable_testing()

add_executable(test_main test/main.c)

target_link_libraries(test_main base64)

add_test(NAME test1 COMMAND test_main)