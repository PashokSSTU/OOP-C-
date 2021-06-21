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

	// распечатка полей
	void printValues()
	{
		std::cout << "m_a = " << m_a << std::endl;
		std::cout << "m_b = " << m_b << std::endl;
	}

	// 0 - если инициализирован по умолчанию, 1 - заданы другие поля
	bool operator!() const
	{
		return(m_a == 0 && m_b == 0);
	}

	Calculate operator-() const // унарный минус
	{
		Calculate obj(-m_a, -m_b);
		return obj;
	}

	Calculate& operator++() // преинкремент полей
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

	Calculate& operator--() // предекремент полей
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

	Calculate operator++(int); // постинкремент полей
	Calculate operator--(int); // постдекремент полей

	Calculate& operator+=(const int num);
	Calculate& operator+=(const Calculate &obj);
	Calculate& operator-=(const int num);
	Calculate& operator-=(const Calculate& obj);

	friend std::ostream& operator<<(std::ostream& out, Calculate& obj);
};

//template <typename T1, typename T2>// бинарный плюс
//Calculate<T1, T2> operator+(const Calculate<T1, T2>& obj1, const Calculate<T1, T2>& obj2); 
//
//template <typename T1, typename T2>
//Calculate<T1, T2> operator+(const Calculate<T1, T2>& obj1, const int num); // бинарный плюс
//
//template <typename T1, typename T2>
//Calculate<T1, T2> operator+(const int num, const Calculate<T1, T2>& obj); // бинарный плюс
//
//template <typename T1, typename T2>// бинарный минус
//Calculate<T1, T2> operator-(const Calculate<T1, T2>& obj1, const Calculate<T1, T2>& obj2); 
//
//template <typename T1, typename T2>
//Calculate<T1, T2> operator-(const Calculate<T1, T2>& obj, const int num); // бинарный минус
//
//template <typename T1, typename T2>
//Calculate<T1, T2> operator-(const int num, const Calculate<T1, T2>& obj); // бинарный минус
//
//
//template <typename T1, typename T2>
//std::ostream& operator<<(std::ostream &out, Calculate<T1, T2>&obj);