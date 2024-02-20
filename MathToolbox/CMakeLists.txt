add_library(toolbox STATIC)

target_include_directories(toolbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(
        toolbox
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/calc.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/quaternion.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vector2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vector2i.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vector3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vector4.cpp
)