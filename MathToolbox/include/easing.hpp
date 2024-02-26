#pragma once

#include "calc.hpp"

namespace Easing
{
    /// @brief The SineIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInSine">SineIn</a> easing function.
    float SineIn(float t);


    /// @brief The SineOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutSine">SineOut</a> easing function.
    float SineOut(float t);


    /// @brief The SineInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutSine">SineInOut</a> easing function.
    float SineInOut(float t);


    /// @brief The QuadIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInQuad">QuadIn</a> easing function.
    float QuadIn(float t);


    /// @brief The QuadOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutQuad">QuadOut</a> easing function.
    float QuadOut(float t);


    /// @brief The QuadInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutQuad">QuadInOut</a> easing function.
    float QuadInOut(float t);


    /// @brief The CubicIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInCubic">CubicIn</a> easing function.
    float CubicIn(float t);


    /// @brief The CubicOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutCubic">CubicOut</a> easing function.
    float CubicOut(float t);


    /// @brief The CubicInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutCubic">CubicInOut</a> easing function.
    float CubicInOut(float t);


    /// @brief The QuartIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInQuart">QuartIn</a> easing function.
    float QuartIn(float t);


    /// @brief The QuartOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutQuart">QuartOut</a> easing function.
    float QuartOut(float t);


    /// @brief The QuartInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutQuart">QuartInOut</a> easing function.
    float QuartInOut(float t);


    /// @brief The QuintIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInQuint">QuintIn</a> easing function.
    float QuintIn(float t);


    /// @brief The QuintOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutQuint">QuintOut</a> easing function.
    float QuintOut(float t);


    /// @brief The QuintInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutQuint">QuintInOut</a> easing function.
    float QuintInOut(float t);


    /// @brief The ExpoIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInExpo">ExpoIn</a> easing function.
    float ExpoIn(float t);


    /// @brief The ExpoOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutExpo">ExpoOut</a> easing function.
    float ExpoOut(float t);


    /// @brief The ExpoInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutExpo">ExpoInOut</a> easing function.
    float ExpoInOut(float t);


    /// @brief The CircIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInCirc">CircIn</a> easing function.
    float CircIn(float t);


    /// @brief The CircOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutCirc">CircOut</a> easing function.
    float CircOut(float t);


    /// @brief The CircInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutCirc">CircInOut</a> easing function.
    float CircInOut(float t);


    /// @brief The BackIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInBack">BackIn</a> easing function.
    float BackIn(float t);


    /// @brief The BackOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutBack">BackOut</a> easing function.
    float BackOut(float t);


    /// @brief The BackInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutBack">BackInOut</a> easing function.
    float BackInOut(float t);


    /// @brief The ElasticIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInElastic">ElasticIn</a> easing function.
    float ElasticIn(float t);


    /// @brief The ElasticOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutElastic">ElasticOut</a> easing function.
    float ElasticOut(float t);


    /// @brief The ElasticInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutElastic">ElasticInOut</a> easing function.
    float ElasticInOut(float t);


    /// @brief The BounceIn easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInBounce">BounceIn</a> easing function.
    float BounceIn(float t);


    /// @brief The BounceOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeOutBounce">BounceOut</a> easing function.
    float BounceOut(float t);


    /// @brief The BounceInOut easing function.
    /// @param t The current time. Must be between 0 and 1 inclusive.
    /// @return The transformed time.
    /// @see The <a href="https://easings.net/#easeInOutBounce">BounceInOut</a> easing function.
    float BounceInOut(float t);
}
