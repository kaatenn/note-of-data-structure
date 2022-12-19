cmake_minimum_required(VERSION 3.23)
project(note_of_data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(note_of_data_structure tree/public/TreeNode.cpp tree/public/TreeNode.h tree/main.cpp tree/public/ITreeNode.cpp tree/public/ITreeNode.h)

#[[add_executable(note_of_data_structure Orthogonal/OrthogonalList.cpp Orthogonal/OrthogonalList.h Orthogonal/main.cpp)]]

#[[add_executable(note_of_data_structure matrix/multiple/multiple.cpp matrix/public/Matrix.cpp matrix/public/Matrix.h)]]

#[[add_executable(note_of_data_structure matrix/transposed/main.cpp matrix/public/Matrix.cpp matrix/public/Matrix.h)]]

#[[add_executable(note_of_data_structure test/test.cpp)]]

#[[add_executable(note_of_data_structure calculator/main.cpp)]]

#[[
add_executable(note_of_data_structure Josephus/main.cpp)
]]

#[[
add_executable(note_of_data_structure xor/main.cpp)
]]

#[[
add_executable(note_of_data_structure polynomial/main.cpp polynomial/Polynomial.cpp polynomial/Polynomial.h polynomial/NumberLink.cpp polynomial/NumberLink.h)
]]
