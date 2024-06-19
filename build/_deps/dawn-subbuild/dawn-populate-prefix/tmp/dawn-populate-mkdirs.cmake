# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-src"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-build"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-subbuild/dawn-populate-prefix"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-subbuild/dawn-populate-prefix/tmp"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-subbuild/dawn-populate-prefix/src/dawn-populate-stamp"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-subbuild/dawn-populate-prefix/src"
  "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-subbuild/dawn-populate-prefix/src/dawn-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-subbuild/dawn-populate-prefix/src/dawn-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/calebsimmons/software-development/Vizion3D/build/_deps/dawn-subbuild/dawn-populate-prefix/src/dawn-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
