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
)

if(DEV_MODE)
    target_compile_definitions(App PRIVATE
        RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources"
    )
else()
    target_compile_definitions(App PRIVATE
        RESOURCE_DIR="./resources"
    )
endif()

target_include_directories(App PRIVATE .)

if (WIN32)
    # Path to the directory containing wgpu_native.dll and wgpu_native.dll.lib
    set(WGPU_NATIVE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build-win/_deps/webgpu-backend-wgpu-src/bin/windows-x86_64")

    # Find wgpu_native.dll
    find_library(WGPU_NATIVE_DLL
        NAMES wgpu_native.dll
        PATHS ${WGPU_NATIVE_DIR}
    )
    if (NOT WGPU_NATIVE_DLL)
        message(FATAL_ERROR "wgpu_native.dll not found in ${WGPU_NATIVE_DIR}")
    endif()

    # Find wgpu_native.dll.lib
    find_library(WGPU_NATIVE_LIB
        NAMES wgpu_native.dll.lib
        PATHS ${WGPU_NATIVE_DIR}
    )
    if (NOT WGPU_NATIVE_LIB)
        message(FATAL_ERROR "wgpu_native.dll.lib not found in ${WGPU_NATIVE_DIR}")
    endif()

    target_link_libraries(App PRIVATE glfw3webgpu ${WGPU_NATIVE_DLL} ${WGPU_NATIVE_LIB})
else()
    target_link_libraries(App PRIVATE glfw webgpu glfw3webgpu)
endif()

set_target_properties(App PROPERTIES
    CXX_STANDARD 17
    VS_DEBUGGER_ENVIRONMENT "DAWN_DEBUG_BREAK_ON_ERROR=1"
)

target_treat_all_warnings_as_errors(App)
target_copy_webgpu_binaries(App)

if (MSVC)
    target_compile_options(App PUBLIC /wd4201 /wd4305 /wd4244)
endif (MSVC)

install(TARGETS App DESTINATION bin)
install(DIRECTORY resources DESTINATION .)

# CPack configuration
set(CPACK_PACKAGE_NAME "VIZION3D")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_GENERATOR "ZIP")
set(CPACK_SYSTEM_NAME "")

if(CPACK_SYSTEM_NAME)
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_SYSTEM_NAME}")
else()
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
endif()

include(CPack)




# Commands Mac Build
# cmake ..
# cmake --build build-mac

#Commands Window Build
#cmake .. -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake
# cmake --build build-win or cmake --build .
# mkdir build-win
# cd build-win 
# cmake .. -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake