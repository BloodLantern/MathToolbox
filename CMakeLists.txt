cmake_minimum_required(VERSION 3.10)
project(MathToolbox VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_TESTS "Build unit tests" OFF)
option(DLL_EXPORT "Add dllexport to declarations" OFF)
option(DEFINE_FORMATTER "Define std::formatter implementations" OFF)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(FATAL_ERROR "This project currently only supports MSVC")
endif ()

add_compile_options(/MP)

set(COMMON_CXX_FLAGS "")

if (DEFINE_FORMATTER)
    string(APPEND COMMON_CXX_FLAGS "/DMATH_DEFINE_FORMATTER ")
endif ()

if (DLL_EXPORT)
    string(APPEND COMMON_CXX_FLAGS "/DMATH_TOOLBOX_DLL_EXPORT ")
endif ()

message(DEBUG "CXX Flags: " ${COMMON_CXX_FLAGS})

set(CMAKE_CXX_FLAGS_DEBUG ${COMMON_CXX_FLAGS} CACHE STRING
        "Flags used by the C++ compiler during Debug builds."
        FORCE)
set(CMAKE_C_FLAGS_DEBUG "" CACHE STRING
        "Flags used by the C compiler during Debug builds."
        FORCE)
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "" CACHE STRING
        "Flags used for linking binaries during Debug builds."
        FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "" CACHE STRING
        "Flags used by the shared libraries linker during Debug builds."
        FORCE)

set(CMAKE_CXX_FLAGS_RELEASE ${COMMON_CXX_FLAGS} CACHE STRING
        "Flags used by the C++ compiler during Release builds."
        FORCE)
set(CMAKE_C_FLAGS_RELEASE "" CACHE STRING
        "Flags used by the C compiler during Release builds."
        FORCE)
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "" CACHE STRING
        "Flags used for linking binaries during Release builds."
        FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "" CACHE STRING
        "Flags used by the shared libraries linker during Release builds."
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
