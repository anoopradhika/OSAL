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
CMAKE_SOURCE_DIR = /home/neo/build/OSAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neo/build/OSAL

# Include any dependencies generated for this target.
include Engine/CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include Engine/CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include Engine/CMakeFiles/engine.dir/flags.make

Engine/CMakeFiles/engine.dir/Engine.cpp.o: Engine/CMakeFiles/engine.dir/flags.make
Engine/CMakeFiles/engine.dir/Engine.cpp.o: Engine/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neo/build/OSAL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Engine/CMakeFiles/engine.dir/Engine.cpp.o"
	cd /home/neo/build/OSAL/Engine && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/Engine.cpp.o -c /home/neo/build/OSAL/Engine/Engine.cpp

Engine/CMakeFiles/engine.dir/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/Engine.cpp.i"
	cd /home/neo/build/OSAL/Engine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neo/build/OSAL/Engine/Engine.cpp > CMakeFiles/engine.dir/Engine.cpp.i

Engine/CMakeFiles/engine.dir/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/Engine.cpp.s"
	cd /home/neo/build/OSAL/Engine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neo/build/OSAL/Engine/Engine.cpp -o CMakeFiles/engine.dir/Engine.cpp.s

Engine/CMakeFiles/engine.dir/Engine.cpp.o.requires:

.PHONY : Engine/CMakeFiles/engine.dir/Engine.cpp.o.requires

Engine/CMakeFiles/engine.dir/Engine.cpp.o.provides: Engine/CMakeFiles/engine.dir/Engine.cpp.o.requires
	$(MAKE) -f Engine/CMakeFiles/engine.dir/build.make Engine/CMakeFiles/engine.dir/Engine.cpp.o.provides.build
.PHONY : Engine/CMakeFiles/engine.dir/Engine.cpp.o.provides

Engine/CMakeFiles/engine.dir/Engine.cpp.o.provides.build: Engine/CMakeFiles/engine.dir/Engine.cpp.o


Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o: Engine/CMakeFiles/engine.dir/flags.make
Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o: Engine/Engine_controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neo/build/OSAL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o"
	cd /home/neo/build/OSAL/Engine && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/Engine_controller.cpp.o -c /home/neo/build/OSAL/Engine/Engine_controller.cpp

Engine/CMakeFiles/engine.dir/Engine_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/Engine_controller.cpp.i"
	cd /home/neo/build/OSAL/Engine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neo/build/OSAL/Engine/Engine_controller.cpp > CMakeFiles/engine.dir/Engine_controller.cpp.i

Engine/CMakeFiles/engine.dir/Engine_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/Engine_controller.cpp.s"
	cd /home/neo/build/OSAL/Engine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neo/build/OSAL/Engine/Engine_controller.cpp -o CMakeFiles/engine.dir/Engine_controller.cpp.s

Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o.requires:

.PHONY : Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o.requires

Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o.provides: Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o.requires
	$(MAKE) -f Engine/CMakeFiles/engine.dir/build.make Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o.provides.build
.PHONY : Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o.provides

Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o.provides.build: Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o


# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/Engine.cpp.o" \
"CMakeFiles/engine.dir/Engine_controller.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

Engine/libengine.a: Engine/CMakeFiles/engine.dir/Engine.cpp.o
Engine/libengine.a: Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o
Engine/libengine.a: Engine/CMakeFiles/engine.dir/build.make
Engine/libengine.a: Engine/CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neo/build/OSAL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libengine.a"
	cd /home/neo/build/OSAL/Engine && $(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean_target.cmake
	cd /home/neo/build/OSAL/Engine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Engine/CMakeFiles/engine.dir/build: Engine/libengine.a

.PHONY : Engine/CMakeFiles/engine.dir/build

Engine/CMakeFiles/engine.dir/requires: Engine/CMakeFiles/engine.dir/Engine.cpp.o.requires
Engine/CMakeFiles/engine.dir/requires: Engine/CMakeFiles/engine.dir/Engine_controller.cpp.o.requires

.PHONY : Engine/CMakeFiles/engine.dir/requires

Engine/CMakeFiles/engine.dir/clean:
	cd /home/neo/build/OSAL/Engine && $(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : Engine/CMakeFiles/engine.dir/clean

Engine/CMakeFiles/engine.dir/depend:
	cd /home/neo/build/OSAL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neo/build/OSAL /home/neo/build/OSAL/Engine /home/neo/build/OSAL /home/neo/build/OSAL/Engine /home/neo/build/OSAL/Engine/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Engine/CMakeFiles/engine.dir/depend

