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
include test/gtc/CMakeFiles/test-gtc_ulp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/gtc/CMakeFiles/test-gtc_ulp.dir/compiler_depend.make

# Include the progress variables for this target.
include test/gtc/CMakeFiles/test-gtc_ulp.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtc/CMakeFiles/test-gtc_ulp.dir/flags.make

test/gtc/CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o: test/gtc/CMakeFiles/test-gtc_ulp.dir/flags.make
test/gtc/CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o: /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtc/gtc_ulp.cpp
test/gtc/CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o: test/gtc/CMakeFiles/test-gtc_ulp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dillonmaltese/Documents/GitHub/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtc/CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtc && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/gtc/CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o -MF CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o.d -o CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o -c /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtc/gtc_ulp.cpp

test/gtc/CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.i"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtc && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtc/gtc_ulp.cpp > CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.i

test/gtc/CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.s"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtc && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtc/gtc_ulp.cpp -o CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.s

# Object files for target test-gtc_ulp
test__gtc_ulp_OBJECTS = \
"CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o"

# External object files for target test-gtc_ulp
test__gtc_ulp_EXTERNAL_OBJECTS =

test/gtc/test-gtc_ulp: test/gtc/CMakeFiles/test-gtc_ulp.dir/gtc_ulp.cpp.o
test/gtc/test-gtc_ulp: test/gtc/CMakeFiles/test-gtc_ulp.dir/build.make
test/gtc/test-gtc_ulp: test/gtc/CMakeFiles/test-gtc_ulp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dillonmaltese/Documents/GitHub/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtc_ulp"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtc_ulp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtc/CMakeFiles/test-gtc_ulp.dir/build: test/gtc/test-gtc_ulp
.PHONY : test/gtc/CMakeFiles/test-gtc_ulp.dir/build

test/gtc/CMakeFiles/test-gtc_ulp.dir/clean:
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtc && $(CMAKE_COMMAND) -P CMakeFiles/test-gtc_ulp.dir/cmake_clean.cmake
.PHONY : test/gtc/CMakeFiles/test-gtc_ulp.dir/clean

test/gtc/CMakeFiles/test-gtc_ulp.dir/depend:
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/gtc /Users/dillonmaltese/Documents/GitHub/OpenGL/build /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtc /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/gtc/CMakeFiles/test-gtc_ulp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtc/CMakeFiles/test-gtc_ulp.dir/depend

