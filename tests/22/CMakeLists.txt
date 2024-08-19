project(22_test)

add_executable(${PROJECT_NAME} main.cpp)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        6 3 1 2 3
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})