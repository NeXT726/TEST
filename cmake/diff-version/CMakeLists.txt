project(TEST)

add_executable(main main.cpp)

add_subdirectory(a-version1)
# add_subdirectory(a-version2)
add_subdirectory(b)

add_subdirectory(c)

target_include_directories(main PUBLIC "${TEST_SOURCE_DIR}")

target_link_libraries(main c b)

