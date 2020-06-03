### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" 
IS_IN_SOURCE_DIR)
if(EXISTS "${IS_IN_SOURCE_DIR}")
    message(FATAL_ERROR "You cannot build in a source 
    directory (or any directory with a CMakeLists.txt file). 
    Please make a build subdirectory with ¡®mkdir build¡¯.")
endif()

#find all source code and save these name in DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

#create static link package
add_library(Libs ${DIR_LIB_SRCS})