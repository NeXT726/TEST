project(HELLO)

add_executable(main main.cpp)
target_link_libraries(main ${HELLO_SOURCE_DIR}/../b/build/libb.a)
target_include_directories(main PRIVATE ${HELLO_SOURCE_DIR}/../b)