# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/julian/Documents/Development/maidsafe/branches/b-jc-nat-pmp/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/julian/Documents/Development/maidsafe/branches/b-jc-nat-pmp/src/build/OSX

# Utility rule file for NightlyCoverage.

CMakeFiles/NightlyCoverage:
	/usr/local/bin/ctest -D NightlyCoverage

NightlyCoverage: CMakeFiles/NightlyCoverage
NightlyCoverage: CMakeFiles/NightlyCoverage.dir/build.make
.PHONY : NightlyCoverage

# Rule to build all files generated by this target.
CMakeFiles/NightlyCoverage.dir/build: NightlyCoverage
.PHONY : CMakeFiles/NightlyCoverage.dir/build

CMakeFiles/NightlyCoverage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NightlyCoverage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NightlyCoverage.dir/clean

CMakeFiles/NightlyCoverage.dir/depend:
	cd /Users/julian/Documents/Development/maidsafe/branches/b-jc-nat-pmp/src/build/OSX && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/julian/Documents/Development/maidsafe/branches/b-jc-nat-pmp/src /Users/julian/Documents/Development/maidsafe/branches/b-jc-nat-pmp/src /Users/julian/Documents/Development/maidsafe/branches/b-jc-nat-pmp/src/build/OSX /Users/julian/Documents/Development/maidsafe/branches/b-jc-nat-pmp/src/build/OSX /Users/julian/Documents/Development/maidsafe/branches/b-jc-nat-pmp/src/build/OSX/CMakeFiles/NightlyCoverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NightlyCoverage.dir/depend
