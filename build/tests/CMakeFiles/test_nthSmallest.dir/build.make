# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zeculesu/Desktop/Artemia/algo_dop/dop2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_nthSmallest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_nthSmallest.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_nthSmallest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_nthSmallest.dir/flags.make

tests/CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o: tests/CMakeFiles/test_nthSmallest.dir/flags.make
tests/CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o: /home/zeculesu/Desktop/Artemia/algo_dop/dop2/tests/test_nthSmallest.cpp
tests/CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o: tests/CMakeFiles/test_nthSmallest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o"
	cd /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o -MF CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o.d -o CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o -c /home/zeculesu/Desktop/Artemia/algo_dop/dop2/tests/test_nthSmallest.cpp

tests/CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.i"
	cd /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeculesu/Desktop/Artemia/algo_dop/dop2/tests/test_nthSmallest.cpp > CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.i

tests/CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.s"
	cd /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeculesu/Desktop/Artemia/algo_dop/dop2/tests/test_nthSmallest.cpp -o CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.s

# Object files for target test_nthSmallest
test_nthSmallest_OBJECTS = \
"CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o"

# External object files for target test_nthSmallest
test_nthSmallest_EXTERNAL_OBJECTS =

tests/test_nthSmallest: tests/CMakeFiles/test_nthSmallest.dir/test_nthSmallest.cpp.o
tests/test_nthSmallest: tests/CMakeFiles/test_nthSmallest.dir/build.make
tests/test_nthSmallest: src/libBFPRTLib.a
tests/test_nthSmallest: /usr/lib/x86_64-linux-gnu/libgtest_main.a
tests/test_nthSmallest: /usr/lib/x86_64-linux-gnu/libgtest.a
tests/test_nthSmallest: tests/CMakeFiles/test_nthSmallest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_nthSmallest"
	cd /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_nthSmallest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_nthSmallest.dir/build: tests/test_nthSmallest
.PHONY : tests/CMakeFiles/test_nthSmallest.dir/build

tests/CMakeFiles/test_nthSmallest.dir/clean:
	cd /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_nthSmallest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_nthSmallest.dir/clean

tests/CMakeFiles/test_nthSmallest.dir/depend:
	cd /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zeculesu/Desktop/Artemia/algo_dop/dop2 /home/zeculesu/Desktop/Artemia/algo_dop/dop2/tests /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/tests /home/zeculesu/Desktop/Artemia/algo_dop/dop2/build/tests/CMakeFiles/test_nthSmallest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/test_nthSmallest.dir/depend

