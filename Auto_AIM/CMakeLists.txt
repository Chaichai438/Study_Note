cmake_minimum_required(VERSION 3.10)

project(Auto_Aim)

find_package(OpenCV 4 REQUIRED)
find_package(fmt REQUIRED)


add_subdirectory(
    src/auto_aim
    
)

# 向项目添加头文件搜索路径
include_directories(
    src/
    src/auto_aim/include
    src/utils/include
    
    ${OpenCV_INCLUDE_DIRS}
    
) 

add_executable(
    Auto_Aim 
    main.cpp 
)

add_subdirectory(Logger)
target_link_libraries(
    Auto_Aim 
    
    auto_detector
    

    ${OpenCV_LIBS}
    fmt::fmt
    Utils::Logger
)


