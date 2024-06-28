project(03_test)

include_directories(${test_extra_include_dirs})

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${test_extra_include_dirs})
target_link_directories(${PROJECT_NAME} PUBLIC ${test_extra_lib_dirs})
target_link_libraries(${PROJECT_NAME} MyQueue)

add_test(NAME ${PROJECT_NAME}
        COMMAND "./${PROJECT_NAME}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})