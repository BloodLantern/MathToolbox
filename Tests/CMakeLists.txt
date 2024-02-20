enable_testing()

add_executable(tests)

target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/MathToolbox/include)

target_sources(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)

target_link_libraries(tests toolbox)
target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
