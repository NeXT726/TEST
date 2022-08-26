# 父目录下的CMakeLists.txt
cmake_minimum_required(VERSION 3.10.2)
project(test)

add_executable(test main.cpp)
add_library(sub test.cpp)
target_link_libraries(test sub)