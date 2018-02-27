cmake_minimum_required(VERSION 3.0.0)

project(lcsc)

include_directories("include")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_CXX_STANDARD 14)

add_executable(simple_example "example/simple_example.cpp" "src/rng/lcrng.cpp" "src/rng/distributions.cpp" include/test/test.h)
