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
include _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/flags.make

_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/log_sink.cc.o: _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/flags.make
_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/log_sink.cc.o: _deps/dawn-src/third_party/abseil-cpp/absl/log/log_sink.cc
_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/log_sink.cc.o: _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/log_sink.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/abseil/absl/log && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/log_sink.cc.o -MF CMakeFiles/absl_log_sink.dir/log_sink.cc.o.d -o CMakeFiles/absl_log_sink.dir/log_sink.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/abseil-cpp/absl/log/log_sink.cc

_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/log_sink.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/absl_log_sink.dir/log_sink.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/abseil/absl/log && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/abseil-cpp/absl/log/log_sink.cc > CMakeFiles/absl_log_sink.dir/log_sink.cc.i

_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/log_sink.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/absl_log_sink.dir/log_sink.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/abseil/absl/log && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/abseil-cpp/absl/log/log_sink.cc -o CMakeFiles/absl_log_sink.dir/log_sink.cc.s

# Object files for target absl_log_sink
absl_log_sink_OBJECTS = \
"CMakeFiles/absl_log_sink.dir/log_sink.cc.o"

# External object files for target absl_log_sink
absl_log_sink_EXTERNAL_OBJECTS =

_deps/dawn-build/third_party/abseil/absl/log/libabsl_log_sink.a: _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/log_sink.cc.o
_deps/dawn-build/third_party/abseil/absl/log/libabsl_log_sink.a: _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/build.make
_deps/dawn-build/third_party/abseil/absl/log/libabsl_log_sink.a: _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_log_sink.a"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/abseil/absl/log && $(CMAKE_COMMAND) -P CMakeFiles/absl_log_sink.dir/cmake_clean_target.cmake
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/abseil/absl/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/absl_log_sink.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/build: _deps/dawn-build/third_party/abseil/absl/log/libabsl_log_sink.a
.PHONY : _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/build

_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/clean:
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/abseil/absl/log && $(CMAKE_COMMAND) -P CMakeFiles/absl_log_sink.dir/cmake_clean.cmake
.PHONY : _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/clean

_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/depend:
	cd /Users/calebsimmons/software-development/Vizion3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/abseil-cpp/absl/log /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/abseil/absl/log /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/dawn-build/third_party/abseil/absl/log/CMakeFiles/absl_log_sink.dir/depend

