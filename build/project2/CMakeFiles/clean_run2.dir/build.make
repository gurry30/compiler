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

# Utility rule file for clean_run2.

# Include the progress variables for this target.
include project2/CMakeFiles/clean_run2.dir/progress.make

project2/CMakeFiles/clean_run2:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sunnight/CompilerProject-2020Spring-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "run generated clean in /home/sunnight/CompilerProject-2020Spring-master/project2"
	cd /home/sunnight/CompilerProject-2020Spring-master/project2 && /home/sunnight/CompilerProject-2020Spring-master/build/project2/cleanf2

clean_run2: project2/CMakeFiles/clean_run2
clean_run2: project2/CMakeFiles/clean_run2.dir/build.make

.PHONY : clean_run2

# Rule to build all files generated by this target.
project2/CMakeFiles/clean_run2.dir/build: clean_run2

.PHONY : project2/CMakeFiles/clean_run2.dir/build

project2/CMakeFiles/clean_run2.dir/clean:
	cd /home/sunnight/CompilerProject-2020Spring-master/build/project2 && $(CMAKE_COMMAND) -P CMakeFiles/clean_run2.dir/cmake_clean.cmake
.PHONY : project2/CMakeFiles/clean_run2.dir/clean

project2/CMakeFiles/clean_run2.dir/depend:
	cd /home/sunnight/CompilerProject-2020Spring-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunnight/CompilerProject-2020Spring-master /home/sunnight/CompilerProject-2020Spring-master/project2 /home/sunnight/CompilerProject-2020Spring-master/build /home/sunnight/CompilerProject-2020Spring-master/build/project2 /home/sunnight/CompilerProject-2020Spring-master/build/project2/CMakeFiles/clean_run2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project2/CMakeFiles/clean_run2.dir/depend

