cmake_minimum_required(VERSION 3.10)

project(test01)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(test01 12_单目位姿估计.cpp)

target_link_libraries(test01 PRIVATE ${OpenCV_LIBS})