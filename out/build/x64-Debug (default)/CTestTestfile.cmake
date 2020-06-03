# CMake generated Testfile for 
# Source directory: F:/OneDrive/code/Repository
# Build directory: F:/OneDrive/code/Repository/out/build/x64-Debug (default)
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unittests "MainProject")
set_tests_properties(unittests PROPERTIES  _BACKTRACE_TRIPLES "F:/OneDrive/code/Repository/CMakeLists.txt;32;add_test;F:/OneDrive/code/Repository/CMakeLists.txt;0;")
subdirs("apps")
subdirs("cmake")
subdirs("docs")
subdirs("extern")
subdirs("src")
subdirs("tests")
subdirs("scripts")
