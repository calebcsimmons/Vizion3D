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
include _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/flags.make

_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/src/dawn/dawn.json
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/src/dawn/dawn_wire.json
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/generator/templates/dawn_proc.cpp
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/generator/templates/dawn_thread_dispatch_proc.cpp
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/utils.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/__init__.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/visitor.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/async_utils.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/lexer.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/markupsafe/__init__.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/markupsafe/_compat.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/markupsafe/_native.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/tests.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/filters.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/environment.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/generator/dawn_json_generator.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/optimizer.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/defaults.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/parser.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/exceptions.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/idtracking.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/nodes.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/runtime.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/_identifier.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/compiler.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/generator/generator_lib.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/bccache.py
_deps/dawn-build/gen/src/dawn/dawn_proc.cpp: _deps/dawn-src/third_party/jinja2/loaders.py
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Dawn: Generating files for Dawn C++ wrapper."
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /opt/homebrew/Frameworks/Python.framework/Versions/3.12/bin/python3.12 /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/generator/dawn_json_generator.py --template-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/generator/templates --root-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src --output-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen --dawn-json /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/dawn/dawn.json --wire-json /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/dawn/dawn_wire.json --targets proc --jinja2-path /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/jinja2 --markupsafe-path /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/markupsafe

_deps/dawn-build/gen/src/dawn/dawn_thread_dispatch_proc.cpp: _deps/dawn-build/gen/src/dawn/dawn_proc.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/dawn-build/gen/src/dawn/dawn_thread_dispatch_proc.cpp

_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/src/dawn/dawn.json
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/src/dawn/dawn_wire.json
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/generator/templates/api.h
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/generator/templates/dawn/wire/client/api.h
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/generator/templates/dawn_proc_table.h
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/markupsafe/_native.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/exceptions.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/markupsafe/_compat.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/filters.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/tests.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/optimizer.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/runtime.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/async_utils.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/idtracking.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/__init__.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/compiler.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/parser.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/_identifier.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/bccache.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/environment.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/visitor.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/nodes.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/lexer.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/defaults.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/utils.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/generator/generator_lib.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/jinja2/loaders.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/third_party/markupsafe/__init__.py
_deps/dawn-build/gen/include/dawn/webgpu.h: _deps/dawn-src/generator/dawn_json_generator.py
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Dawn: Generating files for Dawn headers."
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /opt/homebrew/Frameworks/Python.framework/Versions/3.12/bin/python3.12 /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/generator/dawn_json_generator.py --template-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/generator/templates --root-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src --output-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen --dawn-json /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/dawn/dawn.json --wire-json /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/dawn/dawn_wire.json --targets headers --jinja2-path /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/jinja2 --markupsafe-path /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/markupsafe

_deps/dawn-build/gen/include/dawn/wire/client/webgpu.h: _deps/dawn-build/gen/include/dawn/webgpu.h
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/dawn-build/gen/include/dawn/wire/client/webgpu.h

_deps/dawn-build/gen/include/dawn/dawn_proc_table.h: _deps/dawn-build/gen/include/dawn/webgpu.h
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/dawn-build/gen/include/dawn/dawn_proc_table.h

_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/src/dawn/dawn.json
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/src/dawn/dawn_wire.json
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/generator/templates/api_cpp.h
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/generator/templates/api_cpp.h
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/generator/templates/api_cpp_print.h
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/generator/templates/api_cpp_chained_struct.h
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/nodes.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/markupsafe/__init__.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/generator/dawn_json_generator.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/compiler.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/environment.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/parser.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/tests.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/loaders.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/runtime.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/idtracking.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/exceptions.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/defaults.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/__init__.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/lexer.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/generator/generator_lib.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/async_utils.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/filters.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/_identifier.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/markupsafe/_compat.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/markupsafe/_native.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/bccache.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/utils.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/visitor.py
_deps/dawn-build/gen/include/dawn/webgpu_cpp.h: _deps/dawn-src/third_party/jinja2/optimizer.py
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Dawn: Generating files for Dawn C++ headers."
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /opt/homebrew/Frameworks/Python.framework/Versions/3.12/bin/python3.12 /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/generator/dawn_json_generator.py --template-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/generator/templates --root-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src --output-dir /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen --dawn-json /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/dawn/dawn.json --wire-json /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/dawn/dawn_wire.json --targets cpp_headers --jinja2-path /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/jinja2 --markupsafe-path /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/third_party/markupsafe

