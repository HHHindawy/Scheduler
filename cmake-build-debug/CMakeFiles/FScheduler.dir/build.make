# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macpro/Documents/Term7/OS/FScheduler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FScheduler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FScheduler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FScheduler.dir/flags.make

CMakeFiles/FScheduler.dir/main.c.o: CMakeFiles/FScheduler.dir/flags.make
CMakeFiles/FScheduler.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FScheduler.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FScheduler.dir/main.c.o   -c /Users/macpro/Documents/Term7/OS/FScheduler/main.c

CMakeFiles/FScheduler.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FScheduler.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/macpro/Documents/Term7/OS/FScheduler/main.c > CMakeFiles/FScheduler.dir/main.c.i

CMakeFiles/FScheduler.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FScheduler.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/macpro/Documents/Term7/OS/FScheduler/main.c -o CMakeFiles/FScheduler.dir/main.c.s

CMakeFiles/FScheduler.dir/main.c.o.requires:

.PHONY : CMakeFiles/FScheduler.dir/main.c.o.requires

CMakeFiles/FScheduler.dir/main.c.o.provides: CMakeFiles/FScheduler.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/FScheduler.dir/build.make CMakeFiles/FScheduler.dir/main.c.o.provides.build
.PHONY : CMakeFiles/FScheduler.dir/main.c.o.provides

CMakeFiles/FScheduler.dir/main.c.o.provides.build: CMakeFiles/FScheduler.dir/main.c.o


CMakeFiles/FScheduler.dir/minHeap.c.o: CMakeFiles/FScheduler.dir/flags.make
CMakeFiles/FScheduler.dir/minHeap.c.o: ../minHeap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/FScheduler.dir/minHeap.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FScheduler.dir/minHeap.c.o   -c /Users/macpro/Documents/Term7/OS/FScheduler/minHeap.c

CMakeFiles/FScheduler.dir/minHeap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FScheduler.dir/minHeap.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/macpro/Documents/Term7/OS/FScheduler/minHeap.c > CMakeFiles/FScheduler.dir/minHeap.c.i

CMakeFiles/FScheduler.dir/minHeap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FScheduler.dir/minHeap.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/macpro/Documents/Term7/OS/FScheduler/minHeap.c -o CMakeFiles/FScheduler.dir/minHeap.c.s

CMakeFiles/FScheduler.dir/minHeap.c.o.requires:

.PHONY : CMakeFiles/FScheduler.dir/minHeap.c.o.requires

CMakeFiles/FScheduler.dir/minHeap.c.o.provides: CMakeFiles/FScheduler.dir/minHeap.c.o.requires
	$(MAKE) -f CMakeFiles/FScheduler.dir/build.make CMakeFiles/FScheduler.dir/minHeap.c.o.provides.build
.PHONY : CMakeFiles/FScheduler.dir/minHeap.c.o.provides

CMakeFiles/FScheduler.dir/minHeap.c.o.provides.build: CMakeFiles/FScheduler.dir/minHeap.c.o


CMakeFiles/FScheduler.dir/queue.c.o: CMakeFiles/FScheduler.dir/flags.make
CMakeFiles/FScheduler.dir/queue.c.o: ../queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/FScheduler.dir/queue.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FScheduler.dir/queue.c.o   -c /Users/macpro/Documents/Term7/OS/FScheduler/queue.c

CMakeFiles/FScheduler.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FScheduler.dir/queue.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/macpro/Documents/Term7/OS/FScheduler/queue.c > CMakeFiles/FScheduler.dir/queue.c.i

CMakeFiles/FScheduler.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FScheduler.dir/queue.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/macpro/Documents/Term7/OS/FScheduler/queue.c -o CMakeFiles/FScheduler.dir/queue.c.s

CMakeFiles/FScheduler.dir/queue.c.o.requires:

.PHONY : CMakeFiles/FScheduler.dir/queue.c.o.requires

CMakeFiles/FScheduler.dir/queue.c.o.provides: CMakeFiles/FScheduler.dir/queue.c.o.requires
	$(MAKE) -f CMakeFiles/FScheduler.dir/build.make CMakeFiles/FScheduler.dir/queue.c.o.provides.build
.PHONY : CMakeFiles/FScheduler.dir/queue.c.o.provides

CMakeFiles/FScheduler.dir/queue.c.o.provides.build: CMakeFiles/FScheduler.dir/queue.c.o


# Object files for target FScheduler
FScheduler_OBJECTS = \
"CMakeFiles/FScheduler.dir/main.c.o" \
"CMakeFiles/FScheduler.dir/minHeap.c.o" \
"CMakeFiles/FScheduler.dir/queue.c.o"

# External object files for target FScheduler
FScheduler_EXTERNAL_OBJECTS =

FScheduler: CMakeFiles/FScheduler.dir/main.c.o
FScheduler: CMakeFiles/FScheduler.dir/minHeap.c.o
FScheduler: CMakeFiles/FScheduler.dir/queue.c.o
FScheduler: CMakeFiles/FScheduler.dir/build.make
FScheduler: CMakeFiles/FScheduler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable FScheduler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FScheduler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FScheduler.dir/build: FScheduler

.PHONY : CMakeFiles/FScheduler.dir/build

CMakeFiles/FScheduler.dir/requires: CMakeFiles/FScheduler.dir/main.c.o.requires
CMakeFiles/FScheduler.dir/requires: CMakeFiles/FScheduler.dir/minHeap.c.o.requires
CMakeFiles/FScheduler.dir/requires: CMakeFiles/FScheduler.dir/queue.c.o.requires

.PHONY : CMakeFiles/FScheduler.dir/requires

CMakeFiles/FScheduler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FScheduler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FScheduler.dir/clean

CMakeFiles/FScheduler.dir/depend:
	cd /Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macpro/Documents/Term7/OS/FScheduler /Users/macpro/Documents/Term7/OS/FScheduler /Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug /Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug /Users/macpro/Documents/Term7/OS/FScheduler/cmake-build-debug/CMakeFiles/FScheduler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FScheduler.dir/depend

