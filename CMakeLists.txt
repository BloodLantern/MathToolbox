cmake_minimum_required(VERSION 3.10)
project(MathToolbox VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_TESTS "Build unit tests" OFF)
option(DLL_EXPORT "Add dllexport to declarations" OFF)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(FATAL_ERROR "This project currently only supports MSVC")
endif ()

add_compile_options(/MP)

if(CMAKE_CONFIGURATION_TYPES)
    list(APPEND CMAKE_CONFIGURATION_TYPES DebugDllExport)
    list(APPEND CMAKE_CONFIGURATION_TYPES ReleaseDllExport)
    set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
            "Add the configurations that we need"
            FORCE)
endif()

set(CMAKE_CXX_FLAGS_DEBUGDLLEXPORT "/DMATH_TOOLBOX_DLL_EXPORT" CACHE STRING
        "Flags used by the C++ compiler during DebugDllExport builds."
        FORCE)
set(CMAKE_C_FLAGS_DEBUGDLLEXPORT "" CACHE STRING
        "Flags used by the C compiler during DebugDllExport builds."
        FORCE)
set(CMAKE_EXE_LINKER_FLAGS_DEBUGDLLEXPORT "" CACHE STRING
        "Flags used for linking binaries during DebugDllExport builds."
        FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_DEBUGDLLEXPORT "" CACHE STRING
        "Flags used by the shared libraries linker during DebugDllExport builds."
        FORCE)

set(CMAKE_CXX_FLAGS_RELEASEDLLEXPORT "/DMATH_TOOLBOX_DLL_EXPORT" CACHE STRING
        "Flags used by the C++ compiler during ReleaseDllExport builds."
        FORCE)
set(CMAKE_C_FLAGS_RELEASEDLLEXPORT "" CACHE STRING
        "Flags used by the C compiler during ReleaseDllExport builds."
        FORCE)
set(CMAKE_EXE_LINKER_FLAGS_RELEASEDLLEXPORT "" CACHE STRING
        "Flags used for linking binaries during ReleaseDllExport builds."
        FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_RELEASEDLLEXPORT "" CACHE STRING
        "Flags used by the shared libraries linker during ReleaseDllExport builds."
        FORCE)

mark_as_advanced(
        CMAKE_CXX_FLAGS_MAINTAINER
        CMAKE_C_FLAGS_MAINTAINER
        CMAKE_EXE_LINKER_FLAGS_MAINTAINER
        CMAKE_SHARED_LINKER_FLAGS_MAINTAINER)
# Update the documentation string of CMAKE_BUILD_TYPE for GUIs
set(CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE}" CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel Maintainer."
        FORCE)

add_subdirectory(MathToolbox)

if (${BUILD_TESTS})
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(Tests)
endif ()
