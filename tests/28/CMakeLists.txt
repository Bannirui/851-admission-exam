project(28_test)

add_executable(${PROJECT_NAME} main.cpp)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        6 6 5 4 2 1 3
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})