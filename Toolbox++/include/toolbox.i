%module toolbox

%{
#include "calc.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "matrix2x2.hpp"
#include "matrix3x3.hpp"
#include "matrix4x4.hpp"
%}

%include calc.hpp

%include vector2.hpp


%extend Vector2
{
	[[nodiscard]]
	float& __getitem__(const size_t i)
    {
        return *(&x + i);
    }

	[[nodiscard]]
	float& __setitem__(const size_t i, const float value)
    {
        return *(&x + i) = value;
    }

    void __str__()
    {
        printf("{ %6.3f, %6.3f }", v.x, v.y);
    }
}

%include vector3.hpp

%include vector4.hpp

%include matrix2x2.hpp

%include matrix3x3.hpp

%include matrix4x4.hpp
