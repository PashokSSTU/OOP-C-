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


