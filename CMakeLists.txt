cmake_minimum_required(VERSION 3.18)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(base64)

include(GNUInstallDirs)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(LIB_SOURCES src/base64.c)
set(LIB_HEADERS include/base64.h)

add_library(base64 SHARED ${LIB_SOURCES})
add_library(base64-static STATIC ${LIB_SOURCES})
set_target_properties(base64-static PROPERTIES OUTPUT_NAME "base64")
set_target_properties(base64-static PROPERTIES PREFIX "lib")
set_target_properties(base64 PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(base64-static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
install(TARGETS base64 base64-static
        EXPORT Base64Targets 
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}  # 动态库安装路径
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}  # 静态库安装路径
        RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}  # 可执行文件安装路径
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}  # 头文件安装路径
        )
install(FILES ${LIB_HEADERS} DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR} )

enable_testing()

add_executable(test_main test/main.c)

target_link_libraries(test_main base64)

add_test(NAME test1 COMMAND test_main)