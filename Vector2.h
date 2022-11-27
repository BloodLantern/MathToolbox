#pragma once
#include <iostream>

#include "Point2.h"

namespace Math {

	template<typename T = float>
	class Vector2
	{
	private:
		T m_x, m_y;

	public:
		

		Vector2(const Point2<T>& p);
		Vector2(const Point2<T>& p1, const Point2<T>& p2);
		Vector2(const T x = 0, const T y = 0);
		Vector2();

		double getNorm() const;
		double dotProduct(const Vector2<T>& v);
		double determinant(const Vector2<T>& v);
		double angle(const Vector2<T>& v);

		inline T getX() const;
		inline void setX(const T& x);
		inline T getY() const;
		inline void setY(const T& y);
	};

	template<typename T>
	Point2<T> operator+(Point2<T> p, Vector2<T> v)
	{
		return Point2<T>(p.getX() + v.getX(), p.getY() + v.getY());
	}

	template<typename T>
	Vector2<T> operator+(Vector2<T> v1, Vector2<T> v2)
	{
		return Vector2<T>(v1.getX() + v2.getX(), v1.getY() + v2.getY());
	}

	template<typename T>
	Vector2<T> operator-(Vector2<T> v1, Vector2<T> v2)
	{
		return Vector2<T>(v1.getX() - v2.getX(), v1.getY() - v2.getY());
	}

	template<typename T>
	Vector2<T> operator-(Vector2<T> v)
	{
		return Vector2<T>(-v.getX(), -v.getY());
	}

	template<typename T>
	Vector2<T> operator*(Vector2<T> v1, Vector2<T> v2)
	{
		return Vector2<T>(v1.getX() * v2.getX(), v1.getY() * v2.getY());
	}

	template<typename T>
	Vector2<T> operator*(Vector2<T> v1, T x)
	{
		return Vector2<T>(v1.getX() * x, v1.getY() * x);
	}

	template<typename T>
	Vector2<T> operator/(Vector2<T> v1, Vector2<T> v2)
	{
		return Vector2<T>(v1.getX() / v2.getX(), v1.getY() / v2.getY());
	}

	template<typename T>
	Vector2<T> operator/(Vector2<T> v1, T x)
	{
		return Vector2<T>(v1.getX() / x, v1.getY() / x);
	}

	template<typename T>
	bool operator<(Vector2<T> v1, Vector2<T> v2)
	{
		return v1.getNorm() < v2.getNorm();
	}

	template<typename T>
	bool operator<(Vector2<T> v1, T x)
	{
		return v1.getNorm() < x;
	}

	template<typename T>
	bool operator>(Vector2<T> v1, Vector2<T> v2)
	{
		return v1.getNorm() > v2.getNorm();
	}

	template<typename T>
	bool operator>(Vector2<T> v1, T x)
	{
		return v1.getNorm() > x;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, Vector2<T>& v)
	{
		return out << "[" << v.getX() << " ; " << v.getY() << "]";
	}

}
