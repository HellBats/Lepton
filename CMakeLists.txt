cmake_minimum_required(VERSION 3.29.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(QuantaVM VERSION 1.0)
file(GLOB_RECURSE SRC_FILES src/*.c)
add_executable(Quanta ${SRC_FILES})
target_include_directories(Quanta PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)