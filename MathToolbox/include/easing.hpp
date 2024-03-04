#pragma once

#include "calc.hpp"

namespace Easing
{
    /// @brief The SineIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInSine">SineIn</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float SineIn(float t);


    /// @brief The SineOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutSine">SineOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float SineOut(float t);


    /// @brief The SineInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutSine">SineInOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float SineInOut(float t);


    /// @brief The QuadIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInQuad">QuadIn</a> easing function.
    [[nodiscard]]
    constexpr float QuadIn(float t);


    /// @brief The QuadOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutQuad">QuadOut</a> easing function.
    [[nodiscard]]
    constexpr float QuadOut(float t);


    /// @brief The QuadInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutQuad">QuadInOut</a> easing function.
    [[nodiscard]]
    constexpr float QuadInOut(float t);


    /// @brief The CubicIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInCubic">CubicIn</a> easing function.
    [[nodiscard]]
    constexpr float CubicIn(float t);


    /// @brief The CubicOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutCubic">CubicOut</a> easing function.
    [[nodiscard]]
    constexpr float CubicOut(float t);


    /// @brief The CubicInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutCubic">CubicInOut</a> easing function.
    [[nodiscard]]
    constexpr float CubicInOut(float t);


    /// @brief The QuartIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInQuart">QuartIn</a> easing function.
    [[nodiscard]]
    constexpr float QuartIn(float t);


    /// @brief The QuartOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutQuart">QuartOut</a> easing function.
    [[nodiscard]]
    constexpr float QuartOut(float t);


    /// @brief The QuartInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutQuart">QuartInOut</a> easing function.
    [[nodiscard]]
    constexpr float QuartInOut(float t);


    /// @brief The QuintIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInQuint">QuintIn</a> easing function.
    [[nodiscard]]
    constexpr float QuintIn(float t);


    /// @brief The QuintOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutQuint">QuintOut</a> easing function.
    [[nodiscard]]
    constexpr float QuintOut(float t);


    /// @brief The QuintInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutQuint">QuintInOut</a> easing function.
    [[nodiscard]]
    constexpr float QuintInOut(float t);


    /// @brief The ExpoIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInExpo">ExpoIn</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float ExpoIn(float t);


    /// @brief The ExpoOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutExpo">ExpoOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float ExpoOut(float t);


    /// @brief The ExpoInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutExpo">ExpoInOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float ExpoInOut(float t);


    /// @brief The CircIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInCirc">CircIn</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float CircIn(float t);


    /// @brief The CircOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutCirc">CircOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float CircOut(float t);


    /// @brief The CircInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutCirc">CircInOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float CircInOut(float t);


    /// @brief The BackIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInBack">BackIn</a> easing function.
    [[nodiscard]]
    constexpr float BackIn(float t);


    /// @brief The BackOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutBack">BackOut</a> easing function.
    [[nodiscard]]
    constexpr float BackOut(float t);


    /// @brief The BackInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutBack">BackInOut</a> easing function.
    [[nodiscard]]
    constexpr float BackInOut(float t);


    /// @brief The ElasticIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInElastic">ElasticIn</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float ElasticIn(float t);


    /// @brief The ElasticOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutElastic">ElasticOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float ElasticOut(float t);


    /// @brief The ElasticInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutElastic">ElasticInOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float ElasticInOut(float t);


    /// @brief The BounceIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInBounce">BounceIn</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float BounceIn(float t);


    /// @brief The BounceOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutBounce">BounceOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float BounceOut(float t);


    /// @brief The BounceInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutBounce">BounceInOut</a> easing function.
    [[nodiscard]]
    MATH_TOOLBOX float BounceInOut(float t);
}

constexpr float Easing::QuadIn(const float t)
{
    return t * t;
}

constexpr float Easing::QuadOut(const float t)
{
    return t * (2.f - t);
}

constexpr float Easing::QuadInOut(const float t)
{
    return t < 0.5f ? 2.f * t * t : t * (4.f - 2.f * t) - 1.f;
}

constexpr float Easing::CubicIn(const float t)
{
    return t * t * t;
}

constexpr float Easing::CubicOut(float t)
{
    t--;
    return 1.f + t * t * t;
}

constexpr float Easing::CubicInOut(const float t)
{
    float t2 = t - 1;
    float t3 = t2 - 1;
    return t < 0.5f ? 4.f * t * t * t : 1.f + t2 * (2.f * t3) * (2.f * t3);
}

constexpr float Easing::QuartIn(float t)
{
    t *= t;
    return t * t;
}

constexpr float Easing::QuartOut(const float t)
{
    float t2 = t - 1;
    t2 *= t2;
    return 1.f - t2 * t2;
}

constexpr float Easing::QuartInOut(float t)
{
    if (t < 0.5f)
    {
        t *= t;
        return 8.f * t * t;
    }
    else
    {
        t -= 1;
        t = t * t;
        return 1.f - 8.f * t * t;
    }
}

constexpr float Easing::QuintIn(const float t)
{
    float t2 = t * t;
    return t * t2 * t2;
}

constexpr float Easing::QuintOut(float t)
{
    t -= 1;
    float t2 = t * t;
    return 1.f + t * t2 * t2;
}

constexpr float Easing::QuintInOut(float t)
{
    float t2;
    if (t < 0.5f)
    {
        t2 = t * t;
        return 16.f * t * t2 * t2;
    }
    else
    {
        t -= 1;
        t2 = t * t;
        return 1.f + 16.f * t * t2 * t2;
    }
}

constexpr float Easing::BackIn(const float t)
{
    return t * t * (2.70158f * t - 1.70158f);
}

constexpr float Easing::BackOut(float t)
{
    t -= 1;
    return 1.f + t * t * (2.70158f * t + 1.70158f);
}

constexpr float Easing::BackInOut(float t)
{
    if (t < 0.5f)
    {
        return t * t * (7.f * t - 2.5f) * 2.f;
    }
    else
    {
        t -= 1;
        return 1.f + t * t * 2.f * (7.f * t + 2.5f);
    }
}
