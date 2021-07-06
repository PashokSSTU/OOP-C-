#pragma once
#include <iostream>
#include <cassert>

template <typename T>
class Stack
{
private:
	T* p_Stack; // ��������� �� ����
	int m_size; // ������ �����
	int m_top; // ������� ������������� �����

public:
	Stack(int = 10);
	Stack(const Stack<T>&);
	~Stack();

	void push(const T); // ���������� �������� � ����
	T pop(); // ��������� ���������� �������� � ����������� ���������
	T top(); // ��������� ���������� �������� ��� ��������
	int count_top() const; // ����� ���������� ����������� ��������� �����
	int size() const; // ����� ������������� ������� �����
	T* getPtr() const; // ��������� ��������� �� ����
	T peek(int); // ����� n-���� �������� �� �������
	bool empty() const; // �������� �� �������
	void print() const; // ����� ����� ����������� � �������

	Stack<T>& operator=(const Stack<T>&); // ���������� ��������� ������������
};

template <typename T>
Stack<T>::Stack(int maxSize) :m_size(maxSize)
{
	p_Stack = new T[m_size];
	m_top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) :m_size(otherStack.size()),
m_top(otherStack.top())
{
	p_Stack = new T[m_size];

	for (int i = 0; i < m_top; i++)
		p_Stack[i] = otherStack.getPtr()[i];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] p_Stack;
	p_Stack = nullptr;
}

template <typename T>
void Stack<T>::push(T value)
{
	assert(m_top < m_size);

	p_Stack[m_top++] = value;
}

template <typename T>
T Stack<T>::pop()
{
	assert(m_top > 0 && m_top <= m_size);

	return p_Stack[--m_top];
}

template <typename T>
T Stack<T>::top()
{
	return p_Stack[m_top - 1];
}

template <typename T>
int Stack<T>::count_top() const
{
	return m_top;
}

template <typename T>
T* Stack<T>::getPtr() const
{
	return p_Stack;
}

template <typename T>
int Stack<T>::size() const
{
	return m_size;
}

template <typename T>
T Stack<T>::peek(int index)
{
	assert(index <= m_top);

	return p_Stack[m_top - index];
}

template <typename T>
bool Stack<T>::empty() const
{
	return m_top == 0;
}

template <typename T>
void Stack<T>::print() const
{
	if (!empty())
	{
		for (int i = m_top - 1; i >= 0; i--)
		{
			std::cout << "|" << p_Stack[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Error! Stack is empty!!!" << std::endl;
	}
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj)
{
	if (this == &obj) // ���������� ����������������
	{
		return *this;
	}
	m_size = obj.m_size;
	m_top = obj.m_top;
	for (int i = 0; i < m_size; i++)
	{
		p_Stack[i] = obj.p_Stack[i];
	}

}
