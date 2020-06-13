### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" 
IS_IN_SOURCE_DIR)
if(EXISTS "${IS_IN_SOURCE_DIR}")
    message(FATAL_ERROR "You cannot build in a source 
    directory (or any directory with a CMakeLists.txt file). 
    Please make a build subdirectory with ¡®mkdir build¡¯.")
endif()

find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

#find all source code and save these name in SRC_DIR
aux_source_directory(. SRC_DIR)

#Add excutable
if(WIN32)
    #set subsystem windows
     add_executable(MainProject WIN32 ${SRC_DIR})
 else()
     add_executable(MainProject ${SRC_DIR})
 endif()

#Link excutable with headers dirctor
target_include_directories(MainProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)
#Link excutable with libs
target_link_libraries(MainProject PRIVATE ${wxWidgets_LIBRARIES})