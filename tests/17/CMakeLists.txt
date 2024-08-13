project(17_test)

add_executable(${PROJECT_NAME} main.cpp)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        7 34 37 5 9 8 9 8
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})