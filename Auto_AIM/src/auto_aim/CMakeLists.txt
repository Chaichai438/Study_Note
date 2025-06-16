find_package(OpenCV 4 REQUIRED)

include_directories(
        ./include
        ${OpenCV_INCLUDE_DIRS}
)

add_library(
        auto_detector
        src/Detector.cpp
        src/Lightbar.cpp
        src/Armor.cpp
)

target_link_libraries(
        auto_detector
        ${OpenCV_LIBS} 
        fmt::fmt
)
