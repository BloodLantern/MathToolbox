cmake_minimum_required(VERSION 3.12)

if (${BUILD_SHARED_LIBS})
    add_compile_definitions(MATH_EXPORT)
endif ()

include_directories(".")

file(GLOB_RECURSE SOURCE_FILES "*.cpp")

add_library(Math ${SOURCE_FILES})
