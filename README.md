# C++ Math Toolbox

This library defines a set of math types and functions to easily manipulate vectors, quaternions and matrices for the C++ programming language.

## Language version and architecture

This project is compiled using C++23 features (`/std:c++latest`), on MSVC, for the `x64` architecture.

You could actually build the project from source for the `x86` architecture, but the releases and project configurations are all for `x64`.

## Documentation

The [Doxygen](https://doxygen.nl) documentation can be found [online](https://codedocs.xyz/BloodLantern/MathToolbox/index.html) or manually generated using the Doxyfile.

Most types and functions have documentation in their respective header files, so you can always check them if needed.

## What is included

In addition to the common types like vectors in two, three and four dimensions,
quaternions and 4x4 matrices, this library provides the Vector2i type.
This is a vector in two dimensions but for integer values.
This can be useful when working with resolutions, or more generally when using exact pixel coordinates.
All those types are defined in the global namespace so that they are straightforward and quick to use.

In the `Calc` namespace, mathematical constants and some useful, general use functions are defined.
In the `Easing` namespace, the common easing functions can be found as well.

The majority of this library's functions are `constexpr`,
which means that their calls can be resolved at compile-time which allows a faster execution at run-time.

All rotation angles are in radians. If you want to use degrees instead, multiply your degree angle by `Calc::Deg2Rad`. This will give you the same amount but in radians.

To use this library, you can `#include` the specific file you need, or you can instead `#include` the `math.hpp` file, which contains every other header for you.
