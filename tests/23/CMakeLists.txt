project(23_test)

add_executable(${PROJECT_NAME} main.cpp)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        6 11 14 23 13 4 5 14
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})