#include "pch.h"

// ReSharper disable CppNoDiscardExpression
#include <chrono>
#include <functional>
#include <numeric>

namespace TestCalc
{
    TEST(calc, Sign)
    {
        EXPECT_EQ(calc::Sign(17.8f), 1.f);
        EXPECT_EQ(calc::Sign(-86.1f), -1.f);
    }

    TEST(calc, Abs)
    {
        EXPECT_EQ(calc::Abs(17.8f), 17.8f);
        EXPECT_EQ(calc::Abs(-86.1f), 86.1f);
    }

    TEST(calc, IsZero)
    {
        EXPECT_TRUE(calc::IsZero(calc::Zero));
        EXPECT_TRUE(calc::IsZero(0.000001f));
    }

    TEST(calc, Equals)
    {
        EXPECT_TRUE(calc::Equals(1.f, 1.00000075f));
    }
}

namespace TestVector2
{
    constexpr vec2 UnitX = vec2::UnitX();
    constexpr vec2 UnitY = vec2::UnitY();

    TEST(Vector2, Constants)
    {
        EXPECT_EQ(vec2::Zero(), vec2());
    
        EXPECT_EQ(UnitX, vec2(1.f, 0.f));
        EXPECT_EQ(UnitY, vec2(0.f, 1.f));
    }

    constexpr vec2 X4(4.f, 0.f);
    constexpr vec2 Y4(0.f, 4.f);
    
    TEST(Vector2, LengthAndNormalization)
    {
        EXPECT_EQ(X4.SquaredLength(), 16.f);
        EXPECT_EQ(Y4.Length(), 4.f);
    
        EXPECT_EQ(X4.Normalized().SquaredLength(), 1.f);
        EXPECT_EQ(Y4.Normalized().Length(), 1.f);
    }

    TEST(Vector2, Normal)
    {
        bool check = UnitX.Normal() == UnitY || UnitX.Normal() == -UnitY;
        EXPECT_TRUE(check);
        check = UnitY.Normal() == UnitX || UnitY.Normal() == -UnitX;
        EXPECT_TRUE(check);
    }

    TEST(Vector2, DotProduct)
    {
        EXPECT_EQ(vec2::Dot(UnitX, UnitY), 0.f);
        EXPECT_EQ(vec2::Dot(UnitX, UnitX), 1.f);
        EXPECT_EQ(vec2::Dot(UnitX, -UnitX), -1.f);
    }

    TEST(Vector2, Lerp)
    {
        EXPECT_EQ(vec2::Lerp(vec2::Zero(), vec2(1.f), 0.5f), vec2(0.5f));
    }
    
    TEST(Vector2, SubscriptOutOfRangeThrow)
    {
        EXPECT_THROW(UnitX[2], std::out_of_range);
    }
}

namespace TestVector2i
{
    constexpr vec2i UnitX = vec2i::UnitX();
    constexpr vec2i UnitY = vec2i::UnitY();

    constexpr vec2i X4(4, 0);
    constexpr vec2i Y4(0, 4);

    TEST(Vector2i, Constants)
    {
        EXPECT_EQ(vec2i::Zero(), vec2i());
    
        EXPECT_EQ(UnitX, vec2i(1, 0));
        EXPECT_EQ(UnitY, vec2i(0, 1));
    }
    
    TEST(Vector2i, LengthAndNormalization)
    {
        EXPECT_EQ(X4.SquaredLength(), 16);
        EXPECT_EQ(Y4.Length(), 4);
    
        EXPECT_EQ(X4.Normalized().SquaredLength(), 1);
        EXPECT_EQ(Y4.Normalized().Length(), 1);
    }

    TEST(Vector2i, Normal)
    {
        bool check = UnitX.Normal() == static_cast<vec2>(UnitY) || UnitX.Normal() == static_cast<vec2>(-UnitY);
        EXPECT_TRUE(check);
        check = UnitY.Normal() == static_cast<vec2>(UnitX) || UnitY.Normal() == static_cast<vec2>(-UnitX);
        EXPECT_TRUE(check);
    }

    TEST(Vector2i, DotProduct)
    {
        EXPECT_EQ(vec2i::Dot(UnitX, UnitY), 0.f);
        EXPECT_EQ(vec2i::Dot(UnitX, UnitX), 1.f);
        EXPECT_EQ(vec2i::Dot(UnitX, -UnitX), -1.f);
    }
    
    TEST(Vector2i, SubscriptOutOfRangeThrow)
    {
        EXPECT_THROW(UnitX[2], std::out_of_range);
    }
}

namespace TestVector3
{
    constexpr vec3 UnitX = vec3::UnitX();
    constexpr vec3 UnitY = vec3::UnitY();
    constexpr vec3 UnitZ = vec3::UnitZ();

    constexpr vec3 X4(4.f, 0.f, 0.f);
    constexpr vec3 Y4(0.f, 4.f, 0.f);

