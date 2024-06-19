# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.29.6)

# Reject any attempt to use a toolchain file. We must not use one because
# we could be downloading it here. If the CMAKE_TOOLCHAIN_FILE environment
# variable is set, the cache variable will have been initialized from it.
unset(CMAKE_TOOLCHAIN_FILE CACHE)
unset(ENV{CMAKE_TOOLCHAIN_FILE})

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(webgpu-backend-wgpu-populate NONE)



include(ExternalProject)
ExternalProject_Add(webgpu-backend-wgpu-populate
                     "UPDATE_DISCONNECTED" "False" "EXTERNALPROJECT_INTERNAL_ARGUMENT_SEPARATOR" "DOWNLOAD_COMMAND" "cd" "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-src" "&&" "git" "init" "&&" "git" "fetch" "--depth=1" "https://github.com/eliemichel/WebGPU-distribution" "ac055bef9d8c37f28e7706e4bd32153cbc0c210f" "&&" "git" "reset" "--hard" "FETCH_HEAD"
                    SOURCE_DIR          "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-src"
                    BINARY_DIR          "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


