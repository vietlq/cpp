# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vietlq/projects/viet-github-cpp/boost_ipc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-make

# Include any dependencies generated for this target.
include CMakeFiles/boost_ipc_inspector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boost_ipc_inspector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boost_ipc_inspector.dir/flags.make

CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o: CMakeFiles/boost_ipc_inspector.dir/flags.make
CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o: ../inspector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-make/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o -c /Users/vietlq/projects/viet-github-cpp/boost_ipc/inspector.cpp

CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/vietlq/projects/viet-github-cpp/boost_ipc/inspector.cpp > CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.i

CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/vietlq/projects/viet-github-cpp/boost_ipc/inspector.cpp -o CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.s

CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o.requires:
.PHONY : CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o.requires

CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o.provides: CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o.requires
	$(MAKE) -f CMakeFiles/boost_ipc_inspector.dir/build.make CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o.provides.build
.PHONY : CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o.provides

CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o.provides.build: CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o

# Object files for target boost_ipc_inspector
boost_ipc_inspector_OBJECTS = \
"CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o"

# External object files for target boost_ipc_inspector
boost_ipc_inspector_EXTERNAL_OBJECTS =

boost_ipc_inspector: CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o
boost_ipc_inspector: CMakeFiles/boost_ipc_inspector.dir/build.make
boost_ipc_inspector: CMakeFiles/boost_ipc_inspector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable boost_ipc_inspector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_ipc_inspector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boost_ipc_inspector.dir/build: boost_ipc_inspector
.PHONY : CMakeFiles/boost_ipc_inspector.dir/build

CMakeFiles/boost_ipc_inspector.dir/requires: CMakeFiles/boost_ipc_inspector.dir/inspector.cpp.o.requires
.PHONY : CMakeFiles/boost_ipc_inspector.dir/requires

CMakeFiles/boost_ipc_inspector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boost_ipc_inspector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boost_ipc_inspector.dir/clean

CMakeFiles/boost_ipc_inspector.dir/depend:
	cd /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-make && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vietlq/projects/viet-github-cpp/boost_ipc /Users/vietlq/projects/viet-github-cpp/boost_ipc /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-make /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-make /Users/vietlq/projects/viet-github-cpp/boost_ipc/build-make/CMakeFiles/boost_ipc_inspector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boost_ipc_inspector.dir/depend

