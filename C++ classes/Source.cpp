#include <iostream>

class obj
{
	int m_var;
public:
	obj(int variable = 0):m_var(variable)
	{
	}

	void setValue(int variable)
	{
		m_var = variable;
	}

	const int getValue()
	{
		return m_var;
	}

	void printVariable()
	{
		std::cout << "m_var = " << m_var << std::endl;
	}

	~obj()
	{
	}

	friend obj operator+(const obj& obj1, const obj& obj2);

};

obj operator+(const obj& obj1, const obj& obj2)
{
	return obj(obj1.m_var + obj2.m_var);
}

int main()
{

	obj obj1(1);
	obj obj2(9);

	obj obj3;

	obj3 = obj1 + obj2;

	obj3.printVariable();

	return 0;
}