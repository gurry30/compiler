# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sunnight/CompilerProject-2020Spring-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunnight/CompilerProject-2020Spring-master/build

# Utility rule file for ExperimentalTest.

# Include the progress variables for this target.
include jsoncpp-build/CMakeFiles/ExperimentalTest.dir/progress.make

jsoncpp-build/CMakeFiles/ExperimentalTest:
	cd /home/sunnight/CompilerProject-2020Spring-master/build/jsoncpp-build && /usr/bin/ctest -D ExperimentalTest

ExperimentalTest: jsoncpp-build/CMakeFiles/ExperimentalTest
ExperimentalTest: jsoncpp-build/CMakeFiles/ExperimentalTest.dir/build.make

.PHONY : ExperimentalTest

# Rule to build all files generated by this target.
jsoncpp-build/CMakeFiles/ExperimentalTest.dir/build: ExperimentalTest

.PHONY : jsoncpp-build/CMakeFiles/ExperimentalTest.dir/build

jsoncpp-build/CMakeFiles/ExperimentalTest.dir/clean:
	cd /home/sunnight/CompilerProject-2020Spring-master/build/jsoncpp-build && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalTest.dir/cmake_clean.cmake
.PHONY : jsoncpp-build/CMakeFiles/ExperimentalTest.dir/clean

jsoncpp-build/CMakeFiles/ExperimentalTest.dir/depend:
	cd /home/sunnight/CompilerProject-2020Spring-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunnight/CompilerProject-2020Spring-master /home/sunnight/CompilerProject-2020Spring-master/3rdparty/jsoncpp /home/sunnight/CompilerProject-2020Spring-master/build /home/sunnight/CompilerProject-2020Spring-master/build/jsoncpp-build /home/sunnight/CompilerProject-2020Spring-master/build/jsoncpp-build/CMakeFiles/ExperimentalTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : jsoncpp-build/CMakeFiles/ExperimentalTest.dir/depend