    TEST(Vector3, Constants)
    {
        EXPECT_EQ(vec3::Zero(), vec3());
    
        EXPECT_EQ(UnitX, vec3(1.f, 0.f, 0.f));
        EXPECT_EQ(UnitY, vec3(0.f, 1.f, 0.f));
        EXPECT_EQ(UnitZ, vec3(0.f, 0.f, 1.f));
    }

    TEST(Vector3, LengthAndNormalization)
    {
        EXPECT_EQ(X4.SquaredLength(), 16.f);
        EXPECT_EQ(Y4.Length(), 4.f);
    
        EXPECT_EQ(X4.Normalized().SquaredLength(), 1.f);
        EXPECT_EQ(Y4.Normalized().Length(), 1.f);
    }

    TEST(Vector3, DotProduct)
    {
        EXPECT_EQ(vec3::Dot(UnitX, UnitY), 0.f);
        EXPECT_EQ(vec3::Dot(UnitX, UnitX), 1.f);
        EXPECT_EQ(vec3::Dot(UnitX, -UnitX), -1.f);
    }

    TEST(Vector3, Lerp)
    {
        EXPECT_EQ(vec3::Lerp(vec3::Zero(), vec3(1.f), 0.5f), vec3(0.5f));
    }

    TEST(Vector3, SubscriptOutOfRangeThrow)
    {
        EXPECT_THROW(UnitX[3], std::out_of_range);
    }
}

namespace TestVector4
{
    constexpr vec4 UnitX = vec4::UnitX();
    constexpr vec4 UnitY = vec4::UnitY();
    constexpr vec4 UnitZ = vec4::UnitZ();
    constexpr vec4 UnitW = vec4::UnitW();

    constexpr vec4 X4(4.f, 0.f, 0.f, 0.f);
    constexpr vec4 Y4(0.f, 4.f, 0.f, 0.f);

    TEST(Vector4, Constants)
    {
        EXPECT_EQ(vec4::Zero(), vec4());
    
        EXPECT_EQ(UnitX, vec4(1.f, 0.f, 0.f, 0.f));
        EXPECT_EQ(UnitY, vec4(0.f, 1.f, 0.f, 0.f));
        EXPECT_EQ(UnitZ, vec4(0.f, 0.f, 1.f, 0.f));
        EXPECT_EQ(UnitW, vec4(0.f, 0.f, 0.f, 1.f));
    }
    TEST(Vector4, LengthAndNormalization)
    {
        EXPECT_EQ(X4.SquaredLength(), 16.f);
        EXPECT_EQ(Y4.Length(), 4.f);
    
        EXPECT_EQ(X4.Normalized().SquaredLength(), 1.f);
        EXPECT_EQ(Y4.Normalized().Length(), 1.f);
    }

    TEST(Vector4, DotProduct)
    {
        EXPECT_EQ(vec4::Dot(UnitX, UnitY), 0.f);
        EXPECT_EQ(vec4::Dot(UnitX, UnitX), 1.f);
        EXPECT_EQ(vec4::Dot(UnitX, -UnitX), -1.f);
    }

    TEST(Vector4, Lerp)
    {
        EXPECT_EQ(vec4::Lerp(vec4::Zero(), vec4(1.f), 0.5f), vec4(0.5f));
    }
    
    TEST(Vector4, SubscriptOutOfRangeThrow)
    {
        EXPECT_THROW(UnitX[4], std::out_of_range);
    }

    TEST(Vector4, CastToMatrixBackToVector4)
    {
        EXPECT_EQ(X4, static_cast<vec4>(static_cast<mat4>(X4)));
    }
}

namespace TestQuaternion
{
    constexpr quat UnitX = quat::UnitX();
    constexpr quat UnitY = quat::UnitY();
    constexpr quat UnitZ = quat::UnitZ();
    constexpr quat UnitW = quat::UnitW();

    constexpr quat X4(4.f, 0.f, 0.f, 0.f);
    constexpr quat Y4(0.f, 4.f, 0.f, 0.f);

    const quat RotationHalfCircleZ = quat::FromAxisAngle(vec3::UnitZ(), calc::PiOver2);
    const vec3 RotatedUnitX = quat::Rotate(vec3::UnitX(), RotationHalfCircleZ);

    TEST(Quaternion, Constants)
    {
        EXPECT_EQ(quat::Zero(), quat());
    
        EXPECT_EQ(UnitX, quat(1.f, 0.f, 0.f, 0.f));
        EXPECT_EQ(UnitY, quat(0.f, 1.f, 0.f, 0.f));
        EXPECT_EQ(UnitZ, quat(0.f, 0.f, 1.f, 0.f));
        EXPECT_EQ(UnitW, quat(0.f, 0.f, 0.f, 1.f));
    
        EXPECT_EQ(UnitW, quat::Identity());
    }

    TEST(Quaternion, LengthAndNormalization)
    {
        EXPECT_EQ(X4.SquaredLength(), 16.f);
        EXPECT_EQ(Y4.Length(), 4.f);
    
        EXPECT_EQ(X4.Normalized().SquaredLength(), 1.f);
        EXPECT_EQ(Y4.Normalized().Length(), 1.f);
    }

