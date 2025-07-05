cmake_minimum_required(VERSION 3.12)

project(MathUnitTests)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

include_directories(${MathLibrary_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/c67de117379f4d1c889c7581a0a76aa0979c2083.zip # Commit from June 28, 2025
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

if (BUILD_SHARED_LIBS)
    add_compile_definitions(MATH_SHARED)
endif ()

add_executable(
    MathUnitTests
    test.cpp
)
target_link_libraries(
    MathUnitTests
    GTest::gtest_main
    Math
)

if (WIN32)
    if (MATH_BUILD_SHARED_LIBS)
        add_custom_command(TARGET MathUnitTests POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Math>
            $<TARGET_FILE_DIR:MathUnitTests>
            COMMENT "Copy Math shared library to MathUnitTests output directory"
        )
    endif ()

    add_custom_command(
        TARGET MathUnitTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:MathUnitTests> $<TARGET_FILE_DIR:MathUnitTests>
        COMMAND_EXPAND_LISTS
        COMMENT "Copy GTest shared library to MathUnitTests output directory"
    )
endif ()

include(GoogleTest)
gtest_discover_tests(MathUnitTests)
