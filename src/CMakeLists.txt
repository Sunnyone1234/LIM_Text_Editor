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

find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

#find all source code and save these name in SRC_DIR
aux_source_directory(. SRC_DIR)

#create static link package
add_library(headers INTERFACE)
target_include_directories(headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/headerfiles)

#Add excutable
if(WIN32)
    #set subsystem windows
     add_executable(MainProject WIN32 ${SRC_DIR})
 else()
     add_executable(MainProject ${SRC_DIR})
 endif()

#Link excutable with libs
#target_link_libraries(MainProject PRIVATE Libs sqlite3)
target_link_libraries(MainProject PRIVATE headers ${wxWidgets_LIBRARIES})