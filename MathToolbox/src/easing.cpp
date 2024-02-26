#include "easing.hpp"

#include <cmath>

float Easing::SineIn(const float t)
{
    return std::sin(Calc::PiOver2 * t);
}

float Easing::SineOut(const float t)
{
    return 1.f + std::sin(Calc::PiOver2 * (t - 1));
}

float Easing::SineInOut(const float t)
{
    return 0.5f * (1.f + std::sin(Calc::Pi * (t - 0.5f)));
}

float Easing::QuadIn(const float t)
{
    return t * t;
}

float Easing::QuadOut(const float t)
{
    return t * (2.f - t);
}

float Easing::QuadInOut(const float t)
{
    return t < 0.5f ? 2.f * t * t : t * (4.f - 2.f * t) - 1.f;
}

float Easing::CubicIn(const float t)
{
    return t * t * t;
}

float Easing::CubicOut(float t)
{
    t--;
    return 1.f + t * t * t;
}

float Easing::CubicInOut(const float t)
{
    float t2 = t - 1;
    float t3 = t2 - 1;
    return t < 0.5f ? 4.f * t * t * t : 1.f + t2 * (2.f * t3) * (2.f * t3);
}

float Easing::QuartIn(float t)
{
    t *= t;
    return t * t;
}

float Easing::QuartOut(const float t)
{
    float t2 = t - 1;
    t2 *= t2;
    return 1.f - t2 * t2;
}

float Easing::QuartInOut(float t)
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

float Easing::QuintIn(const float t)
{
    float t2 = t * t;
    return t * t2 * t2;
}

float Easing::QuintOut(float t)
{
    t -= 1;
    float t2 = t * t;
    return 1.f + t * t2 * t2;
}

float Easing::QuintInOut(float t)
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

float Easing::ExpoIn(const float t)
{
    return (std::pow(2.f, 8.f * t) - 1.f) / 255.f;
}

float Easing::ExpoOut(const float t)
{
    return 1.f - std::pow(2.f, -8.f * t);
}

float Easing::ExpoInOut(const float t)
{
    if (t < 0.5f)
    {
        return (std::pow(2.f, 16.f * t) - 1.f) / 510.f;
    }
    else
    {
        return 1.f - 0.5f * std::pow(2.f, -16.f * (t - 0.5f));
    }
}

float Easing::CircIn(const float t)
{
    return 1.f - sqrt(1.f - t);
}

float Easing::CircOut(const float t)
{
    return sqrt(t);
}

float Easing::CircInOut(const float t)
{
    if (t < 0.5f)
    {
        return (1.f - sqrt(1.f - 2.f * t)) * 0.5f;
    }
    else
    {
        return (1.f + sqrt(2.f * t - 1.f)) * 0.5f;
    }
}

float Easing::BackIn(const float t)
{
    return t * t * (2.70158f * t - 1.70158f);
}

float Easing::BackOut(float t)
{
    t -= 1;
    return 1.f + t * t * (2.70158f * t + 1.70158f);
}

float Easing::BackInOut(float t)
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

float Easing::ElasticIn(const float t)
{
    float t2 = t * t;
    return t2 * t2 * std::sin(t * Calc::Pi * 4.5f);
}

float Easing::ElasticOut(const float t)
{
    float t2 = (t - 1.f) * (t - 1.f);
    return 1.f - t2 * t2 * std::cos(t * Calc::Pi * 4.5f);
}

float Easing::ElasticInOut(const float t)
{
    float t2;
    if (t < 0.45f)
    {
        t2 = t * t;
        return 8.f * t2 * t2 * std::sin(t * Calc::Pi * 9.f);
    }
    else if (t < 0.55f)
    {
        return 0.5f + 0.75f * std::sin(t * Calc::Pi * 4.f);
    }
    else
    {
        t2 = (t - 1.f) * (t - 1.f);
        return 1.f - 8.f * t2 * t2 * std::sin(t * Calc::Pi * 9.f);
    }
}

float Easing::BounceIn(const float t)
{
    return std::pow(2.f, 6.f * (t - 1.f)) * std::abs(std::sin(t * Calc::Pi * 3.5f));
}

float Easing::BounceOut(const float t)
{
    return 1.f - std::pow(2.f, -6.f * t) * std::abs(std::cos(t * Calc::Pi * 3.5f));
}

float Easing::BounceInOut(const float t)
{
    if (t < 0.5f)
    {
        return 8.f * std::pow(2.f, 8.f * (t - 1.f)) * std::abs(std::sin(t * Calc::Pi * 7.f));
    }
    else
    {
        return 1.f - 8.f * std::pow(2.f, -8.f * t) * std::abs(std::sin(t * Calc::Pi * 7.f));
    }
}
