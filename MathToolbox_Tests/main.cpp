// ReSharper disable CppNoDiscardExpression
#include <iostream>
#include <chrono>
#include <functional>
#include <numeric>

#include "math.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("calc")
{
    SUBCASE("Sign")
    {
        CHECK_EQ(calc::Sign(17.8f), 1.f);
        CHECK_EQ(calc::Sign(-86.1f), -1.f);
    }
    
    SUBCASE("Abs")
    {
        CHECK_EQ(calc::Abs(17.8f), 17.8f);
        CHECK_EQ(calc::Abs(-86.1f), 86.1f);
    }
    
    SUBCASE("IsZero")
    {
        CHECK(calc::IsZero(calc::Zero));
        CHECK(calc::IsZero(0.000001f));
    }
    
    SUBCASE("Equals")
    {
        CHECK(calc::Equals(1.f, 1.00000075f));
    }
}

TEST_CASE("Vector2")
{
    constexpr vec2 unitX = vec2::UnitX();
    constexpr vec2 unitY = vec2::UnitY();
    
    SUBCASE("Constants")
    {
        CHECK_EQ(vec2::Zero(), vec2());
    
        CHECK_EQ(unitX, vec2(1.f, 0.f));
        CHECK_EQ(unitY, vec2(0.f, 1.f));
    }

    constexpr vec2 x4(4.f, 0.f);
    constexpr vec2 y4(0.f, 4.f);
    
    SUBCASE("Length and normalization")
    {
        CHECK_EQ(x4.SquaredLength(), 16.f);
        CHECK_EQ(y4.Length(), 4.f);
    
        CHECK_EQ(x4.Normalized().SquaredLength(), 1.f);
        CHECK_EQ(y4.Normalized().Length(), 1.f);
    }

    SUBCASE("Normal")
    {
        bool check = unitX.Normal() == unitY || unitX.Normal() == -unitY;
        CHECK(check);
        check = unitY.Normal() == unitX || unitY.Normal() == -unitX;
        CHECK(check);
    }

    SUBCASE("Dot product")
    {
        CHECK_EQ(vec2::Dot(unitX, unitY), 0.f);
        CHECK_EQ(vec2::Dot(unitX, unitX), 1.f);
        CHECK_EQ(vec2::Dot(unitX, -unitX), -1.f);
    }

    SUBCASE("Lerp")
        CHECK_EQ(vec2::Lerp(vec2::Zero(), vec2(1.f), 0.5f), vec2(0.5f));
    
    SUBCASE("Subscript out of range throw")
        CHECK_THROWS_AS(unitX[2], std::out_of_range);
}

TEST_CASE("Vector2i")
{
    constexpr vec2i unitX = vec2i::UnitX();
    constexpr vec2i unitY = vec2i::UnitY();
    
    SUBCASE("Constants")
    {
        CHECK_EQ(vec2i::Zero(), vec2i());
    
        CHECK_EQ(unitX, vec2i(1, 0));
        CHECK_EQ(unitY, vec2i(0, 1));
    }

    constexpr vec2i x4(4, 0);
    constexpr vec2i y4(0, 4);
    
    SUBCASE("Length and normalization")
    {
        CHECK_EQ(x4.SquaredLength(), 16);
        CHECK_EQ(y4.Length(), 4);
    
        CHECK_EQ(x4.Normalized().SquaredLength(), 1);
        CHECK_EQ(y4.Normalized().Length(), 1);
    }

    SUBCASE("Normal")
    {
        bool check = unitX.Normal() == static_cast<vec2>(unitY) || unitX.Normal() == static_cast<vec2>(-unitY);
        CHECK(check);
        check = unitY.Normal() == static_cast<vec2>(unitX) || unitY.Normal() == static_cast<vec2>(-unitX);
        CHECK(check);
    }

    SUBCASE("Dot product")
    {
        CHECK_EQ(vec2i::Dot(unitX, unitY), 0.f);
        CHECK_EQ(vec2i::Dot(unitX, unitX), 1.f);
        CHECK_EQ(vec2i::Dot(unitX, -unitX), -1.f);
    }
    
    SUBCASE("Subscript out of range throw")
        CHECK_THROWS_AS(unitX[2], std::out_of_range);
}

