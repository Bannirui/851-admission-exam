project(06_test)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${test_extra_include_dirs})
target_link_directories(${PROJECT_NAME} PUBLIC ${test_extra_lib_dirs})
target_link_libraries(${PROJECT_NAME} MyList)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        5 5 4 3 2 1
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})