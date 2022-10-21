cmake_minimum_required(VERSION 3.23)
project(note_of_data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(note_of_data_structure calculator/main.cpp)

#[[
add_executable(note_of_data_structure Josephus/main.cpp)
]]

#[[
add_executable(note_of_data_structure xor/main.cpp)
]]

#[[
add_executable(note_of_data_structure polynomial/main.cpp polynomial/Polynomial.cpp polynomial/Polynomial.h polynomial/NumberLink.cpp polynomial/NumberLink.h)
]]
