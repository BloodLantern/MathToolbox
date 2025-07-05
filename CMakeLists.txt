cmake_minimum_required(VERSION 3.14)

project(Math LANGUAGES CXX)

option(MATH_BUILD_UNIT_TESTS "Build unit tests" OFF)
option(MATH_BUILD_SHARED_LIBS "Build a shared library instead of a static one" OFF)
option(MATH_DEFINE_FORMATTER "Define a specialization of std::formatter for all types" ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/MP /Zc:__cplusplus) # Manually add some specific compilation flags on MSVC
endif ()

if (MATH_DEFINE_FORMATTER)
    add_compile_definitions(MATH_DEFINE_FORMATTER)
endif ()

add_subdirectory(src)

if (MATH_BUILD_UNIT_TESTS)
    add_subdirectory(tests)
endif ()
