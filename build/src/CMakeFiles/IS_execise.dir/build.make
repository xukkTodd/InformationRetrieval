# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/actev/IS/IS_execise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/actev/IS/IS_execise/build

# Include any dependencies generated for this target.
include src/CMakeFiles/IS_execise.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/IS_execise.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/IS_execise.dir/flags.make

src/CMakeFiles/IS_execise.dir/main.cpp.o: src/CMakeFiles/IS_execise.dir/flags.make
src/CMakeFiles/IS_execise.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/actev/IS/IS_execise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/IS_execise.dir/main.cpp.o"
	cd /home/actev/IS/IS_execise/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IS_execise.dir/main.cpp.o -c /home/actev/IS/IS_execise/src/main.cpp

src/CMakeFiles/IS_execise.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IS_execise.dir/main.cpp.i"
	cd /home/actev/IS/IS_execise/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/actev/IS/IS_execise/src/main.cpp > CMakeFiles/IS_execise.dir/main.cpp.i

src/CMakeFiles/IS_execise.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IS_execise.dir/main.cpp.s"
	cd /home/actev/IS/IS_execise/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/actev/IS/IS_execise/src/main.cpp -o CMakeFiles/IS_execise.dir/main.cpp.s

src/CMakeFiles/IS_execise.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/IS_execise.dir/main.cpp.o.requires

src/CMakeFiles/IS_execise.dir/main.cpp.o.provides: src/CMakeFiles/IS_execise.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/IS_execise.dir/build.make src/CMakeFiles/IS_execise.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/IS_execise.dir/main.cpp.o.provides

src/CMakeFiles/IS_execise.dir/main.cpp.o.provides.build: src/CMakeFiles/IS_execise.dir/main.cpp.o


src/CMakeFiles/IS_execise.dir/chapter1.cpp.o: src/CMakeFiles/IS_execise.dir/flags.make
src/CMakeFiles/IS_execise.dir/chapter1.cpp.o: ../src/chapter1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/actev/IS/IS_execise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/IS_execise.dir/chapter1.cpp.o"
	cd /home/actev/IS/IS_execise/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IS_execise.dir/chapter1.cpp.o -c /home/actev/IS/IS_execise/src/chapter1.cpp

src/CMakeFiles/IS_execise.dir/chapter1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IS_execise.dir/chapter1.cpp.i"
	cd /home/actev/IS/IS_execise/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/actev/IS/IS_execise/src/chapter1.cpp > CMakeFiles/IS_execise.dir/chapter1.cpp.i

src/CMakeFiles/IS_execise.dir/chapter1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IS_execise.dir/chapter1.cpp.s"
	cd /home/actev/IS/IS_execise/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/actev/IS/IS_execise/src/chapter1.cpp -o CMakeFiles/IS_execise.dir/chapter1.cpp.s

src/CMakeFiles/IS_execise.dir/chapter1.cpp.o.requires:

.PHONY : src/CMakeFiles/IS_execise.dir/chapter1.cpp.o.requires

src/CMakeFiles/IS_execise.dir/chapter1.cpp.o.provides: src/CMakeFiles/IS_execise.dir/chapter1.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/IS_execise.dir/build.make src/CMakeFiles/IS_execise.dir/chapter1.cpp.o.provides.build
.PHONY : src/CMakeFiles/IS_execise.dir/chapter1.cpp.o.provides

src/CMakeFiles/IS_execise.dir/chapter1.cpp.o.provides.build: src/CMakeFiles/IS_execise.dir/chapter1.cpp.o


# Object files for target IS_execise
IS_execise_OBJECTS = \
"CMakeFiles/IS_execise.dir/main.cpp.o" \
"CMakeFiles/IS_execise.dir/chapter1.cpp.o"

# External object files for target IS_execise
IS_execise_EXTERNAL_OBJECTS =

../bin/IS_execise: src/CMakeFiles/IS_execise.dir/main.cpp.o
../bin/IS_execise: src/CMakeFiles/IS_execise.dir/chapter1.cpp.o
../bin/IS_execise: src/CMakeFiles/IS_execise.dir/build.make
../bin/IS_execise: src/CMakeFiles/IS_execise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/actev/IS/IS_execise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/IS_execise"
	cd /home/actev/IS/IS_execise/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IS_execise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/IS_execise.dir/build: ../bin/IS_execise

.PHONY : src/CMakeFiles/IS_execise.dir/build

src/CMakeFiles/IS_execise.dir/requires: src/CMakeFiles/IS_execise.dir/main.cpp.o.requires
src/CMakeFiles/IS_execise.dir/requires: src/CMakeFiles/IS_execise.dir/chapter1.cpp.o.requires

.PHONY : src/CMakeFiles/IS_execise.dir/requires

src/CMakeFiles/IS_execise.dir/clean:
	cd /home/actev/IS/IS_execise/build/src && $(CMAKE_COMMAND) -P CMakeFiles/IS_execise.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/IS_execise.dir/clean

src/CMakeFiles/IS_execise.dir/depend:
	cd /home/actev/IS/IS_execise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/actev/IS/IS_execise /home/actev/IS/IS_execise/src /home/actev/IS/IS_execise/build /home/actev/IS/IS_execise/build/src /home/actev/IS/IS_execise/build/src/CMakeFiles/IS_execise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/IS_execise.dir/depend
