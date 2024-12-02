project(97_test)

add_executable(${PROJECT_NAME} main.cpp)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        "1234567890522"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})