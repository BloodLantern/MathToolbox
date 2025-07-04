#pragma once

#include <cmath>
#include <cstdint>
#include <utility>

/// @file core.hpp
/// @brief File containing various macros used in the library.
///
/// When <b>NOT</b> building a DLL using this library, define @c MATH_NO_DLL.
/// When building a DLL, instead define @c MATH_EXPORT.

#if __cplusplus < 202100L
    #error "This library needs at least C++23 to be compiled"
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
    #define ENVIRONMENT_WINDOWS
#elifdef linux
    #define ENVIRONMENT_LINUX
#endif

#if defined(_MSC_VER) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
    #define COMPILER_MSVC
#elif defined(__GNUC__) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
    #define COMPILER_GCC
#elifdef __clang__
    #define COMPILER_CLANG
#endif

#ifdef COMPILER_MSVC
    #define COMPILER_ATTRIBUTE(x) __declspec(x)
    #define ASSUME(condition) __assume(condition)
#endif

#ifdef COMPILER_GCC
    #define ASSUME(condition) do { if (!(condition)) std::unreachable(); } while (0)
#endif

#ifdef COMPILER_CLANG
    #define ASSUME(condition) __builtin_assume(condition)
#endif

// For both GCC and Clang
#ifdef __GNUC__
    #define COMPILER_ATTRIBUTE(x) __attribute__((x))
#endif

/// @brief Macro preceding all declarations of this library. Used when integrating this library in a shared library.
///
/// When building a shared library using this library, define @c MATH_SHARED.
/// When building this project as a shared library, also define @c MATH_EXPORT.
#ifdef MATH_SHARED
    #ifdef ENVIRONMENT_WINDOWS
        #ifdef MATH_EXPORT
            #define SHARED_PUBLIC COMPILER_ATTRIBUTE(dllexport)
        #else
            #define SHARED_PUBLIC COMPILER_ATTRIBUTE(dllimport)
        #endif
        #define SHARED_PRIVATE
    #else
        #if __GNUC__ >= 4
            #define SHARED_PUBLIC COMPILER_ATTRIBUTE(visibility("default"))
            #define SHARED_PRIVATE  COMPILER_ATTRIBUTE(visibility("hidden"))
        #else
            #define SHARED_PUBLIC
            #define SHARED_PRIVATE
        #endif
    #endif

    #define PUBLIC_API SHARED_PUBLIC
    #define PRIVATE_API SHARED_PRIVATE
#else
    #define PUBLIC_API
    #define PRIVATE_API
#endif

using bool_t = bool;
using char_t = char;

/// @brief Expands to the square of a value.
#define SQ(x) ((x) * (x))
