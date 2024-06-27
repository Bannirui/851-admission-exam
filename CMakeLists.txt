cmake_minimum_required(VERSION 3.25)

project(861-admission-exam C)

option(UNIT_TEST "unit test" OFF)
if (UNIT_TEST)
    # 在项目的toplevel开启ctest
    enable_testing()
    add_subdirectory(tests)
endif ()