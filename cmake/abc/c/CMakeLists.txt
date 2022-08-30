project(HELLO)

add_executable(main main.cpp)
target_link_libraries(main ${HELLO_SOURCE_DIR}/../b/build/libb.so)
target_include_directories(main PRIVATE ${HELLO_SOURCE_DIR}/../b)

# target_link_libraries(main ${HELLO_SOURCE_DIR}/../a/build/liba.a)
# target_include_directories(main PRIVATE ${HELLO_SOURCE_DIR}/../a)
