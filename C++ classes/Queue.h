#pragma once
#include <iostream>

template <typename T>
class Queue
{
private:
	int m_size; // Размер очереди
	T* p_queue; // Указатель на очередь
	int m_begin, m_end; // Начало и конец данных очереди
	int m_count; // Количество элементов очереди

	T* getP_Queue() const; // Вывод указателя на очередь
	int getBegin_ind() const; // Вывод индекса начала
	int getEnd_ind() const; // Вывод индекса конца

public:
	Queue(int = 10);
	Queue(const Queue&);
	~Queue();

	void push(const T); // Добавление элемента
	void pop(); // Удаление элемента
	void print() const; // Вывод элементов очереди
	int size() const; // Максимальный размер очереди
	T front() const; // Обращение к первому элементу
	T back() const; // Получение последнего элемента очереди
	int elemcount() const; // Количество элементов в очереди
	bool empty() const; // Проверка на пустоту

	Queue<T>& operator=(const Queue<T>&);// Перегрузка оператора присваивания
};

template <typename T>
Queue<T>::Queue(int size) :m_size(size), m_begin(0), m_end(0), m_count(0)
{
	p_queue = new int[m_size];
}


template <typename T>
Queue<T>::Queue(const Queue<T>& obj) : m_size(obj.size()),
	m_begin(obj.getBegin_ind()), m_end(obj.getEnd_ind()), m_count(obj.elemcount())
{
	p_queue = new T[m_size];
	if (obj.empty())
		return;

	if (m_begin >= m_end)
		for (int i = m_begin; i < m_size; i++)
			p_queue[i] = obj.getP_Queue()[i];
	else
		for (int i = m_begin; i < m_end; i++)
			p_queue[i] = obj.getP_Queue()[i];

}

template <typename T>
Queue<T>::~Queue()
{
	delete[] p_queue;
	p_queue = nullptr;
}

template <typename T>
T* Queue<T>::getP_Queue() const
{
	return p_queue;
}

template <typename T>
int Queue<T>::getBegin_ind() const
{
	return m_begin;
}

template <typename T>
int Queue<T>::getEnd_ind() const
{
	return m_end;
}

template <typename T>
void Queue<T>::push(T value)
{
	if (m_count == m_size)
	{
		std::cout << "The queue is full!" << std::endl;
		return;
	}

	p_queue[m_end++] = value;

	if (m_end >= m_size)
	{
		m_end -= m_size;
	}

	m_count++;
}

template <typename T>
void Queue<T>::pop()
{
	if (empty())
	{
		std::cout << "The queue is empty!" << std::endl;
		return;
	}

	++m_begin;

	if (m_begin >= m_size)
	{
		m_begin -= m_size;
	}

	m_count--;
}

template <typename T>
void Queue<T>::print() const
{
	if (empty())
	{
		std::cout << "The queue is empty!" << std::endl;
		return;
	}

	if (m_begin >= m_end)
	{
		for (int i = m_begin; i < m_size; i++)
		{
			std::cout << p_queue[i] << " ";
		}
		for (int i = 0; i < m_end; i++)
		{
			std::cout << p_queue[i] << " ";
		}
	}
	else
	{
		for (int i = m_begin; i < m_end; i++)
		{
			std::cout << p_queue[i] << " ";
		}
	}

	std::cout << std::endl;
}

template <typename T>
int Queue<T>::size() const
{
	return m_size;
}

template <typename T>
T Queue<T>::front() const
{
	return p_queue[m_begin];
}

template <typename T>
T Queue<T>::back() const
{
	return p_queue[m_end];
}

template <typename T>
int Queue<T>::elemcount() const
{
	return m_count;
}

template <typename T>
bool Queue<T>::empty() const
{
	return m_count == 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& obj)
{
	if (this == &obj) // Исключение самоприсваивания
	{
		return *this;
	}
	m_size = obj.m_size;
	m_count = obj.m_count;
	m_begin = obj.m_begin;
	m_end = obj.m_end;
	for (int i = 0; i < m_size; i++)
	{
		p_queue[i] = obj.p_queue[i];
	}
}



