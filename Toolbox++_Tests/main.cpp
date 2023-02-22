#include <iostream>
#include <numbers>
#include <chrono>
//#include <intrin.h>

#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix.hpp"

#define PRINT(o) (std::cout << (o) << std::endl)

//typedef void (*Func_T)(void);

int main()
{
    /*
#pragma region Point2
    PRINT("Point2 :\n");

    Vector2 A(0.f, 0.f);
    Vector2 B(4.f, 0.f);
    Vector2 C(2.0, std::sqrt(3.f) / 2.f * Dist(A, B));

    Vector2 D = -B;
    Vector2 E = Mid(A, B);

    Vector2 F = Circumcenter(A, B, C);
    Vector2 G = Circumcenter(B, C, D);
    Vector2 H = Circumcenter(A, C, D);
    Vector2 I = Circumcenter(F, B, D);

    Vector2 J = IsobarycenterTriangle(A, B, C);

    PRINT(A);
    PRINT(B);
    PRINT(C);
    PRINT(D);
    PRINT(E);
    PRINT(F);
    PRINT(G);
    PRINT(H);
    PRINT(I);
    PRINT(J);
#pragma endregion
    */

    /*
#pragma region Vector2
    PRINT("\nVector2 :\n");

    Vector2 a(2.f, 5.f);
    Vector2 b(3.f, -5.f);
    Vector2 c = a + b;
    PRINT(a);
    PRINT(b);
    PRINT(c);

    a = Vector2(3.f, 5.f);
    PRINT(a);
    c = a + b;
    PRINT(c);

    Vector2 d = -a;
    PRINT(d);
    c = d + b;
    PRINT(c);
    c = -a + b;
    PRINT(c);

    Vector2 ab(A, B);
    Vector2 ac(A, C);
    PRINT(ab);
    PRINT(ac);

    PRINT(a.GetNorm());
    PRINT(b.GetNorm());
    PRINT(d.GetNorm());
    PRINT(ab.GetNorm());
    PRINT(ac.GetNorm());

    PRINT(Angle(ab, ac) / std::numbers::pi * 180.f);
    PRINT(Angle(ac, ab) / std::numbers::pi * 180.f);

    PRINT(DotProduct(a, b));
    PRINT(DotProduct(a, d));
    PRINT(DotProduct(ab, ac));

    Vector2 bc(B, C);
    PRINT(bc);
    Vector2 cd(C, D);
    PRINT(cd);
    PRINT(DotProduct(bc, cd));
    PRINT(Determinant(ab, ac));

    Vector2 K = A + ab;
    PRINT(K);
#pragma endregion
    */

    /*void* addr = _AddressOfReturnAddress();
    printf("%p\n", addr);
    Func_T ptr = *(Func_T*)addr;
    printf("%p\n", ptr);

    ptr();*/

    Matrix mat = {
        { 6, 2, 4, 8, 2, 1, 9, 4, 3, 5, 9, 4, 2, 4, 6, 2, 6, 4, 5, 5 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 2, -4, 8, 4, 6, 9, 7, 2, 3, 5, 8, 6, 1, 9, 2, 5, 8, 7, 2, 9 },
        { 3, 6, 9, 8, 6, 9, 8, 4, 3, 5 ,7, 2, 3, 6, 4, 1, 5, 2, 3, 7 }
    };

    //Matrix result = Matrix::Inverse(mat/*, mat2*/);
    std::chrono::time_point start = std::chrono::system_clock::now();
    PRINT(mat.Determinant());
    std::cout << std::chrono::system_clock::now() - start << std::endl;
    //PRINT(result);

    return 0;
}
