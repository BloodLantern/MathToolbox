# MathToolbox

This library defines a set of math types and functions to easily manipulate vectors, quaternions and matrices.

## How to use this library

### Build from source

To use this library, you need to compile it using the Visual Studio solution file found in the root directory. After opening it, the only thing you have to do is to build the library (MathToolbox project) in Debug and then in Release mode.

The build events will automatically create a 'bin' folder in the root folder. In that folder, you will find the .lib, .pdb and .idb files for Debug and Release. For the Debug version, the file names will be suffixed with a 'd'. Additionally, the 'include' directory, in which all the header files are located, can be found in the MathToolbox folder.

To then use the library in any of your projects, do as you would usually: include the necessary headers and compile by statically linking the corresponding library files (Debug or Release).

### Download a release

[Link](https://github.com/BloodLantern/MathToolbox/releases)

## What is included

In addition to the common types like vectors in 2, 3 and 4 dimensions, quaternions and 4x4 matrices, this library provides the Vector2i type. This is a vector in 2 dimensions but for integer values. This can be useful when working with resolutions, or more generally when using exact pixel coordinates.

In the Calc namespace, mathematical constants, and some useful, general use functions are defined.

Most types and functions have documentation in their respective header files so you can always check them if needed. A [Doxygen](https://www.doxygen.nl)-generated documentation page will also soon be available.

The majority of this library functions are `constexpr`, which means that their calls can be resolved at compile-time.
