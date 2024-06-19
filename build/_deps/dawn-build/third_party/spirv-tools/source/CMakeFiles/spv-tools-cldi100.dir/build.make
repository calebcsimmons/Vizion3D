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

# Utility rule file for spv-tools-cldi100.

# Include any custom commands dependencies for this target.
include _deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/progress.make

_deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100: _deps/dawn-build/third_party/spirv-tools/opencl.debuginfo.100.insts.inc

_deps/dawn-build/third_party/spirv-tools/opencl.debuginfo.100.insts.inc: _deps/dawn-src/third_party/spirv-tools/src/utils/generate_grammar_tables.py
_deps/dawn-build/third_party/spirv-tools/opencl.debuginfo.100.insts.inc: _deps/dawn-src/third_party/spirv-headers/src/include/spirv/unified1/extinst.opencl.debuginfo.100.grammar.json
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generate extended instruction tables for opencl.debuginfo.100."
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/spirv-tools/source && /opt/homebrew/Frameworks/Python.framework/Versions/3.12/bin/python3.12 /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/spirv-tools/src/utils/generate_grammar_tables.py --extinst-vendor-grammar=/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/spirv-headers/src/include/spirv/unified1/extinst.opencl.debuginfo.100.grammar.json --vendor-insts-output=/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/spirv-tools/opencl.debuginfo.100.insts.inc --vendor-operand-kind-prefix=CLDEBUG100_

spv-tools-cldi100: _deps/dawn-build/third_party/spirv-tools/opencl.debuginfo.100.insts.inc
spv-tools-cldi100: _deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100
spv-tools-cldi100: _deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/build.make
.PHONY : spv-tools-cldi100

# Rule to build all files generated by this target.
_deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/build: spv-tools-cldi100
.PHONY : _deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/build

_deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/clean:
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/spirv-tools/source && $(CMAKE_COMMAND) -P CMakeFiles/spv-tools-cldi100.dir/cmake_clean.cmake
.PHONY : _deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/clean

_deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/depend:
	cd /Users/calebsimmons/software-development/Vizion3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/spirv-tools/src/source /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/spirv-tools/source /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/dawn-build/third_party/spirv-tools/source/CMakeFiles/spv-tools-cldi100.dir/depend

