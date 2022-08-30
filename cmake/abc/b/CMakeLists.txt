project(B)

add_library(b SHARED b.cpp b.h)
target_link_libraries(b ${B_SOURCE_DIR}/../a/build/liba.so)
target_include_directories(b PRIVATE ${B_SOURCE_DIR}/../a)
