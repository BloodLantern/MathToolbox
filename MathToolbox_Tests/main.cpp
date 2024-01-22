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
        CHECK(calc::Equals(1.f, 1.0000075f));
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
        CHECK(unitX.Normal() == unitY || unitX.Normal() == -unitY);
        CHECK(unitY.Normal() == unitX || unitY.Normal() == -unitX);
    }

    SUBCASE("Dot product")
    {
        CHECK_EQ(vec2::Dot(unitX, unitY), 0.f);
        CHECK_EQ(vec2::Dot(unitX, -unitX), 1.f);
    }

    SUBCASE("Lerp")
        CHECK_EQ(vec2::Lerp(vec2::Zero(), vec2(1.f), 0.5f), vec2(0.5f));
    
    SUBCASE("Subscript out of range throw")
        CHECK_THROWS(unitX[2]);
}

TEST_CASE("Vector2i")
{
    constexpr vec2i unitX = vec2i::UnitX();
    constexpr vec2i unitY = vec2i::UnitY();
    
    SUBCASE("Constants")
    {
        CHECK_EQ(vec2i::Zero(), vec2i());
    
        CHECK_EQ(unitX, vec2i(1.f, 0.f));
        CHECK_EQ(unitY, vec2i(0.f, 1.f));
    }

    constexpr vec2i x4(4.f, 0.f);
    constexpr vec2i y4(0.f, 4.f);
    
    SUBCASE("Length and normalization")
    {
        CHECK_EQ(x4.SquaredLength(), 16.f);
        CHECK_EQ(y4.Length(), 4.f);
    
        CHECK_EQ(x4.Normalized().SquaredLength(), 1.f);
        CHECK_EQ(y4.Normalized().Length(), 1.f);
    }

    SUBCASE("Normal")
    {
        CHECK(unitX.Normal() == (vec2) unitY || unitX.Normal() == (vec2) -unitY);
        CHECK(unitY.Normal() == (vec2) unitX || unitY.Normal() == (vec2) -unitX);
    }

    SUBCASE("Dot product")
    {
        CHECK_EQ(vec2i::Dot(unitX, unitY), 0.f);
        CHECK_EQ(vec2i::Dot(unitX, -unitX), 1.f);
    }
    
    SUBCASE("Subscript out of range throw")
        CHECK_THROWS(unitX[2]);
}

TEST_CASE("Vector3")
{
    constexpr vec3 unitX = vec3::UnitX();
    constexpr vec3 unitY = vec3::UnitY();
    constexpr vec3 unitZ = vec3::UnitZ();
    
    CHECK_EQ(vec3::Zero(), vec3());
    
    CHECK_EQ(unitX, vec3(1.f, 0.f, 0.f));
    CHECK_EQ(unitY, vec3(0.f, 1.f, 0.f));
    CHECK_EQ(unitZ, vec3(0.f, 0.f, 1.f));

    constexpr vec3 x4(4.f, 0.f, 0.f);
    constexpr vec3 y4(0.f, 4.f, 0.f);
    CHECK_EQ(x4.SquaredLength(), 16.f);
    CHECK_EQ(y4.Length(), 4.f);
    
    CHECK_EQ(x4.Normalized().SquaredLength(), 1.f);
    CHECK_EQ(y4.Normalized().Length(), 1.f);

    CHECK_EQ(vec3::Dot(unitX, unitY), 0.f);
    CHECK_EQ(vec3::Dot(unitX, -unitX), 1.f);

    CHECK_EQ(vec3::Lerp(vec3::Zero(), vec3(1.f), 0.5f), vec3(0.5f));
    
    CHECK_THROWS(unitX[3]);
}

TEST_CASE("Vector4")
{
    CHECK_EQ(vec4::Zero(), vec4());
    
    constexpr vec4 unitX = vec4::UnitX();
    constexpr vec4 unitY = vec4::UnitY();
    constexpr vec4 unitZ = vec4::UnitZ();
    constexpr vec4 unitW = vec4::UnitW();
    
    CHECK_EQ(unitX, vec4(1.f, 0.f, 0.f, 0.f));
    CHECK_EQ(unitY, vec4(0.f, 1.f, 0.f, 0.f));
    CHECK_EQ(unitZ, vec4(0.f, 0.f, 1.f, 0.f));
    CHECK_EQ(unitW, vec4(0.f, 0.f, 0.f, 1.f));

    constexpr vec4 x4(4.f, 0.f, 0.f, 0.f);
    constexpr vec4 y4(0.f, 4.f, 0.f, 0.f);
    CHECK_EQ(x4.SquaredLength(), 16.f);
    CHECK_EQ(y4.Length(), 4.f);
    
    CHECK_EQ(x4.Normalized().SquaredLength(), 1.f);
    CHECK_EQ(y4.Normalized().Length(), 1.f);

    CHECK_EQ(vec4::Dot(unitX, unitY), 0.f);
    CHECK_EQ(vec4::Dot(unitX, -unitX), 1.f);

    CHECK_EQ(vec4::Lerp(vec4::Zero(), vec4(1.f), 0.5f), vec4(0.5f));
    
    CHECK_THROWS(unitX[4]);

    CHECK_EQ(x4, (vec4) (mat4) x4);
}

TEST_CASE("Quaternion")
{
    CHECK_EQ(quat::Zero(), quat());
    
    constexpr quat unitX = quat::UnitX();
    constexpr quat unitY = quat::UnitY();
    constexpr quat unitZ = quat::UnitZ();
    constexpr quat unitW = quat::UnitW();
    
    CHECK_EQ(unitX, quat(1.f, 0.f, 0.f, 0.f));
    CHECK_EQ(unitY, quat(0.f, 1.f, 0.f, 0.f));
    CHECK_EQ(unitZ, quat(0.f, 0.f, 1.f, 0.f));
    CHECK_EQ(unitW, quat(0.f, 0.f, 0.f, 1.f));
    
    CHECK_EQ(unitW, quat::Identity());

    constexpr quat x4(4.f, 0.f, 0.f, 0.f);
    constexpr quat y4(0.f, 4.f, 0.f, 0.f);
    CHECK_EQ(x4.SquaredLength(), 16.f);
    CHECK_EQ(y4.Length(), 4.f);
    
    CHECK_EQ(x4.Normalized().SquaredLength(), 1.f);
    CHECK_EQ(y4.Normalized().Length(), 1.f);

    CHECK_EQ(quat::Dot(unitX, unitY), 0.f);
    CHECK_EQ(quat::Dot(unitX, -unitX), 1.f);

    CHECK_EQ(quat::Lerp(quat::Zero(), quat(1.f), 0.5f), quat(0.5f));
    
    CHECK_THROWS(unitX[4]);

    constexpr quat rotationHalfCircleZ = quat::FromAxisAngle(vec3::UnitZ(), calc::PiOver2);
    constexpr vec3 rotatedUnitX = quat::Rotate(vec3::UnitX(), rotationHalfCircleZ);
    CHECK_EQ(quat(rotatedUnitX), rotationHalfCircleZ * vec3::UnitX() * rotationHalfCircleZ.Conjugate());
}
