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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zjh/work/beaglebone/module/relay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zjh/work/beaglebone/module/relay/build

# Include any dependencies generated for this target.
include CMakeFiles/beaglebone_relay.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/beaglebone_relay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/beaglebone_relay.dir/flags.make

CMakeFiles/beaglebone_relay.dir/function/relay.c.o: CMakeFiles/beaglebone_relay.dir/flags.make
CMakeFiles/beaglebone_relay.dir/function/relay.c.o: ../function/relay.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zjh/work/beaglebone/module/relay/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/beaglebone_relay.dir/function/relay.c.o"
	/home/zjh/bbb/cross_tool/gcc-linaro-arm-linux-gnueabihf-4.8-2013.10_linux/bin/arm-linux-gnueabihf-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/beaglebone_relay.dir/function/relay.c.o   -c /home/zjh/work/beaglebone/module/relay/function/relay.c

CMakeFiles/beaglebone_relay.dir/function/relay.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/beaglebone_relay.dir/function/relay.c.i"
	/home/zjh/bbb/cross_tool/gcc-linaro-arm-linux-gnueabihf-4.8-2013.10_linux/bin/arm-linux-gnueabihf-gcc  $(C_DEFINES) $(C_FLAGS) -E /home/zjh/work/beaglebone/module/relay/function/relay.c > CMakeFiles/beaglebone_relay.dir/function/relay.c.i

CMakeFiles/beaglebone_relay.dir/function/relay.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/beaglebone_relay.dir/function/relay.c.s"
	/home/zjh/bbb/cross_tool/gcc-linaro-arm-linux-gnueabihf-4.8-2013.10_linux/bin/arm-linux-gnueabihf-gcc  $(C_DEFINES) $(C_FLAGS) -S /home/zjh/work/beaglebone/module/relay/function/relay.c -o CMakeFiles/beaglebone_relay.dir/function/relay.c.s

CMakeFiles/beaglebone_relay.dir/function/relay.c.o.requires:
.PHONY : CMakeFiles/beaglebone_relay.dir/function/relay.c.o.requires

CMakeFiles/beaglebone_relay.dir/function/relay.c.o.provides: CMakeFiles/beaglebone_relay.dir/function/relay.c.o.requires
	$(MAKE) -f CMakeFiles/beaglebone_relay.dir/build.make CMakeFiles/beaglebone_relay.dir/function/relay.c.o.provides.build
.PHONY : CMakeFiles/beaglebone_relay.dir/function/relay.c.o.provides

CMakeFiles/beaglebone_relay.dir/function/relay.c.o.provides.build: CMakeFiles/beaglebone_relay.dir/function/relay.c.o

# Object files for target beaglebone_relay
beaglebone_relay_OBJECTS = \
"CMakeFiles/beaglebone_relay.dir/function/relay.c.o"

# External object files for target beaglebone_relay
beaglebone_relay_EXTERNAL_OBJECTS =

libbeaglebone_relay.so: CMakeFiles/beaglebone_relay.dir/function/relay.c.o
libbeaglebone_relay.so: CMakeFiles/beaglebone_relay.dir/build.make
libbeaglebone_relay.so: CMakeFiles/beaglebone_relay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library libbeaglebone_relay.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/beaglebone_relay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/beaglebone_relay.dir/build: libbeaglebone_relay.so
.PHONY : CMakeFiles/beaglebone_relay.dir/build

CMakeFiles/beaglebone_relay.dir/requires: CMakeFiles/beaglebone_relay.dir/function/relay.c.o.requires
.PHONY : CMakeFiles/beaglebone_relay.dir/requires

CMakeFiles/beaglebone_relay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/beaglebone_relay.dir/cmake_clean.cmake
.PHONY : CMakeFiles/beaglebone_relay.dir/clean

CMakeFiles/beaglebone_relay.dir/depend:
	cd /home/zjh/work/beaglebone/module/relay/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zjh/work/beaglebone/module/relay /home/zjh/work/beaglebone/module/relay /home/zjh/work/beaglebone/module/relay/build /home/zjh/work/beaglebone/module/relay/build /home/zjh/work/beaglebone/module/relay/build/CMakeFiles/beaglebone_relay.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/beaglebone_relay.dir/depend
