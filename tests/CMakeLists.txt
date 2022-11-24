project(tests)

include_directories(include)
add_executable(tests src/tests.cpp)
target_link_libraries(tests mylib)
add_test(usage_test tests)