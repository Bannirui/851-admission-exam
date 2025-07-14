cmake_minimum_required(VERSION 3.25)
project(851-admission-exam CXX)

# 平台判断并设置默认编译器 仅在未手动指定时生效
if(NOT DEFINED CMAKE_C_COMPILER AND NOT DEFINED CMAKE_CXX_COMPILER)
    if(APPLE)
        message(STATUS "Detected Apple platform")
        set(CMAKE_C_COMPILER /usr/bin/clang CACHE STRING "C compiler" FORCE)
        set(CMAKE_CXX_COMPILER /usr/bin/clang++ CACHE STRING "C++ compiler" FORCE)
    elseif(UNIX)
        message(STATUS "Detected Linux platform")
        set(CMAKE_C_COMPILER /usr/bin/gcc CACHE STRING "C compiler" FORCE)
        set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE STRING "C++ compiler" FORCE)
    else()
        message(FATAL_ERROR "Unsupported platform")
    endif()
else()
    message(STATUS "Using user-defined compiler: ${CMAKE_C_COMPILER}, ${CMAKE_CXX_COMPILER}")
endif()
# c/cpp标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Werror)
# 输出目录
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(src)

option(UNIT_TEST "unit test" ON)
if (UNIT_TEST)
    # 在项目的top level开启ctest
    enable_testing()
    add_subdirectory(tests)
endif ()