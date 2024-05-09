cmake_minimum_required(VERSION 3.0)
project(LinkedListProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/DoublyLinkedList.cpp
)

add_library(LinkedListProject ${SOURCES})

include_directories(include)

add_executable(LinkedList ${SOURCES})

add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(LinkedList_test
    tests/DoublyLinkedListTest.cpp
)

target_link_libraries(LinkedList_test
    gtest
    gtest_main
    pthread
    LinkedListProject
)

add_custom_target(run_tests
    COMMAND LinkedList_test
    DEPENDS LinkedList_test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)