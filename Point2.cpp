#include "Point2.h"

#include <math.h>

namespace Math {

    template<typename T>
    const Point2<float> Point2<T>::origin(0, 0);

    template<typename T>
    Point2<T> Point2<T>::circumcenter(const Point2<T> p1, const Point2<T> p2, const Point2<T> p3)
    {
        T d = 2 * (
            p1.m_x * (p2.m_y - p3.m_y) +
            p2.m_x * (p3.m_y - p1.m_y) +
            p3.m_x * (p1.m_y - p2.m_y)
        );

        Point2<T> p(
            (
                (SQUARE(p1.m_x) + SQUARE(p1.m_y)) * (p2.m_y - p3.m_y) +
                (SQUARE(p2.m_x) + SQUARE(p2.m_y)) * (p3.m_y - p1.m_y) +
                (SQUARE(p3.m_x) + SQUARE(p3.m_y)) * (p1.m_y - p2.m_y)
                ) / d,
            (
                (SQUARE(p1.m_x) + SQUARE(p1.m_y)) * (p3.m_x - p2.m_x) +
                (SQUARE(p2.m_x) + SQUARE(p2.m_y)) * (p1.m_x - p3.m_x) +
                (SQUARE(p3.m_x) + SQUARE(p3.m_y)) * (p2.m_x - p1.m_x)
                ) / d
        );

        return p;
    }

    template<typename T>
    Point2<T> Point2<T>::isobarycenterTriangle(const Point2<T> p1, const Point2<T> p2, const Point2<T> p3)
    {
        return Point2<T>((p1.m_x + p2.m_x + p3.m_x) / 3,
                         (p1.m_y + p2.m_y + p3.m_y) / 3);
    }

    template<typename T>
    Point2<T>::Point2(const T x, const T y)
        : m_x(x), m_y(y)
    {
    }

    template<typename T>
    Point2<T>::Point2()
        : m_x(0), m_y(0)
    {
    }

    template<typename T>
    Point2<T> Point2<T>::mid(const Point2<T>& p) const
    {
        return Point2<T>(m_x + (p.m_x - m_x) / 2, m_y + (p.m_y - m_y) / 2);
    }

    template<typename T>
    double Point2<T>::dist(const Point2<T>& p) const
    {
        return sqrt(SQUARE(p.m_x - m_x) + SQUARE(p.m_y - m_y));
    }

    template<typename T>
    T Point2<T>::getX() const
    {
        return m_x;
    }

    template<typename T>
    void Point2<T>::setX(const T& x)
    {
        m_x = x;
    }

    template<typename T>
    T Point2<T>::getY() const
    {
        return m_y;
    }

    template<typename T>
    void Point2<T>::setY(const T& y)
    {
        m_y = y;
    }

    template class Point2<double>;
    template class Point2<float>;
    template class Point2<int>;

}
