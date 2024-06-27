project(02_test)

add_executable(${PROJECT_NAME} main.c)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        4 "12" "-9.0" "--4" "0.3"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})