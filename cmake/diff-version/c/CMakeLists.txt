add_library(c c.cpp c.h)
target_link_libraries(c ${TEST_SOURCE_DIR}/a-version2/build/liba.a)
target_include_directories(c PUBLIC ${TEST_SOURCE_DIR}/a-version2/version2)