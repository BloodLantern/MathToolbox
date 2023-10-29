# MathToolbox

This library defines a set of math types and functions to easily manipulate mainly vectors and matrices.

## How to use this library

To use this library, you need to compile it using the Visual Studio 2022 solution file found in the root directory. After opening it, the only thing you have to do is to build the library (Toolbox++ project) in Debug and then in Release mode.

The build events will automatically create a 'bin' folder at the project root. In that folder, you will find the .lib, .pdb and .idb files for Debug and Release. For the Debug version, the file names will be suffixed with a 'd'. Additionally, you will find an 'include' folder in which all the header files have been copied for you.

To then use the library in any of your projects, do as you would usually: include the necessary headers and compile using the corresponding library files (Debug or Release).

## Defined types

In addition to the common types like vectors in 2, 3 and 4 dimensions and 2x2, 3x3 and 4x4 matrices, the library provides more specific types. These include Vector2i which is basically a vector in 2 dimensions but for integer values. This can be useful when working with resolutions, or more generally when using exact pixel coordinates. In addition to that, the library provides a Matrix type for any matrix of size MxN and a Vector type for any vector of size M.

Most types and functions have documentation in their respective header files so you can always check them if needed.
