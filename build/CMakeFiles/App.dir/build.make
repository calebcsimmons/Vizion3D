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
include CMakeFiles/App.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/App.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/App.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/App.dir/flags.make

CMakeFiles/App.dir/main.cpp.o: CMakeFiles/App.dir/flags.make
CMakeFiles/App.dir/main.cpp.o: /Users/calebsimmons/software-development/Vizion3D/main.cpp
CMakeFiles/App.dir/main.cpp.o: CMakeFiles/App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/App.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/App.dir/main.cpp.o -MF CMakeFiles/App.dir/main.cpp.o.d -o CMakeFiles/App.dir/main.cpp.o -c /Users/calebsimmons/software-development/Vizion3D/main.cpp

CMakeFiles/App.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/App.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/main.cpp > CMakeFiles/App.dir/main.cpp.i

CMakeFiles/App.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/App.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/main.cpp -o CMakeFiles/App.dir/main.cpp.s

# Object files for target App
App_OBJECTS = \
"CMakeFiles/App.dir/main.cpp.o"

# External object files for target App
App_EXTERNAL_OBJECTS =

App: CMakeFiles/App.dir/main.cpp.o
App: CMakeFiles/App.dir/build.make
App: _deps/webgpu-backend-wgpu-src/bin/macos-aarch64/libwgpu_native.dylib
App: CMakeFiles/App.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable App"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/App.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/App.dir/build: App
.PHONY : CMakeFiles/App.dir/build

CMakeFiles/App.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/App.dir/cmake_clean.cmake
.PHONY : CMakeFiles/App.dir/clean

CMakeFiles/App.dir/depend:
	cd /Users/calebsimmons/software-development/Vizion3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles/App.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/App.dir/depend

