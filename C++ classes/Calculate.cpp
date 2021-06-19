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

Calculate Calculate::operator+(const Calculate& obj1, const Calculate& obj2)
{
	Calculate obj;
}