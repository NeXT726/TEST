
add_library(djl a/a.cpp a/a.h b/b.cpp b/b.h)
target_include_directories(djl PUBLIC "${TEST_SOURCE_DIR}/src")