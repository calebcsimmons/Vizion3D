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
include _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/flags.make

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/flags.make
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o: _deps/dawn-src/third_party/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o -MF CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o.d -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc > CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.i

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.s

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/flags.make
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o: _deps/dawn-src/third_party/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o -MF CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o.d -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc > CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.i

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.s

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/flags.make
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o: _deps/dawn-src/third_party/libprotobuf-mutator/src/src/binary_format.cc
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o -MF CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o.d -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/binary_format.cc

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/binary_format.cc > CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.i

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/binary_format.cc -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.s

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/flags.make
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o: _deps/dawn-src/third_party/libprotobuf-mutator/src/src/mutator.cc
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o -MF CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o.d -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/mutator.cc

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/mutator.cc > CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.i

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/mutator.cc -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.s

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/flags.make
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o: _deps/dawn-src/third_party/libprotobuf-mutator/src/src/text_format.cc
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o -MF CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o.d -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/text_format.cc

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/text_format.cc > CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.i

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/text_format.cc -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.s

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/flags.make
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o: _deps/dawn-src/third_party/libprotobuf-mutator/src/src/utf8_fix.cc
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o -MF CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o.d -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/utf8_fix.cc

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/utf8_fix.cc > CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.i

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/libprotobuf-mutator/src/src/utf8_fix.cc -o CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.s

# Object files for target libprotobuf-mutator
libprotobuf__mutator_OBJECTS = \
"CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o" \
"CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o" \
"CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o" \
"CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o" \
"CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o" \
"CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o"

# External object files for target libprotobuf-mutator
libprotobuf__mutator_EXTERNAL_OBJECTS =

_deps/dawn-build/third_party/liblibprotobuf-mutator.a: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_mutator.cc.o
_deps/dawn-build/third_party/liblibprotobuf-mutator.a: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/libfuzzer/libfuzzer_macro.cc.o
_deps/dawn-build/third_party/liblibprotobuf-mutator.a: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/binary_format.cc.o
_deps/dawn-build/third_party/liblibprotobuf-mutator.a: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/mutator.cc.o
_deps/dawn-build/third_party/liblibprotobuf-mutator.a: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/text_format.cc.o
_deps/dawn-build/third_party/liblibprotobuf-mutator.a: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/libprotobuf-mutator/src/src/utf8_fix.cc.o
_deps/dawn-build/third_party/liblibprotobuf-mutator.a: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/build.make
_deps/dawn-build/third_party/liblibprotobuf-mutator.a: _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library liblibprotobuf-mutator.a"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && $(CMAKE_COMMAND) -P CMakeFiles/libprotobuf-mutator.dir/cmake_clean_target.cmake
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libprotobuf-mutator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/build: _deps/dawn-build/third_party/liblibprotobuf-mutator.a
.PHONY : _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/build

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/clean:
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party && $(CMAKE_COMMAND) -P CMakeFiles/libprotobuf-mutator.dir/cmake_clean.cmake
.PHONY : _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/clean

_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/depend:
	cd /Users/calebsimmons/software-development/Vizion3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/dawn-build/third_party/CMakeFiles/libprotobuf-mutator.dir/depend

