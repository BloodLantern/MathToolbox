#include "Vector2.h"

namespace Math {

	template<typename T>
	Vector2<T>::Vector2(const Point2<T>& p)
		: m_x(p.getX()), m_y(p.getY())
	{
	}

	template<typename T>
	Vector2<T>::Vector2(const Point2<T>& p1, const Point2<T>& p2)
		: m_x(p2.getX() - p1.getX()), m_y(p2.getY() - p1.getY())
	{
	}

	template<typename T>
	Vector2<T>::Vector2(const T x, const T y)
		: m_x(x), m_y(y)
	{
	}

	template<typename T>
	Vector2<T>::Vector2()
		: m_x(0), m_y(0)
	{
	}

	template<typename T>
	double Vector2<T>::getNorm() const
	{
		return sqrt(SQUARE(m_x) + SQUARE(m_y));
	}

	template<typename T>
	double Vector2<T>::dotProduct(const Vector2<T>& v)
	{
		return m_x * v.m_x + m_y * v.m_y;
	}

	template<typename T>
	double Vector2<T>::determinant(const Vector2<T>& v)
	{
		return m_x * v.m_y - v.m_x * m_y;
	}

	template<typename T>
	double Vector2<T>::angle(const Vector2<T>& v)
	{
		double dotProd = dotProduct(v);

		double normV1 = getNorm();
		double normV2 = v.getNorm();

		if (determinant(v) < 0)
			return -acos(dotProd / (normV1 * normV2));
		return acos(dotProd / (normV1 * normV2));
	}

	template<typename T>
	T Vector2<T>::getX() const
	{
		return m_x;
	}

	template<typename T>
	void Vector2<T>::setX(const T& x)
	{
		m_x = x;
	}

	template<typename T>
	T Vector2<T>::getY() const
	{
		return m_y;
	}

	template<typename T>
	void Vector2<T>::setY(const T& y)
	{
		m_y = y;
	}

	template class Vector2<double>;
	template class Vector2<float>;
	template class Vector2<int>;

}
