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
include test/ext/CMakeFiles/test-ext_matrix_transform.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/ext/CMakeFiles/test-ext_matrix_transform.dir/compiler_depend.make

# Include the progress variables for this target.
include test/ext/CMakeFiles/test-ext_matrix_transform.dir/progress.make

# Include the compile flags for this target's objects.
include test/ext/CMakeFiles/test-ext_matrix_transform.dir/flags.make

test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o: test/ext/CMakeFiles/test-ext_matrix_transform.dir/flags.make
test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o: /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/ext/ext_matrix_transform.cpp
test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o: test/ext/CMakeFiles/test-ext_matrix_transform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dillonmaltese/Documents/GitHub/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/ext && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o -MF CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o.d -o CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o -c /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/ext/ext_matrix_transform.cpp

test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.i"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/ext && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/ext/ext_matrix_transform.cpp > CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.i

test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.s"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/ext && /opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/ext/ext_matrix_transform.cpp -o CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.s

# Object files for target test-ext_matrix_transform
test__ext_matrix_transform_OBJECTS = \
"CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o"

# External object files for target test-ext_matrix_transform
test__ext_matrix_transform_EXTERNAL_OBJECTS =

test/ext/test-ext_matrix_transform: test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.o
test/ext/test-ext_matrix_transform: test/ext/CMakeFiles/test-ext_matrix_transform.dir/build.make
test/ext/test-ext_matrix_transform: test/ext/CMakeFiles/test-ext_matrix_transform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dillonmaltese/Documents/GitHub/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-ext_matrix_transform"
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/ext && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-ext_matrix_transform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/ext/CMakeFiles/test-ext_matrix_transform.dir/build: test/ext/test-ext_matrix_transform
.PHONY : test/ext/CMakeFiles/test-ext_matrix_transform.dir/build

test/ext/CMakeFiles/test-ext_matrix_transform.dir/clean:
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/ext && $(CMAKE_COMMAND) -P CMakeFiles/test-ext_matrix_transform.dir/cmake_clean.cmake
.PHONY : test/ext/CMakeFiles/test-ext_matrix_transform.dir/clean

test/ext/CMakeFiles/test-ext_matrix_transform.dir/depend:
	cd /Users/dillonmaltese/Documents/GitHub/OpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm /Users/dillonmaltese/Documents/GitHub/OpenGL/VS/include/glm/test/ext /Users/dillonmaltese/Documents/GitHub/OpenGL/build /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/ext /Users/dillonmaltese/Documents/GitHub/OpenGL/build/test/ext/CMakeFiles/test-ext_matrix_transform.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/ext/CMakeFiles/test-ext_matrix_transform.dir/depend

