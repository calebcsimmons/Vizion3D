# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/calebsimmons/software-development/Vizion3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/calebsimmons/software-development/Vizion3D/build

# Include any dependencies generated for this target.
include _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/flags.make

_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o: _deps/dawn-src/src/tint/utils/command/command_posix.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o -MF CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o.d -o CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/utils/command/command_posix.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/utils/command/command_posix.cc > CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/utils/command/command_posix.cc -o CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.s

# Object files for target tint_utils_command
tint_utils_command_OBJECTS = \
"CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o"

# External object files for target tint_utils_command
tint_utils_command_EXTERNAL_OBJECTS =

_deps/dawn-build/src/tint/libtint_utils_command.a: _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/utils/command/command_posix.cc.o
_deps/dawn-build/src/tint/libtint_utils_command.a: _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/build.make
_deps/dawn-build/src/tint/libtint_utils_command.a: _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtint_utils_command.a"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && $(CMAKE_COMMAND) -P CMakeFiles/tint_utils_command.dir/cmake_clean_target.cmake
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tint_utils_command.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/build: _deps/dawn-build/src/tint/libtint_utils_command.a
.PHONY : _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/build

_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/clean:
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && $(CMAKE_COMMAND) -P CMakeFiles/tint_utils_command.dir/cmake_clean.cmake
.PHONY : _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/clean

_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/depend:
	cd /Users/calebsimmons/software-development/Vizion3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/dawn-build/src/tint/CMakeFiles/tint_utils_command.dir/depend

