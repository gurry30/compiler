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

# Include any dependencies generated for this target.
include project1/CMakeFiles/cleanf.dir/depend.make

# Include the progress variables for this target.
include project1/CMakeFiles/cleanf.dir/progress.make

# Include the compile flags for this target's objects.
include project1/CMakeFiles/cleanf.dir/flags.make

project1/CMakeFiles/cleanf.dir/clean/clean.cc.o: project1/CMakeFiles/cleanf.dir/flags.make
project1/CMakeFiles/cleanf.dir/clean/clean.cc.o: ../project1/clean/clean.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunnight/CompilerProject-2020Spring-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object project1/CMakeFiles/cleanf.dir/clean/clean.cc.o"
	cd /home/sunnight/CompilerProject-2020Spring-master/build/project1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cleanf.dir/clean/clean.cc.o -c /home/sunnight/CompilerProject-2020Spring-master/project1/clean/clean.cc

project1/CMakeFiles/cleanf.dir/clean/clean.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cleanf.dir/clean/clean.cc.i"
	cd /home/sunnight/CompilerProject-2020Spring-master/build/project1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunnight/CompilerProject-2020Spring-master/project1/clean/clean.cc > CMakeFiles/cleanf.dir/clean/clean.cc.i

project1/CMakeFiles/cleanf.dir/clean/clean.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cleanf.dir/clean/clean.cc.s"
	cd /home/sunnight/CompilerProject-2020Spring-master/build/project1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunnight/CompilerProject-2020Spring-master/project1/clean/clean.cc -o CMakeFiles/cleanf.dir/clean/clean.cc.s

project1/CMakeFiles/cleanf.dir/clean/clean.cc.o.requires:

.PHONY : project1/CMakeFiles/cleanf.dir/clean/clean.cc.o.requires

project1/CMakeFiles/cleanf.dir/clean/clean.cc.o.provides: project1/CMakeFiles/cleanf.dir/clean/clean.cc.o.requires
	$(MAKE) -f project1/CMakeFiles/cleanf.dir/build.make project1/CMakeFiles/cleanf.dir/clean/clean.cc.o.provides.build
.PHONY : project1/CMakeFiles/cleanf.dir/clean/clean.cc.o.provides

project1/CMakeFiles/cleanf.dir/clean/clean.cc.o.provides.build: project1/CMakeFiles/cleanf.dir/clean/clean.cc.o


# Object files for target cleanf
cleanf_OBJECTS = \
"CMakeFiles/cleanf.dir/clean/clean.cc.o"

# External object files for target cleanf
cleanf_EXTERNAL_OBJECTS =

project1/cleanf: project1/CMakeFiles/cleanf.dir/clean/clean.cc.o
project1/cleanf: project1/CMakeFiles/cleanf.dir/build.make
project1/cleanf: project1/CMakeFiles/cleanf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunnight/CompilerProject-2020Spring-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cleanf"
	cd /home/sunnight/CompilerProject-2020Spring-master/build/project1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cleanf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
project1/CMakeFiles/cleanf.dir/build: project1/cleanf

.PHONY : project1/CMakeFiles/cleanf.dir/build

project1/CMakeFiles/cleanf.dir/requires: project1/CMakeFiles/cleanf.dir/clean/clean.cc.o.requires

.PHONY : project1/CMakeFiles/cleanf.dir/requires

project1/CMakeFiles/cleanf.dir/clean:
	cd /home/sunnight/CompilerProject-2020Spring-master/build/project1 && $(CMAKE_COMMAND) -P CMakeFiles/cleanf.dir/cmake_clean.cmake
.PHONY : project1/CMakeFiles/cleanf.dir/clean

project1/CMakeFiles/cleanf.dir/depend:
	cd /home/sunnight/CompilerProject-2020Spring-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunnight/CompilerProject-2020Spring-master /home/sunnight/CompilerProject-2020Spring-master/project1 /home/sunnight/CompilerProject-2020Spring-master/build /home/sunnight/CompilerProject-2020Spring-master/build/project1 /home/sunnight/CompilerProject-2020Spring-master/build/project1/CMakeFiles/cleanf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project1/CMakeFiles/cleanf.dir/depend

