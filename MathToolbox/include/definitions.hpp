#pragma once

/// \file definitions.hpp
/// <summary>
/// File containing various macros used in the library.
/// 
/// When building a DLL using this library, define <c>MATH_TOOLBOX_DLL_EXPORT</c>. When using a DLL that was built using this library, instead define <c>MATH_TOOLBOX_DLL_IMPORT</c>.
/// </summary>

/// <summary>
/// Macro preceding all declarations of this library. Used when integrating this library in a DLL.
///
/// If using this library to build a DLL, define <c>MATH_TOOLBOX_DLL_EXPORT</c>. If using a DLL that was built using this library, instead define <c>MATH_TOOLBOX_DLL_IMPORT</c>.
/// </summary>
#ifdef MATH_TOOLBOX_DLL_EXPORT
#define MATH_TOOLBOX __declspec(dllexport)
#elifdef MATH_TOOLBOX_DLL_IMPORT
#define MATH_TOOLBOX __declspec(dllimport)
#else
#define MATH_TOOLBOX
#endif

/// <summary>
/// Expands to the square of a value.
/// </summary>
#define SQ(x) ((x) * (x))
