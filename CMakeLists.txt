cmake_minimum_required(VERSION 3.28)
project(scsd_lib C)

set(CMAKE_C_STANDARD 11)

# Enable testing
enable_testing()

# Add the library
add_library(scsd_lib
        lib/tiny_stack_trace/tiny_stack_trace.c
        lib/crc/crc.c)

# Include directories
target_include_directories(scsd_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/tiny_stack_trace
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/crc
)

# Add the executable for running the tests
add_executable(scsd_lib_tests
        main.c
        tests/unit/crc/test_crc.c
        tests/unit/tiny_stack_trace/test_tiny_stack_trace.c)

# Include directories for the test executable
target_include_directories(scsd_lib_tests
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/crc
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/tiny_stack_trace
)

# Link the test executable with the library
target_link_libraries(scsd_lib_tests scsd_lib)

# Add a test
add_test(NAME SCSD_LIB_TESTS COMMAND scsd_lib_tests)
