cmake_minimum_required(VERSION 3.29.6)

project(
    Vizion3D
    VERSION 0.1.0
    DESCRIPTION "A 3D visualization application"
    LANGUAGES CXX C
)

# Executables
add_executable(App main.cpp)

# Subdirectories

if (NOT EMSCRIPTEN)
    add_subdirectory(glfw)
else()
    # Emscripten has built-in support for GLFW but requires the `-sUSE_GLFW=3` link option:
    add_library(glfw INTERFACE)
    target_link_options(glfw INTERFACE -sUSE_GLFW=3)
endif()

add_subdirectory(webgpu)

# Dependencies
target_link_libraries(App PRIVATE webgpu glfw)
target_link_libraries(App PRIVATE webgpu)

# Set target properties
set_target_properties(App PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Set compile options
if (MSVC)
    target_compile_options(App PRIVATE /W4 /WX)
else()
    target_compile_options(App PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# Xcode specific properties
if (XCODE)
    set_target_properties(App PROPERTIES
        XCODE_GENERATE_SCHEME ON
        XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE "Metal"
    )
endif()

# Emscripten options
if (EMSCRIPTEN)
	# Generate an HTML
	set_target_properties(App PROPERTIES SUFFIX ".html")
endif()