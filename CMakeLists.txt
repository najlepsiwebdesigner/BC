# http://docs.opencv.org/3.0-beta/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage main.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )