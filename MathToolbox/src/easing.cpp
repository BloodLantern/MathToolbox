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
    return 1.f - std::sqrt(1.f - t);
}

float Easing::CircOut(const float t)
{
    return std::sqrt(t);
}

float Easing::CircInOut(const float t)
{
    if (t < 0.5f)
    {
        return (1.f - std::sqrt(1.f - 2.f * t)) * 0.5f;
    }
    else
    {
        return (1.f + std::sqrt(2.f * t - 1.f)) * 0.5f;
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
