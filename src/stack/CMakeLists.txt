project(MyStack)

# 头文件目录
include_directories(../include)

add_library(${PROJECT_NAME} STATIC MyStack.c)