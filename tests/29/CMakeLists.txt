project(29_test)

add_executable(${PROJECT_NAME} main.cpp)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        6 1 2 1 4 4 6
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})