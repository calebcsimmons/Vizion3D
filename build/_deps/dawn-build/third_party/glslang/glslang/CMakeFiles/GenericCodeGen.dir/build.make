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
include _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/flags.make

_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o: _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/flags.make
_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o: _deps/dawn-src/third_party/glslang/src/glslang/GenericCodeGen/CodeGen.cpp
_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o: _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o -MF CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o.d -o CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/glslang/src/glslang/GenericCodeGen/CodeGen.cpp

_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/glslang/src/glslang/GenericCodeGen/CodeGen.cpp > CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.i

_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/glslang/src/glslang/GenericCodeGen/CodeGen.cpp -o CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.s

_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o: _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/flags.make
_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o: _deps/dawn-src/third_party/glslang/src/glslang/GenericCodeGen/Link.cpp
_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o: _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o -MF CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o.d -o CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/glslang/src/glslang/GenericCodeGen/Link.cpp

_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/glslang/src/glslang/GenericCodeGen/Link.cpp > CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.i

_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/glslang/src/glslang/GenericCodeGen/Link.cpp -o CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.s

# Object files for target GenericCodeGen
GenericCodeGen_OBJECTS = \
"CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o" \
"CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o"

# External object files for target GenericCodeGen
GenericCodeGen_EXTERNAL_OBJECTS =

_deps/dawn-build/third_party/glslang/glslang/libGenericCodeGen.a: _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/CodeGen.cpp.o
_deps/dawn-build/third_party/glslang/glslang/libGenericCodeGen.a: _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/GenericCodeGen/Link.cpp.o
_deps/dawn-build/third_party/glslang/glslang/libGenericCodeGen.a: _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/build.make
_deps/dawn-build/third_party/glslang/glslang/libGenericCodeGen.a: _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libGenericCodeGen.a"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && $(CMAKE_COMMAND) -P CMakeFiles/GenericCodeGen.dir/cmake_clean_target.cmake
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GenericCodeGen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/build: _deps/dawn-build/third_party/glslang/glslang/libGenericCodeGen.a
.PHONY : _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/build

_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/clean:
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang && $(CMAKE_COMMAND) -P CMakeFiles/GenericCodeGen.dir/cmake_clean.cmake
.PHONY : _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/clean

_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/depend:
	cd /Users/calebsimmons/software-development/Vizion3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/glslang/src/glslang /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/dawn-build/third_party/glslang/glslang/CMakeFiles/GenericCodeGen.dir/depend

