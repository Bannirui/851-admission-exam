project(01_test)

add_executable(${PROJECT_NAME} main.c)

add_test(NAME "01_test"
        COMMAND "01_test"
        ACACMM
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})