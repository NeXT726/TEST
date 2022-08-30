add_library(b b.cpp b.h)
target_link_libraries(b ../a/build/liba.a)
target_include_directories(b PRIVATE ../a)
target_include_directories(b PUBLIC .)