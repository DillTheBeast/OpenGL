# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dillonmaltese/Documents/GitHub/OpenGL/build

# Include any dependencies generated for this target.
include test/gtx/CMakeFiles/test-gtx_integer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/gtx/CMakeFiles/test-gtx_integer.dir/compiler_depend.make

# Include the progress variables for this target.
include test/gtx/CMakeFiles/test-gtx_integer.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtx/CMakeFiles/test-gtx_integer.dir/flags.make

test/gtx/CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o: test/gtx/CMakeFiles/test-gtx_integer.dir/flags.make
test/gtx/CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o: /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtx/gtx_integer.cpp
test/gtx/CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o: test/gtx/CMakeFiles/test-gtx_integer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dillonmaltese/Documents/GitHub/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtx/CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtx && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/gtx/CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o -MF CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o.d -o CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o -c /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtx/gtx_integer.cpp

test/gtx/CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.i"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtx && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtx/gtx_integer.cpp > CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.i

test/gtx/CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.s"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtx && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtx/gtx_integer.cpp -o CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.s

# Object files for target test-gtx_integer
test__gtx_integer_OBJECTS = \
"CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o"

# External object files for target test-gtx_integer
test__gtx_integer_EXTERNAL_OBJECTS =

test/gtx/test-gtx_integer: test/gtx/CMakeFiles/test-gtx_integer.dir/gtx_integer.cpp.o
test/gtx/test-gtx_integer: test/gtx/CMakeFiles/test-gtx_integer.dir/build.make
test/gtx/test-gtx_integer: test/gtx/CMakeFiles/test-gtx_integer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dillonmaltese/Documents/GitHub/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtx_integer"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtx_integer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtx/CMakeFiles/test-gtx_integer.dir/build: test/gtx/test-gtx_integer
.PHONY : test/gtx/CMakeFiles/test-gtx_integer.dir/build

test/gtx/CMakeFiles/test-gtx_integer.dir/clean:
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtx && $(CMAKE_COMMAND) -P CMakeFiles/test-gtx_integer.dir/cmake_clean.cmake
.PHONY : test/gtx/CMakeFiles/test-gtx_integer.dir/clean

test/gtx/CMakeFiles/test-gtx_integer.dir/depend:
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtx /Users/dillonmaltese/Documents/GitHub/OpenGL/build /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtx /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtx/CMakeFiles/test-gtx_integer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtx/CMakeFiles/test-gtx_integer.dir/depend

