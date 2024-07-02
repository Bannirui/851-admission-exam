project(07_test)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${test_extra_include_dirs})
target_link_directories(${PROJECT_NAME} PUBLIC ${test_extra_lib_dirs})
target_link_libraries(${PROJECT_NAME} MyTree)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        7 1 2 3 5 6 7 8 3 8
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})