#pragma once

#include <cmath>
#include <cstdint>

/// @file core.hpp
/// @brief File containing various macros used in the library.
///
/// When <b>NOT</b> building a DLL using this library, define @c MATH_NO_DLL.

//#define MATH_NO_DLL

/// @brief Macro preceding all declarations of this library. Used when integrating this library in a DLL.
///
/// When <b>NOT</b> building a DLL using this library, define @c MATH_NO_DLL.
#ifndef MATH_NO_DLL
    #ifdef MATH_EXPORT
        #define MATH_TOOLBOX __declspec(dllexport)
    #else
        #define MATH_TOOLBOX __declspec(dllimport)
    #endif
#else
    #define MATH_TOOLBOX
#endif

// ReSharper disable once CppEnforceTypeAliasCodeStyle
/// @private
typedef bool bool_t;
// ReSharper disable once CppEnforceTypeAliasCodeStyle
/// @private
typedef char char_t;

/// @brief Expands to the square of a value.
#define SQ(x) ((x) * (x))
