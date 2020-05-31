# Set minimum version of CMake
# To find CMake version run
# $ cmake --version
cmake_minimum_required(VERSION 2.6)

# Set project name
project(LIM_Text_Editor)

#Enable test
enable_testing()

#Add an executable
add_executable(main main.cpp)

#Add test
add_test(unittests main)

#add_test(test2 main)
#set_tests_properties(test2 PROPERTIES PASS_REGULAR_EXPRESSION "some words here")
