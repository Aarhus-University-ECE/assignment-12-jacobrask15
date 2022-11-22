cmake_minimum_required(VERSION 3.10)
project(template)
include(CTest)

set(CMAKE_CXX_STANDARD 14)

# add cpp files not containing a main function here
# for example like this:
# add_library(mylib src/max.cpp src/swap.cpp src/max_sum.cpp)
target_include_directories(mylib PUBLIC include)

# define executable named main for experimenting and debugging code
add_executable(main src/main.cpp)
target_compile_options(main PUBLIC -g -O0)
target_link_libraries(main mylib)

# tests are added by declaring a target, in this case 'tests'. additional tests
# can be added by expanding the test cases in 'src/tests.cpp' or an additional
# target via 'add_executable'
enable_testing()
add_subdirectory(tests)

