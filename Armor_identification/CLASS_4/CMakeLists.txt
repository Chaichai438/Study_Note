cmake_minimum_required(VERSION 3.10)
project(Armor_identification)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(fmt REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include) # 向项目添加头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/tasks)

# Declare the executable target built from your sources
add_executable(Armor_identification main.cpp tasks/detector.cpp)

# Link your application with OpenCV libraries
target_link_libraries(Armor_identification PRIVATE ${OpenCV_LIBS})
target_link_libraries(Armor_identification PRIVATE fmt::fmt)