#include <iostream>
#include "Calculate.h"


//template <typename T1, typename T2>
//void Calculate <T1, T2>::setValues(T1 x, T2 y)
//{
//	m_a = x;
//	m_b = y;
//}

//template <typename T1, typename T2>
//void Calculate <T1, T2>::printValues()
//{
//	std::cout << "m_a = " << m_a << std::endl;
//	std::cout << "m_b = " << m_b << std::endl;
//}

//template <typename T1, typename T2>
//bool Calculate <T1, T2>::operator!() const
//{
//	return(m_a == 0 && m_b == 0);
//}

//template <typename T1, typename T2>
//Calculate <T1, T2> Calculate <T1, T2>::operator-() const
//{
//	Calculate obj(-m_a,-m_b);
//	return obj;
//}

//template <typename T1, typename T2>
//Calculate <T1, T2>& Calculate <T1, T2>::operator++()
//{
//	if (m_a == 2147483647)
//	{
//		m_a = -2147483648;
//	}
//	else
//	{
//		++m_a;
//	}
//
//	if (m_b == 2147483647)
//	{
//		m_b = -2147483648;
//	}
//	else
//	{
//		++m_b;
//	}
//
//	return *this;
//}

//template <typename T1, typename T2>
//Calculate <T1, T2>& Calculate <T1, T2>::operator--()
//{
//	if (m_a == -2147483648)
//	{
//		m_a = 2147483647;
//	}
//	else
//	{
//		--m_a;
//	}
//
//	if (m_b == -2147483648)
//	{
//		m_b = 2147483647;
//	}
//	else
//	{
//		--m_b;
//	}
//
//	return *this;
//}

template <typename T1, typename T2>
Calculate <T1, T2> Calculate <T1, T2>::operator++(int)
{
	Calculate temp(m_a, m_b);

	++(*this);

	return temp;
}

template <typename T1, typename T2>
Calculate <T1, T2> Calculate <T1, T2>::operator--(int)
{
	Calculate temp(m_a, m_b);

	--(*this);

	return temp;
}

template <typename T1, typename T2>
Calculate <T1, T2>& Calculate <T1, T2>::operator+=(const int num)
{
	this->m_a += num;
	this->m_b += num;
	return *this;
}

template <typename T1, typename T2>
Calculate <T1, T2>& Calculate <T1, T2>::operator+=(const Calculate &obj)
{
	this->m_a += obj.m_a;
	this->m_b += obj.m_b;
	return *this;
}

template <typename T1, typename T2>
Calculate <T1, T2>& Calculate <T1, T2>::operator-=(const int num)
{
	this->m_a -= num;
	this->m_b -= num;
	return *this;
}

template <typename T1, typename T2>
Calculate <T1, T2>& Calculate <T1, T2>::operator-=(const Calculate& obj)
{
	this->m_a -= obj.m_a;
	this->m_b -= obj.m_b;
	return *this;
}

template <typename T1, typename T2>
Calculate <T1, T2> operator+(const Calculate <T1, T2>& obj1, const Calculate <T1, T2>& obj2)
{
	Calculate <T1, T2> obj(obj1.getA() + obj2.getA(), obj1.getB() + obj2.getB());
	return obj;
}

template <typename T1, typename T2>
Calculate <T1, T2> operator+(const Calculate <T1, T2>& obj, const int num)
{
	Calculate <T1, T2> temp(obj.getA() + num, obj.getB() + num);

	return temp;
}

template <typename T1, typename T2>
Calculate <T1, T2> operator+(const int num, const Calculate <T1, T2>& obj)
{
	Calculate <T1, T2> temp(num + obj.getA(), num + obj.getB());

	return temp;
}

template <typename T1, typename T2>
Calculate <T1, T2> operator-(const Calculate <T1, T2>& obj1, const Calculate <T1, T2>& obj2)
{
	Calculate <T1, T2> obj(obj1.getA() - obj2.getA(), obj1.getB() - obj2.getB());
	return obj;
}

template <typename T1, typename T2>
Calculate <T1, T2> operator-(const Calculate <T1, T2>& obj, const int num)
{
	Calculate <T1, T2> temp(obj.getA() - num, obj.getB() - num);

	return temp;
}

template <typename T1, typename T2>
Calculate <T1, T2> operator-(const int num, const Calculate <T1, T2>& obj)
{
	Calculate <T1, T2> temp(num - obj.getA(), num - obj.getB());

	return temp;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, Calculate <T1, T2>& obj)
{
	out << "m_a = " << obj.m_a << std::endl << "m_b = " << obj.m_b << std::endl;
	return out;
}

