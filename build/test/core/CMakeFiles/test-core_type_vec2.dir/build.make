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
include test/core/CMakeFiles/test-core_type_vec2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/core/CMakeFiles/test-core_type_vec2.dir/compiler_depend.make

# Include the progress variables for this target.
include test/core/CMakeFiles/test-core_type_vec2.dir/progress.make

# Include the compile flags for this target's objects.
include test/core/CMakeFiles/test-core_type_vec2.dir/flags.make

test/core/CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o: test/core/CMakeFiles/test-core_type_vec2.dir/flags.make
test/core/CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o: /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/core/core_type_vec2.cpp
test/core/CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o: test/core/CMakeFiles/test-core_type_vec2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dillonmaltese/Documents/GitHub/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/core/CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/core && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/core/CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o -MF CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o.d -o CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o -c /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/core/core_type_vec2.cpp

test/core/CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.i"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/core && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/core/core_type_vec2.cpp > CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.i

test/core/CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.s"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/core && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/core/core_type_vec2.cpp -o CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.s

# Object files for target test-core_type_vec2
test__core_type_vec2_OBJECTS = \
"CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o"

# External object files for target test-core_type_vec2
test__core_type_vec2_EXTERNAL_OBJECTS =

test/core/test-core_type_vec2: test/core/CMakeFiles/test-core_type_vec2.dir/core_type_vec2.cpp.o
test/core/test-core_type_vec2: test/core/CMakeFiles/test-core_type_vec2.dir/build.make
test/core/test-core_type_vec2: test/core/CMakeFiles/test-core_type_vec2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dillonmaltese/Documents/GitHub/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-core_type_vec2"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-core_type_vec2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/core/CMakeFiles/test-core_type_vec2.dir/build: test/core/test-core_type_vec2
.PHONY : test/core/CMakeFiles/test-core_type_vec2.dir/build

test/core/CMakeFiles/test-core_type_vec2.dir/clean:
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/core && $(CMAKE_COMMAND) -P CMakeFiles/test-core_type_vec2.dir/cmake_clean.cmake
.PHONY : test/core/CMakeFiles/test-core_type_vec2.dir/clean

test/core/CMakeFiles/test-core_type_vec2.dir/depend:
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/core /Users/dillonmaltese/Documents/GitHub/OpenGL/build /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/core /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/core/CMakeFiles/test-core_type_vec2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/core/CMakeFiles/test-core_type_vec2.dir/depend

