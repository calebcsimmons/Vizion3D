# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-src"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-build"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-subbuild/webgpu-backend-wgpu-populate-prefix"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-subbuild/webgpu-backend-wgpu-populate-prefix/tmp"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-subbuild/webgpu-backend-wgpu-populate-prefix/src/webgpu-backend-wgpu-populate-stamp"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-subbuild/webgpu-backend-wgpu-populate-prefix/src"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-subbuild/webgpu-backend-wgpu-populate-prefix/src/webgpu-backend-wgpu-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-subbuild/webgpu-backend-wgpu-populate-prefix/src/webgpu-backend-wgpu-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/calebsimmons/software-development/Vizion3D/build/_deps/webgpu-backend-wgpu-subbuild/webgpu-backend-wgpu-populate-prefix/src/webgpu-backend-wgpu-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
