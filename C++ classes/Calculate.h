#pragma once
class Calculate
{
	int m_a;
	int m_b;
public:
	Calculate(int x = 0, int y = 0):m_a(x),m_b(y)
	{
	}

	~Calculate()
	{
	}

	void setValues(int x, int y);
	int getA() { return m_a; }
	int getB() { return m_b; }
	void printValues();

	Calculate operator+(const Calculate& obj1, const Calculate& obj2);
};

