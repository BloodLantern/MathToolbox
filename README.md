# MathToolbox

This library defines a set of math types and functions to easily manipulate mainly vectors, quaternions and matrices.

## How to use this library

To use this library, you need to compile it using the Visual Studio 2022 solution file found in the root directory. After opening it, the only thing you have to do is to build the library (MathToolbox project) in Debug and then in Release mode.

The build events will automatically create a 'bin' folder at the project root. In that folder, you will find the .lib, .pdb and .idb files for Debug and Release. For the Debug version, the file names will be suffixed with a 'd'. Additionally, the 'include' directory, in which all the header files are located, can be found in the MathToolbox folder.

To then use the library in any of your projects, do as you would usually: include the necessary headers and compile using the corresponding library files (Debug or Release).

## In the library

In addition to the common types like vectors in 2, 3 and 4 dimensions, quaternions and 4x4 matrices, the library provides more specific types. These include Vector2i which is basically a vector in 2 dimensions but for integer values. This can be useful when working with resolutions, or more generally when using exact pixel coordinates.
In the "calc.hpp" header, some useful, general use functions are defined and are for the most part constexpr.

Most types and functions have documentation in their respective header files so you can always check them if needed. They also are constexpr friendly by being usable at compile-time for most functions.
