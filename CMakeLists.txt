cmake_minimum_required(VERSION 3.10)

project(cpp_programs LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_MODULE_PATH "/usr/lib/cmake")
find_package(QPANDA)

add_subdirectory(hw3)



