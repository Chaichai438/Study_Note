add_subdirectory(./Logger) # 项目的存放位置

include_directories(
    ./include
)

add_library(u1s1 src/Log.cpp)

target_link_libraries(
    u1s1
    Utils::Logger
) # 链接库