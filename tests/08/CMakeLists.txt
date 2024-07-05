project(08_test)

add_executable(${PROJECT_NAME} MatrixUDG.cpp)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        7 1 2 3 5 6 7 8 3 8
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})