TEST_CASE("Vector3")
{
    constexpr vec3 unitX = vec3::UnitX();
    constexpr vec3 unitY = vec3::UnitY();
    constexpr vec3 unitZ = vec3::UnitZ();

    SUBCASE("Constants")
    {
        CHECK_EQ(vec3::Zero(), vec3());
    
        CHECK_EQ(unitX, vec3(1.f, 0.f, 0.f));
        CHECK_EQ(unitY, vec3(0.f, 1.f, 0.f));
        CHECK_EQ(unitZ, vec3(0.f, 0.f, 1.f));
    }

    constexpr vec3 x4(4.f, 0.f, 0.f);
    constexpr vec3 y4(0.f, 4.f, 0.f);
    SUBCASE("Length and normalization")
    {
        CHECK_EQ(x4.SquaredLength(), 16.f);
        CHECK_EQ(y4.Length(), 4.f);
    
        CHECK_EQ(x4.Normalized().SquaredLength(), 1.f);
        CHECK_EQ(y4.Normalized().Length(), 1.f);
    }

    SUBCASE("Dot product")
    {
        CHECK_EQ(vec3::Dot(unitX, unitY), 0.f);
        CHECK_EQ(vec3::Dot(unitX, unitX), 1.f);
        CHECK_EQ(vec3::Dot(unitX, -unitX), -1.f);
    }

    SUBCASE("Lerp")
        CHECK_EQ(vec3::Lerp(vec3::Zero(), vec3(1.f), 0.5f), vec3(0.5f));

    SUBCASE("Subscript out of range throw")
        CHECK_THROWS_AS(unitX[3], std::out_of_range);
}

TEST_CASE("Vector4")
{
    constexpr vec4 unitX = vec4::UnitX();
    constexpr vec4 unitY = vec4::UnitY();
    constexpr vec4 unitZ = vec4::UnitZ();
    constexpr vec4 unitW = vec4::UnitW();

    SUBCASE("Constants")
    {
        CHECK_EQ(vec4::Zero(), vec4());
    
        CHECK_EQ(unitX, vec4(1.f, 0.f, 0.f, 0.f));
        CHECK_EQ(unitY, vec4(0.f, 1.f, 0.f, 0.f));
        CHECK_EQ(unitZ, vec4(0.f, 0.f, 1.f, 0.f));
        CHECK_EQ(unitW, vec4(0.f, 0.f, 0.f, 1.f));
    }

    constexpr vec4 x4(4.f, 0.f, 0.f, 0.f);
    constexpr vec4 y4(0.f, 4.f, 0.f, 0.f);
    SUBCASE("Length and normalization")
    {
        CHECK_EQ(x4.SquaredLength(), 16.f);
        CHECK_EQ(y4.Length(), 4.f);
    
        CHECK_EQ(x4.Normalized().SquaredLength(), 1.f);
        CHECK_EQ(y4.Normalized().Length(), 1.f);
    }

    SUBCASE("Dot product")
    {
        CHECK_EQ(vec4::Dot(unitX, unitY), 0.f);
        CHECK_EQ(vec4::Dot(unitX, unitX), 1.f);
        CHECK_EQ(vec4::Dot(unitX, -unitX), -1.f);
    }

    SUBCASE("Lerp")
        CHECK_EQ(vec4::Lerp(vec4::Zero(), vec4(1.f), 0.5f), vec4(0.5f));
    
    SUBCASE("Subscript out of range throw")
        CHECK_THROWS_AS(unitX[4], std::out_of_range);

    SUBCASE("Cast to matrix, back to vec4")
        CHECK_EQ(x4, static_cast<vec4>(static_cast<mat4>(x4)));
}

