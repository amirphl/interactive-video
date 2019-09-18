cmake_minimum_required(VERSION 3.13)
project(Interactive_Video_Design_Project)

set(CMAKE_CXX_STANDARD 11)

add_executable(Interactive_Video_Design_Project main.cpp)

file(GLOB SOURCES
        package_bgs/*.h
        package_bgs/*.cpp
        )


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(OpenCV_ROOT_DIR "C:\\opencv\\mingw-build\\install")
set(OpenCV_DIR "C:\\opencv\\mingw-build\\instal")
FIND_PACKAGE(OpenCV REQUIRED PATHS C:\\opencv\\mingw-build\\install NO_DEFAULT_PATH)
include_directories(${OpenCV_INCLUDE_DIRS})
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_objdetect opencv_video)
target_link_libraries(Interactive_Video_Design_Project ${OpenCV_LIBS})
