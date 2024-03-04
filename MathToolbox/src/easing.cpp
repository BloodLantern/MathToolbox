#include "easing.hpp"

#include <cmath>

float_t Easing::SineIn(const float_t t)
{
    return std::sin(Calc::PiOver2 * t);
}

float_t Easing::SineOut(const float_t t)
{
    return 1.f + std::sin(Calc::PiOver2 * (t - 1));
}

float_t Easing::SineInOut(const float_t t)
{
    return 0.5f * (1.f + std::sin(Calc::Pi * (t - 0.5f)));
}

float_t Easing::ExpoIn(const float_t t)
{
    return (std::pow(2.f, 8.f * t) - 1.f) / 255.f;
}

float_t Easing::ExpoOut(const float_t t)
{
    return 1.f - std::pow(2.f, -8.f * t);
}

float_t Easing::ExpoInOut(const float_t t)
{
    if (t < 0.5f)
        return (std::pow(2.f, 16.f * t) - 1.f) / 510.f;
    
    return 1.f - 0.5f * std::pow(2.f, -16.f * (t - 0.5f));
}

float_t Easing::CircIn(const float_t t)
{
    return 1.f - std::sqrt(1.f - t);
}

float_t Easing::CircOut(const float_t t)
{
    return std::sqrt(t);
}

float_t Easing::CircInOut(const float_t t)
{
    if (t < 0.5f)
        return (1.f - std::sqrt(1.f - 2.f * t)) * 0.5f;
    
    return (1.f + std::sqrt(2.f * t - 1.f)) * 0.5f;
}

float_t Easing::ElasticIn(const float_t t)
{
    const float_t t2 = t * t;
    return t2 * t2 * std::sin(t * Calc::Pi * 4.5f);
}

float_t Easing::ElasticOut(const float_t t)
{
    const float_t t2 = (t - 1.f) * (t - 1.f);
    return 1.f - t2 * t2 * std::cos(t * Calc::Pi * 4.5f);
}

float_t Easing::ElasticInOut(const float_t t)
{
    float_t t2;
    if (t < 0.45f)
    {
        t2 = t * t;
        return 8.f * t2 * t2 * std::sin(t * Calc::Pi * 9.f);
    }
    
    if (t < 0.55f)
        return 0.5f + 0.75f * std::sin(t * Calc::Pi * 4.f);
    
    t2 = (t - 1.f) * (t - 1.f);
    return 1.f - 8.f * t2 * t2 * std::sin(t * Calc::Pi * 9.f);
}

float_t Easing::BounceIn(const float_t t)
{
    return std::pow(2.f, 6.f * (t - 1.f)) * std::abs(std::sin(t * Calc::Pi * 3.5f));
}

float_t Easing::BounceOut(const float_t t)
{
    return 1.f - std::pow(2.f, -6.f * t) * std::abs(std::cos(t * Calc::Pi * 3.5f));
}

float_t Easing::BounceInOut(const float_t t)
{
    if (t < 0.5f)
        return 8.f * std::pow(2.f, 8.f * (t - 1.f)) * std::abs(std::sin(t * Calc::Pi * 7.f));
    
    return 1.f - 8.f * std::pow(2.f, -8.f * t) * std::abs(std::sin(t * Calc::Pi * 7.f));
}
