cmake_minimum_required(VERSION 3.5)
project(
	VIZION3D
	VERSION 0.1.0
	LANGUAGES CXX C
)

include(utils.cmake)

option(DEV_MODE "Set up development helper settings" ON)

add_subdirectory(glfw)
add_subdirectory(webgpu)
add_subdirectory(glfw3webgpu)

add_executable(
	App
	main.cpp
	Application.h
	Application.cpp
	ResourceManager.h
	ResourceManager.cpp
	implementations.cpp
	stb_image.h
	tiny_obj_loader.h
	)

if(DEV_MODE)
	# In dev mode, we load resources from the source tree, so that when we
	# dynamically edit resources (like shaders), these are correctly
	# versioned.
	target_compile_definitions(App PRIVATE
		RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources"
	)
else()
	# In release mode, we just load resources relatively to wherever the
	# executable is launched from, so that the binary is portable
	target_compile_definitions(App PRIVATE
		RESOURCE_DIR="./resources"
	)
endif()

target_include_directories(App PRIVATE .)

target_link_libraries(App PRIVATE glfw webgpu glfw3webgpu)

set_target_properties(App PROPERTIES
	CXX_STANDARD 17
	VS_DEBUGGER_ENVIRONMENT "DAWN_DEBUG_BREAK_ON_ERROR=1"
)
target_treat_all_warnings_as_errors(App)
target_copy_webgpu_binaries(App)

if (MSVC)
	# Ignore a warning that GLM requires to bypass
	# Disable warning C4201: nonstandard extension used: nameless struct/union
	target_compile_options(App PUBLIC /wd4201)
	# Disable warning C4305: truncation from 'int' to 'bool' in 'if' condition
	target_compile_options(App PUBLIC /wd4305)

	# Ignore a warning that stb_image requires to bypass
	# Disable warning C4244: conversion from 'int' to 'short', possible loss of data
	target_compile_options(App PUBLIC /wd4244)
endif (MSVC)

# Define install rules
install(TARGETS App DESTINATION bin)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libwgpu_native.dylib DESTINATION bin)  # Ensure it points to the correct directory
install(DIRECTORY resources DESTINATION .)

# CPack configuration
set(CPACK_PACKAGE_NAME "VIZION3D")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_GENERATOR "ZIP")  # Use ZIP instead of TGZ
# set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")

include(CPack)