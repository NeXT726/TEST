add_library(a a.cpp a.h)
# target_include_directories(a PUBLIC "${TEST_SOURCE_DIR}/a-version1")
target_include_directories(a PUBLIC "${TEST_SOURCE_DIR}/a-version2/version2")
