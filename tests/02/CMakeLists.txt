project(02_test)

add_executable(${PROJECT_NAME} main.c)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        1
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})