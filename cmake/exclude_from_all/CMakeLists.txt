# 父目录下的CMakeLists.txt
cmake_minimum_required(VERSION 3.10.2)
project(test)

add_executable(test main.cpp)
include_directories(sub)
add_subdirectory(sub EXCLUDE_FROM_ALL) 
target_link_libraries(test subsub)
