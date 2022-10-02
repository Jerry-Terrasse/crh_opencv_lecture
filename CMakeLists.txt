cmake_minimum_required(VERSION 3.0) # CMake 最低版本要求

project( OpenCV_Lecture_1 ) # 项目名称

find_package( OpenCV 4 REQUIRED ) # 寻找 OpenCV 库

include_directories( ${OpenCV_INCLUDE_DIRS} ) # 包含 OpenCV 头文件

add_executable( read_write 1_read_write.cpp ) # 添加需要编译的文件
target_link_libraries( read_write ${OpenCV_LIBS} ) # 链接 OpenCV 库

add_executable( img_info 2_img_info.cpp ) # 添加需要编译的文件
target_link_libraries( img_info ${OpenCV_LIBS} ) # 链接 OpenCV 库

add_executable( split 3_split.cpp ) # 添加需要编译的文件
target_link_libraries( split ${OpenCV_LIBS} ) # 链接 OpenCV 库

add_executable( convert 4_convert.cpp ) # 添加需要编译的文件
target_link_libraries( convert ${OpenCV_LIBS} ) # 链接 OpenCV 库

add_executable( threshold 5_threshold.cpp ) # 添加需要编译的文件
target_link_libraries( threshold ${OpenCV_LIBS} ) # 链接 OpenCV 库

add_executable( inrange 6_inrange.cpp ) # 添加需要编译的文件
target_link_libraries( inrange ${OpenCV_LIBS} ) # 链接 OpenCV 库

add_executable( trackbar 7_trackbar.cpp ) # 添加需要编译的文件
target_link_libraries( trackbar ${OpenCV_LIBS} ) # 链接 OpenCV 库

add_executable( filter 8_filter.cpp ) # 添加需要编译的文件
target_link_libraries( filter ${OpenCV_LIBS} ) # 链接 OpenCV 库

add_executable( morph 9_morph.cpp ) # 添加需要编译的文件
target_link_libraries( morph ${OpenCV_LIBS} ) # 链接 OpenCV 库