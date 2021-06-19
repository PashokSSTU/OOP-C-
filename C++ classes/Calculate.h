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

	void printValues(); // ���������� �����

	bool operator!() const; // 0 - ���� ��������������� �� ���������, 1 - ������ ������ ����
	Calculate operator-() const; // ������� �����

};

Calculate operator+(const Calculate& obj1, const Calculate& obj2); // �������� ����
Calculate operator-(const Calculate& obj1, const Calculate& obj2); // �������� �����
