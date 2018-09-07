cmake_minimum_required(VERSION 3.9)
project(toDoList)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES Element.cpp Element.h ListElement.cpp ListElement.h)
add_executable(my_executable main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(my_executable core)