cmake_minimum_required(VERSION 3.25)

project(851-admission-exam CXX)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
# 头文件路径
list(APPEND test_extra_include_dirs "${PROJECT_SOURCE_DIR}/src/include")
# stack
list(APPEND test_extra_lib_dirs "${CMAKE_CURRENT_BINARY_DIR}/src/stack")
list(APPEND test_extra_links MyStack)
# queue
list(APPEND test_extra_lib_dirs "${CMAKE_CURRENT_BINARY_DIR}/src/queue")
list(APPEND test_extra_links MyQueue)
# tree
list(APPEND test_extra_lib_dirs "${CMAKE_CURRENT_BINARY_DIR}/src/tree")
list(APPEND test_extra_links MyTree)
# list
list(APPEND test_extra_lib_dirs "${CMAKE_CURRENT_BINARY_DIR}/src/list")
list(APPEND test_extra_links MyListNode)

option(UNIT_TEST "unit test" OFF)

if (UNIT_TEST)
    # 在项目的top level开启ctest
    enable_testing()
    add_subdirectory(tests)
endif ()