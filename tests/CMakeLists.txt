project(Test)
if (LINUX)
    # 依赖math库
    LINK_LIBRARIES(m)
endif ()

add_executable("test1" test1.c)
add_test(NAME "test1"
        COMMAND "./test1" "ACACMM"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test2 test2.c)
add_test(NAME test2
        COMMAND "./test2" 4 "12" "-9.0" "--4" "0.3"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test3 test3.c)
target_link_libraries(test3 PRIVATE MyQueue)
add_test(NAME test3
        COMMAND "./test3"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test4 test4.c)
target_link_libraries(test4 PRIVATE MyTree)
add_test(NAME test4
        COMMAND "./test4"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test5 test5.c)
target_link_libraries(test5 PRIVATE MyList)
add_test(NAME test5
        COMMAND "./test5"
        7 9 8 7 6 4 3 2 0 1
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test6 test6.c)
target_link_libraries(test6 PRIVATE MyList)
add_test(NAME test6
        COMMAND "./test6"
        5 5 4 3 2 1
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test7 test7.c)
target_link_libraries(test7 PRIVATE MyTree)
add_test(NAME test7
        COMMAND "./test7"
        7 1 2 3 5 6 7 8 3 8
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test8 test8.cpp)
add_test(NAME test8
        COMMAND "./test8"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test9 test9.cpp)
target_link_libraries(test9 PRIVATE MyTree)
add_test(NAME test9
        COMMAND "./test9 100"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

foreach (i RANGE 10 97)
    set(target_name test${i})
    add_executable(${target_name} test${i}.cpp)
    add_test(NAME ${target_name}
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${target_name}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endforeach ()

add_executable(test99 test99.cpp)
add_test(NAME test99
        COMMAND "./test99"
        "1234567890522"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

foreach (i RANGE 100 101)
    set(target_name test${i})
    add_executable(${target_name} test${i}.cpp)
    add_test(NAME ${target_name}
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${target_name}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endforeach ()

add_executable(test102 test102.cpp)
add_test(NAME test102
        COMMAND "./test102 12345#"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

foreach (i RANGE 103 112)
    set(target_name test${i})
    add_executable(${target_name} test${i}.cpp)
    add_test(NAME ${target_name}
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${target_name}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endforeach ()
