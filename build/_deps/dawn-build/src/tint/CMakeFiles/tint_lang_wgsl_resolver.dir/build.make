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
include _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o: _deps/dawn-src/src/tint/lang/wgsl/resolver/dependency_graph.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o -MF CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o.d -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/dependency_graph.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/dependency_graph.cc > CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/dependency_graph.cc -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.s

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o: _deps/dawn-src/src/tint/lang/wgsl/resolver/incomplete_type.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o -MF CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o.d -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/incomplete_type.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/incomplete_type.cc > CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/incomplete_type.cc -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.s

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o: _deps/dawn-src/src/tint/lang/wgsl/resolver/resolve.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o -MF CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o.d -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/resolve.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/resolve.cc > CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/resolve.cc -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.s

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o: _deps/dawn-src/src/tint/lang/wgsl/resolver/resolver.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o -MF CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o.d -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/resolver.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/resolver.cc > CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/resolver.cc -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.s

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o: _deps/dawn-src/src/tint/lang/wgsl/resolver/sem_helper.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o -MF CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o.d -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/sem_helper.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/sem_helper.cc > CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/sem_helper.cc -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.s

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o: _deps/dawn-src/src/tint/lang/wgsl/resolver/uniformity.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o -MF CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o.d -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/uniformity.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/uniformity.cc > CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/uniformity.cc -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.s

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o: _deps/dawn-src/src/tint/lang/wgsl/resolver/unresolved_identifier.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o -MF CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o.d -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/unresolved_identifier.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/unresolved_identifier.cc > CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/unresolved_identifier.cc -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.s

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/flags.make
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o: _deps/dawn-src/src/tint/lang/wgsl/resolver/validator.cc
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o -MF CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o.d -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/validator.cc

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/validator.cc > CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.i

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint/lang/wgsl/resolver/validator.cc -o CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.s

# Object files for target tint_lang_wgsl_resolver
tint_lang_wgsl_resolver_OBJECTS = \
"CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o" \
"CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o" \
"CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o" \
"CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o" \
"CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o" \
"CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o" \
"CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o" \
"CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o"

# External object files for target tint_lang_wgsl_resolver
tint_lang_wgsl_resolver_EXTERNAL_OBJECTS =

_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/dependency_graph.cc.o
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/incomplete_type.cc.o
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolve.cc.o
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/resolver.cc.o
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/sem_helper.cc.o
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/uniformity.cc.o
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/unresolved_identifier.cc.o
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/lang/wgsl/resolver/validator.cc.o
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/build.make
_deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a: _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libtint_lang_wgsl_resolver.a"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && $(CMAKE_COMMAND) -P CMakeFiles/tint_lang_wgsl_resolver.dir/cmake_clean_target.cmake
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tint_lang_wgsl_resolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/build: _deps/dawn-build/src/tint/libtint_lang_wgsl_resolver.a
.PHONY : _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/build

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/clean:
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint && $(CMAKE_COMMAND) -P CMakeFiles/tint_lang_wgsl_resolver.dir/cmake_clean.cmake
.PHONY : _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/clean

_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/depend:
	cd /Users/calebsimmons/software-development/Vizion3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/tint /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/dawn-build/src/tint/CMakeFiles/tint_lang_wgsl_resolver.dir/depend

