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

	int getA() const { return m_a; }
	int getB() const { return m_b; }

	void printValues(); // распечатка полей

	bool operator!() const; // 0 - если инициализирован по умолчанию, 1 - заданы другие поля
	Calculate operator-() const; // унарный минус

};

Calculate operator+(const Calculate& obj1, const Calculate& obj2); // бинарный плюс
Calculate operator-(const Calculate& obj1, const Calculate& obj2); // бинарный минус