TEST_CASE("Quaternion")
{
    constexpr quat unitX = quat::UnitX();
    constexpr quat unitY = quat::UnitY();
    constexpr quat unitZ = quat::UnitZ();
    constexpr quat unitW = quat::UnitW();

    SUBCASE("Constants")
    {
        CHECK_EQ(quat::Zero(), quat());
    
        CHECK_EQ(unitX, quat(1.f, 0.f, 0.f, 0.f));
        CHECK_EQ(unitY, quat(0.f, 1.f, 0.f, 0.f));
        CHECK_EQ(unitZ, quat(0.f, 0.f, 1.f, 0.f));
        CHECK_EQ(unitW, quat(0.f, 0.f, 0.f, 1.f));
    
        CHECK_EQ(unitW, quat::Identity());
    }

    constexpr quat x4(4.f, 0.f, 0.f, 0.f);
    constexpr quat y4(0.f, 4.f, 0.f, 0.f);
    SUBCASE("Length and normalization")
    {
        CHECK_EQ(x4.SquaredLength(), 16.f);
        CHECK_EQ(y4.Length(), 4.f);
    
        CHECK_EQ(x4.Normalized().SquaredLength(), 1.f);
        CHECK_EQ(y4.Normalized().Length(), 1.f);
    }

    SUBCASE("Dot product")
    {
        CHECK_EQ(quat::Dot(unitX, unitY), 0.f);
        CHECK_EQ(quat::Dot(unitX, unitX), 1.f);
        CHECK_EQ(quat::Dot(unitX, -unitX), -1.f);
    }

    SUBCASE("Lerp")
    {
        CHECK_EQ(quat::Lerp(quat::Zero(), quat(1.f), 0.5f), quat(0.5f));
        CHECK_EQ(quat::Slerp(quat::Zero(), quat(1.f), 0.5f), quat(0.707107f));
    }

    SUBCASE("Subscript out of range throw")
        CHECK_THROWS_AS(unitX[4], std::out_of_range);

    const quat rotationHalfCircleZ = quat::FromAxisAngle(vec3::UnitZ(), calc::PiOver2);
    const vec3 rotatedUnitX = quat::Rotate(vec3::UnitX(), rotationHalfCircleZ);
    SUBCASE("Rotation")
    {
        CHECK_EQ(rotatedUnitX, vec3::UnitY());
        
        CHECK_EQ(quat(rotatedUnitX), rotationHalfCircleZ * vec3::UnitX() * rotationHalfCircleZ.Conjugate());
        
        CHECK_EQ(rotationHalfCircleZ, quat::FromEuler(vec3(0.f, 0.f, calc::PiOver2)));
        CHECK_EQ(rotationHalfCircleZ, quat::FromRotationMatrix(mat::RotationZ(calc::PiOver2)));
    }

    SUBCASE("Inversion")
        CHECK_EQ(quat::Rotate(rotatedUnitX, rotationHalfCircleZ.Invert()), vec3::UnitX());
}

TEST_CASE("Matrix")
{
    constexpr mat zero = mat();
    constexpr mat identity = mat::Identity();

    SUBCASE("Constants")
        CHECK_EQ(identity, mat(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f));

    constexpr vec3 one(1.f);
    const mat rotationHalfCircleZ = mat::RotationZ(calc::PiOver2);
    const mat trs = mat::Trs(one, rotationHalfCircleZ, 2.f);

    SUBCASE("Check functions")
    {
        CHECK(identity.IsDiagonal());
        CHECK_FALSE(trs.IsDiagonal());

        CHECK(identity.IsIdentity());
        CHECK_FALSE(zero.IsIdentity());
        CHECK_FALSE(trs.IsIdentity());

        CHECK(zero.IsNull());
        CHECK_FALSE(trs.IsNull());

        constexpr mat symmetric(
            1.f, 2.f, 3.f, 4.f,
            2.f, 5.f, 6.f, 7.f,
            3.f, 6.f, 8.f, 9.f,
            4.f, 7.f, 9.f, 10.f
        );
        constexpr mat antisymmetric(
            1.f, 2.f, 3.f, 4.f,
           -2.f, 5.f, 6.f, 7.f,
           -3.f,-6.f, 8.f, 9.f,
           -4.f,-7.f,-9.f, 10.f
        );
        CHECK(identity.IsSymmetric());
        CHECK(symmetric.IsSymmetric());
        CHECK_FALSE(antisymmetric.IsSymmetric());
        CHECK_FALSE(trs.IsSymmetric());
        
        CHECK(identity.IsAntisymmetric());
        CHECK(antisymmetric.IsAntisymmetric());
        CHECK_FALSE(symmetric.IsAntisymmetric());
        CHECK_FALSE(trs.IsAntisymmetric());
    }

    SUBCASE("Small functions")
    {
        CHECK_EQ(identity.Diagonal(), vec4(1.f));
        
        CHECK_EQ(identity.Determinant(), 1.f);
        CHECK_EQ(trs.Determinant(), 8.f);
        CHECK_EQ(zero.Determinant(), 0.f);

        CHECK_EQ(identity, identity.Transposed());
    }

    SUBCASE("Inversion")
        CHECK_EQ(trs * trs.Inverted(), identity);

    constexpr vec3 oneTwoThree(1.f, 2.f, 3.f);
    SUBCASE("Translation")
        CHECK_EQ(mat::Translation(oneTwoThree) * one, vec3(2.f, 3.f, 4.f));

    SUBCASE("Rotation")
        CHECK_EQ(mat::RotationZ(calc::PiOver2) * vec3::UnitX(), vec3::UnitY());

    SUBCASE("Scaling")
        CHECK_EQ(mat::Scaling(oneTwoThree) * one, oneTwoThree);

    SUBCASE("Subscript")
    {
        CHECK_THROWS_AS(zero.At(4, 0), std::out_of_range);
        CHECK_THROWS_AS(zero.At(0, 4), std::out_of_range);
        CHECK_THROWS_AS(zero.At(4, 4), std::out_of_range);
        CHECK_NOTHROW(zero.At(1, 2));
    }
}
