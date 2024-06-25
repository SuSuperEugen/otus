cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(sequentialContainer sequentialContainer.cpp sequentialContainer.hpp)
set_target_properties(sequentialContainer PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
add_executable(ListTypeContainer ListTypeContainer.cpp ListTypeContainer.hpp)
set_target_properties(ListTypeContainer PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)



