#include <iostream>
#include "Calculate.h"

void Calculate::setValues(int x, int y)
{
	m_a = x;
	m_b = y;
}

void Calculate::printValues()
{
	std::cout << "m_a = " << m_a << std::endl;
	std::cout << "m_b = " << m_b << std::endl;
}

bool Calculate::operator!() const
{
	return(m_a == 0 && m_b == 0);
}

Calculate Calculate::operator-() const
{
	Calculate obj(-m_a,-m_b);
	return obj;
}

Calculate& Calculate::operator++()
{
	if (m_a == 2147483647)
	{
		m_a = -2147483648;
	}
	else
	{
		++m_a;
	}

	if (m_b == 2147483647)
	{
		m_b = -2147483648;
	}
	else
	{
		++m_b;
	}

	return *this;
}

Calculate& Calculate::operator--()
{
	if (m_a == -2147483648)
	{
		m_a = 2147483647;
	}
	else
	{
		--m_a;
	}

	if (m_b == -2147483648)
	{
		m_b = 2147483647;
	}
	else
	{
		--m_b;
	}

	return *this;
}

Calculate Calculate::operator++(int)
{
	Calculate temp(m_a, m_b);

	++(*this);

	return temp;
}

Calculate Calculate::operator--(int)
{
	Calculate temp(m_a, m_b);

	--(*this);

	return temp;
}

Calculate operator+(const Calculate& obj1, const Calculate& obj2)
{
	Calculate obj(obj1.getA() + obj2.getA(), obj1.getB() + obj2.getB());
	return obj;
}

Calculate operator-(const Calculate& obj1, const Calculate& obj2)
{
	Calculate obj(obj1.getA() - obj2.getA(), obj1.getB() - obj2.getB());
	return obj;
}


