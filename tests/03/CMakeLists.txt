project(03_test)

add_executable(${PROJECT_NAME} main.c Stack.c Queue.c)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})