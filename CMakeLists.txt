cmake_minimum_required(VERSION 3.14)

project(Math LANGUAGES CXX)

option(BUILD_TESTS "Build unit tests" OFF)
option(BUILD_SHARED_LIBS "Build a shared library instead of a static one" OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/MP) # Manually add multi-core compilation on MSVC
endif ()

add_subdirectory(src) # TODO Fix subdirectories

if (${BUILD_TESTS})
    add_subdirectory(tests)
endif ()
