cmake_minimum_required(VERSION 3.0.0)

project(lcsc)

include_directories("include")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(simple_example "example/simple_example.cpp" "src/rng/lcrng.cpp")
