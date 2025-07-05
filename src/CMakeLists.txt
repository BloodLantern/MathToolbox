cmake_minimum_required(VERSION 3.12)

project(MathLibrary)

if (MATH_BUILD_SHARED_LIBS)
    add_compile_definitions(MATH_SHARED MATH_EXPORT)
endif ()

include_directories(".")

file(GLOB_RECURSE SOURCE_FILES "*.cpp")

if (MATH_BUILD_SHARED_LIBS)
    add_library(Math SHARED ${SOURCE_FILES})
else ()
    add_library(Math STATIC ${SOURCE_FILES})
endif ()
