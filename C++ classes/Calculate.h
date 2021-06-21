#pragma once
template <class T1, class T2> 
class Calculate
{
	T1 m_a;
	T2 m_b;
public:
	Calculate(T1 x, T2 y):m_a(x),m_b(y)
	{
	}

	~Calculate()
	{
	}

	void setValues(T1 x, T2 y)
	{
		this->m_a = x;
		this->m_b = y;
	}

	T1 getA() const { return m_a; }
	T2 getB() const { return m_b; }

	// ���������� �����
	void printValues()
	{
		std::cout << "m_a = " << m_a << std::endl;
		std::cout << "m_b = " << m_b << std::endl;
	}

	// 0 - ���� ��������������� �� ���������, 1 - ������ ������ ����
	bool operator!() const
	{
		return(m_a == 0 && m_b == 0);
	}

	Calculate operator-() const // ������� �����
	{
		Calculate obj(-m_a, -m_b);
		return obj;
	}

	Calculate& operator++() // ������������ �����
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

	Calculate& operator--() // ������������ �����
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

	Calculate operator++(int); // ������������� �����
	Calculate operator--(int); // ������������� �����

	Calculate& operator+=(const int num);
	Calculate& operator+=(const Calculate &obj);
	Calculate& operator-=(const int num);
	Calculate& operator-=(const Calculate& obj);

	friend std::ostream& operator<<(std::ostream& out, Calculate& obj);
};

//template <typename T1, typename T2>// �������� ����
//Calculate<T1, T2> operator+(const Calculate<T1, T2>& obj1, const Calculate<T1, T2>& obj2); 
//
//template <typename T1, typename T2>
//Calculate<T1, T2> operator+(const Calculate<T1, T2>& obj1, const int num); // �������� ����
//
//template <typename T1, typename T2>
//Calculate<T1, T2> operator+(const int num, const Calculate<T1, T2>& obj); // �������� ����
//
//template <typename T1, typename T2>// �������� �����
//Calculate<T1, T2> operator-(const Calculate<T1, T2>& obj1, const Calculate<T1, T2>& obj2); 
//
//template <typename T1, typename T2>
//Calculate<T1, T2> operator-(const Calculate<T1, T2>& obj, const int num); // �������� �����
//
//template <typename T1, typename T2>
//Calculate<T1, T2> operator-(const int num, const Calculate<T1, T2>& obj); // �������� �����
//
//
//template <typename T1, typename T2>
//std::ostream& operator<<(std::ostream &out, Calculate<T1, T2>&obj);