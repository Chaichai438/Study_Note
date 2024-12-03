cmake_minimum_required(VERSION 3.10)

project(test)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(test 02_Mat类元素的读取.cpp)

target_link_libraries(test PRIVATE ${OpenCV_LIBS})