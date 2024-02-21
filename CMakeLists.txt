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

if (${DEFINE_FORMATTER})
    string(APPEND COMMON_CXX_FLAGS " /DMATH_DEFINE_FORMATTER")
endif ()

if (${DLL_EXPORT})
    string(APPEND COMMON_CXX_FLAGS " /DMATH_TOOLBOX_DLL_EXPORT")
endif ()

message(DEBUG "CXX Flags: " ${COMMON_CXX_FLAGS})

string(APPEND CMAKE_CXX_FLAGS_DEBUG ${COMMON_CXX_FLAGS})

string(APPEND CMAKE_CXX_FLAGS_RELEASE ${COMMON_CXX_FLAGS})

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
