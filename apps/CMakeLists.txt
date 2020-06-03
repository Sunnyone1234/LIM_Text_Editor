### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" 
IS_IN_SOURCE_DIR)
if(EXISTS "${IS_IN_SOURCE_DIR}")
    message(FATAL_ERROR "You cannot build in a source 
    directory (or any directory with a CMakeLists.txt file). 
    Please make a build subdirectory with ¡®mkdir build¡¯.")
endif()

#Add paths in which the linker should find path to src
link_directories(${LIM_Text_Editor_SOURCE_DIR}/src)

#Add excutable
add_executable(MainProject main.cpp)

#Link excutable with libs
target_link_libraries(MainProject Libs)