    TEST(Quaternion, DotProduct)
    {
        EXPECT_EQ(quat::Dot(UnitX, UnitY), 0.f);
        EXPECT_EQ(quat::Dot(UnitX, UnitX), 1.f);
        EXPECT_EQ(quat::Dot(UnitX, -UnitX), -1.f);
    }

    TEST(Quaternion, Lerp)
    {
        EXPECT_EQ(quat::Lerp(quat::Zero(), quat(1.f), 0.5f), quat(0.5f));
        EXPECT_EQ(quat::Slerp(quat::Zero(), quat(1.f), 0.5f), quat(0.707107f));
    }

    TEST(Quaternion, SubscriptOutOfRangeThrow)
    {
        EXPECT_THROW(UnitX[4], std::out_of_range);
    }

    TEST(Quaternion, Rotation)
    {
        EXPECT_EQ(RotatedUnitX, vec3::UnitY());
        
        EXPECT_EQ(quat(RotatedUnitX), RotationHalfCircleZ * vec3::UnitX() * RotationHalfCircleZ.Conjugate());
        
        EXPECT_EQ(RotationHalfCircleZ, quat::FromEuler(vec3(0.f, 0.f, calc::PiOver2)));
        EXPECT_EQ(RotationHalfCircleZ, quat::FromRotationMatrix(mat::RotationZ(calc::PiOver2)));
    }

    TEST(Quaternion, Inversion)
    {
        EXPECT_EQ(quat::Rotate(RotatedUnitX, RotationHalfCircleZ.Invert()), vec3::UnitX());
    }
}

namespace TestMatrix
{
    constexpr mat Zero = mat();
    constexpr mat Identity = mat::Identity();

    constexpr vec3 One(1.f);
    const mat RotationHalfCircleZ = mat::RotationZ(calc::PiOver2);
    const mat Trs = mat::Trs(One, RotationHalfCircleZ, 2.f);

    constexpr mat Symmetric(
        1.f, 2.f, 3.f, 4.f,
        2.f, 5.f, 6.f, 7.f,
        3.f, 6.f, 8.f, 9.f,
        4.f, 7.f, 9.f, 10.f
    );
    constexpr mat Antisymmetric(
        1.f, 2.f, 3.f, 4.f,
       -2.f, 5.f, 6.f, 7.f,
       -3.f,-6.f, 8.f, 9.f,
       -4.f,-7.f,-9.f, 10.f
    );

    constexpr vec3 OneTwoThree(1.f, 2.f, 3.f);

    TEST(Matrix, Constants)
    {
        EXPECT_EQ(Identity, mat(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f));
    }

    TEST(Matrix, CheckFunctions)
    {
        EXPECT_TRUE(Identity.IsDiagonal());
        EXPECT_FALSE(Trs.IsDiagonal());

        EXPECT_TRUE(Identity.IsIdentity());
        EXPECT_FALSE(Zero.IsIdentity());
        EXPECT_FALSE(Trs.IsIdentity());

        EXPECT_TRUE(Zero.IsNull());
        EXPECT_FALSE(Trs.IsNull());
            
        EXPECT_TRUE(Identity.IsSymmetric());
        EXPECT_TRUE(Symmetric.IsSymmetric());
        EXPECT_FALSE(Antisymmetric.IsSymmetric());
        EXPECT_FALSE(Trs.IsSymmetric());
            
        EXPECT_TRUE(Identity.IsAntisymmetric());
        EXPECT_TRUE(Antisymmetric.IsAntisymmetric());
        EXPECT_FALSE(Symmetric.IsAntisymmetric());
        EXPECT_FALSE(Trs.IsAntisymmetric());
    }

    TEST(Matrix, SmallFunctions)
    {
        EXPECT_EQ(Identity.Diagonal(), vec4(1.f));
            
        EXPECT_EQ(Identity.Determinant(), 1.f);
        EXPECT_EQ(Trs.Determinant(), 8.f);
        EXPECT_EQ(Zero.Determinant(), 0.f);

        EXPECT_EQ(Identity, Identity.Transposed());
    }

    TEST(Matrix, Inversion)
    {
        EXPECT_EQ(Trs * Trs.Inverted(), Identity);
    }

    TEST(Matrix, Translation)
    {
        EXPECT_EQ(mat::Translation(OneTwoThree) * One, vec3(2.f, 3.f, 4.f));
    }

    TEST(Matrix, Rotation)
    {
        EXPECT_EQ(mat::RotationZ(calc::PiOver2) * vec3::UnitX(), vec3::UnitY());
    }

    TEST(Matrix, Scaling)
    {
        EXPECT_EQ(mat::Scaling(OneTwoThree) * One, OneTwoThree);
    }

    TEST(Matrix, Subscript)
    {
        EXPECT_THROW(Zero.At(4, 0), std::out_of_range);
        EXPECT_THROW(Zero.At(0, 4), std::out_of_range);
        EXPECT_THROW(Zero.At(4, 4), std::out_of_range);
        EXPECT_NO_THROW(Zero.At(1, 2));
    }
}
