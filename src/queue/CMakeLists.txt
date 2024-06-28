project(MyQueue)

# 头文件目录
include_directories(../include)

add_library(${PROJECT_NAME} STATIC MyQueue.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${test_extra_include_dirs})
target_link_directories(${PROJECT_NAME} PUBLIC ${test_extra_lib_dirs})
target_link_libraries(${PROJECT_NAME} MyStack)