#pragma once
#include <iostream>

namespace Math {

#define SQUARE(n) ((n) * (n))

	template<typename T = float>
	class Point2
	{
	private:
		T m_x, m_y;

	public:
		static const Point2<float> origin;

		static Point2<T> circumcenter(const Point2<T> p1, const Point2<T> p2, const Point2<T> p3);
		static Point2<T> isobarycenterTriangle(const Point2<T> p1, const Point2<T> p2, const Point2<T> p3);

		Point2(const T x = 0, const T y = 0);
		Point2();

		Point2<T> mid(const Point2& p) const;
		double dist(const Point2& p) const;

		inline T getX() const;
		inline void setX(const T& x);
		inline T getY() const;
		inline void setY(const T& y);
	};

	template<typename T>
	Point2<T> operator-(Point2<T>& p)
	{
		return Point2<T>(-p.getX(), -p.getY());
	}

	template<typename T>
	const bool operator==(const Point2<T>& p1, const Point2<T>& p2)
	{
		return p1.getX() == p2.getX() && p1.getY() == p2.getY();
	}

	template<typename T>
	const bool operator!=(const Point2<T>& p1, const Point2<T>& p2)
	{
		return !(p1 == p2);
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Point2<T>& p)
	{
		return out << "[" << p.getX() << " ; " << p.getY() << "]";
	}

}
