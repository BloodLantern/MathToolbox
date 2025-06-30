cmake_minimum_required(VERSION 3.14)

project(UnitTests LANGUAGES C CXX)

include_directories("../src")

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/c67de117379f4d1c889c7581a0a76aa0979c2083.zip # Commit from June 28, 2025
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    Tests
    test.cpp
)
target_link_libraries(
    Tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)
