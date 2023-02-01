// Toolbox++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Vector2.h"
#include "Point2.h"

#define PRINT(o) (std::cout << (o) << std::endl)

//using namespace Math;

int main()
{
    PRINT("Point 2 :\n");

    Point2 A(0.f, 0.f);
    Point2 B(4.f, 0.f);
    Point2 C(2.0, sqrt(3.f) / 2.f * (float) A.dist(B));
    PRINT(C);

    Point2 D = -B;
    PRINT(D);
    Point2 E = A.mid(B);
    PRINT(E);

    Point2 F = Point2::circumcenter(A, B, C);
    Point2 G = Point2::circumcenter(B, C, D);
    Point2 H = Point2::circumcenter(A, C, D);
    Point2 I = Point2::circumcenter(F, B, D);
    PRINT(F);
    PRINT(G);
    PRINT(H);
    PRINT(I);

    // Triangle stuff

    Point2 J = Point2::isobarycenterTriangle(A, B, C);
    PRINT(J);

    PRINT("\nVector 2 :\n");

    Vector2 a(2.f, 5.f);
    Vector2 b(3.f, -5.f);
    Vector2 c = a + b;
    PRINT(c);

    a = Vector2(3.f, 5.f);
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

    PRINT(a.getNorm());
    PRINT(b.getNorm());
    PRINT(d.getNorm());
    PRINT(ab.getNorm());
    PRINT(ac.getNorm());

    PRINT(ab.angle(ac) / M_PI * 180.f);
    PRINT(ac.angle(ab) / M_PI * 180.f);

    PRINT(a.dotProduct(b));
    PRINT(a.dotProduct(d));
    PRINT(ab.dotProduct(ac));

    Vector2 bc(B, C);
    PRINT(bc);
    Vector2 cd(C, D);
    PRINT(cd);
    PRINT(bc.dotProduct(cd));
    PRINT(ab.determinant(ac));

    Point2 K = A + ab;
    PRINT(K);

    return 0;
}