_deps/dawn-build/gen/include/dawn/wire/client/webgpu_cpp.h: _deps/dawn-build/gen/include/dawn/webgpu_cpp.h
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/dawn-build/gen/include/dawn/wire/client/webgpu_cpp.h

_deps/dawn-build/gen/include/dawn/webgpu_cpp_print.h: _deps/dawn-build/gen/include/dawn/webgpu_cpp.h
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/dawn-build/gen/include/dawn/webgpu_cpp_print.h

_deps/dawn-build/gen/include/webgpu/webgpu_cpp_chained_struct.h: _deps/dawn-build/gen/include/dawn/webgpu_cpp.h
	@$(CMAKE_COMMAND) -E touch_nocreate _deps/dawn-build/gen/include/webgpu/webgpu_cpp_chained_struct.h

_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o: _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/flags.make
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o: _deps/dawn-build/gen/src/dawn/dawn_proc.cpp
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o: _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o -MF CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o.d -o CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen/src/dawn/dawn_proc.cpp

_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen/src/dawn/dawn_proc.cpp > CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.i

_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen/src/dawn/dawn_proc.cpp -o CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.s

_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o: _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/flags.make
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o: _deps/dawn-build/gen/src/dawn/dawn_thread_dispatch_proc.cpp
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o: _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o -MF CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o.d -o CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o -c /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen/src/dawn/dawn_thread_dispatch_proc.cpp

_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.i"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen/src/dawn/dawn_thread_dispatch_proc.cpp > CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.i

_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.s"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/gen/src/dawn/dawn_thread_dispatch_proc.cpp -o CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.s

# Object files for target dawn_proc
dawn_proc_OBJECTS = \
"CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o" \
"CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o"

# External object files for target dawn_proc
dawn_proc_EXTERNAL_OBJECTS =

_deps/dawn-build/src/dawn/libdawn_proc.a: _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_proc.cpp.o
_deps/dawn-build/src/dawn/libdawn_proc.a: _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/__/__/gen/src/dawn/dawn_thread_dispatch_proc.cpp.o
_deps/dawn-build/src/dawn/libdawn_proc.a: _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/build.make
_deps/dawn-build/src/dawn/libdawn_proc.a: _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/calebsimmons/software-development/Vizion3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libdawn_proc.a"
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && $(CMAKE_COMMAND) -P CMakeFiles/dawn_proc.dir/cmake_clean_target.cmake
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dawn_proc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/build: _deps/dawn-build/src/dawn/libdawn_proc.a
.PHONY : _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/build

_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/clean:
	cd /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn && $(CMAKE_COMMAND) -P CMakeFiles/dawn_proc.dir/cmake_clean.cmake
.PHONY : _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/clean

_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/include/dawn/dawn_proc_table.h
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/include/dawn/webgpu.h
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/include/dawn/webgpu_cpp.h
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/include/dawn/webgpu_cpp_print.h
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/include/dawn/wire/client/webgpu.h
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/include/dawn/wire/client/webgpu_cpp.h
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/include/webgpu/webgpu_cpp_chained_struct.h
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/src/dawn/dawn_proc.cpp
_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend: _deps/dawn-build/gen/src/dawn/dawn_thread_dispatch_proc.cpp
	cd /Users/calebsimmons/software-development/Vizion3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/calebsimmons/software-development/Vizion3D /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src/src/dawn /Users/calebsimmons/software-development/Vizion3D/build /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn /Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/dawn-build/src/dawn/CMakeFiles/dawn_proc.dir/depend

