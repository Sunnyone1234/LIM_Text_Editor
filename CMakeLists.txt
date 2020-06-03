# Set minimum version of CMake
# To find CMake version run
# $ cmake --version
cmake_minimum_required(VERSION 2.6)

# Set project name
project(LIM_Text_Editor)


#Add subdirector
add_subdirectory(apps)
add_subdirectory(cmake)
add_subdirectory(docs)
add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(scripts)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" 
IS_IN_SOURCE_DIR)
if(EXISTS "${IS_IN_SOURCE_DIR}")
    message(FATAL_ERROR "You cannot build in a source 
    directory (or any directory with a CMakeLists.txt file). 
    Please make a build subdirectory with ¡®mkdir build¡¯.")
endif()

#Enable test
enable_testing()

#Add test
add_test(unittests MainProject)

#add_test(test2 main)
#set_tests_properties(test2 PROPERTIES PASS_REGULAR_EXPRESSION "some words here")
