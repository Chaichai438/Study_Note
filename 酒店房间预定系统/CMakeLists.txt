# 设置最低版本要求
cmake_minimum_required(VERSION 3.24)

# 定义项目名称
project(Hotel_Book)

# 添加可执行文件目标
add_executable(${PROJECT_NAME}
    src/酒店房间预定系统.cpp
    src/hotel_Book.cpp
    src/User.cpp
)

# 为特定目标指定包含目录
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
