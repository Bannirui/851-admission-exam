project(MyTree)

file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
file(GLOB_RECURSE hdrs "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
add_library(${PROJECT_NAME} STATIC ${srcs} ${hdrs})
target_include_directories(${PROJECT_NAME}
        SYSTEM PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)
