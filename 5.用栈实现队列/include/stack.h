#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>

template <typename T>
class Stack
{
private:
	T *data; // T类型的数组
	int size;
	int capacity;
	void resize();

public:
	Stack() : data(new T[10]), size(0), capacity(10) {}
	~Stack();

	void push(T element);
	T pop();
	T top() const;
	int getSize() const;
    bool empty() const;
};

// 动态扩容函数
template <typename T>
void Stack<T>::resize()
{
	int newCapacity = capacity * 2;
	T *newData = new T[newCapacity];

	for (int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCapacity;
}

// 析构函数
template <typename T>
Stack<T>::~Stack()
{
	delete[] data;
}

// 入栈操作
template <typename T>
void Stack<T>::push(T element)
{
	if (size == capacity)
	{
		resize();
	}
	data[size++] = element;
}

// 出栈操作
template <typename T>
T Stack<T>::pop()
{
	if (size == 0)
	{
		throw std::underflow_error("Stack is empty");
	}

	return data[--size];
}

// 获取栈顶元素
template <typename T>
T Stack<T>::top() const
{
	if (size == 0)
	{
		throw std::underflow_error("Stack is empty");
	}

	return data[size - 1];
}

// 获取栈的大小
template <typename T>
int Stack<T>::getSize() const
{
	return size;
}

template <typename T>
bool Stack<T>::empty() const
{
    return size == 0;
}