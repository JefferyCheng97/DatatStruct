#include <iostream>

using namespace std;

#define eleType int // 方便定义顺序表中元素的类型


// 顺序表结构体定义
struct SequentialList
{
	eleType* elements;
	int size; 
	int capacity;
};


// 初始化顺序表
void initializeList(SequentialList* list, int capacity) 
{
	list->elements = new eleType[capacity];
	list->size = 0;
	list->capacity = capacity;
}


// 销毁顺序表
void destroyList(SequentialList* list) 
{
	delete [] list->elements;
}


// 获取顺序表的大小
int size(SequentialList* list) 
{
	return list->size;
}


// 判断顺序表是否为空
bool isEmpty(SequentialList* list) 
{
	return list->size == 0;
}


// 在指定位置插入元素
void insert(SequentialList* list, int index, eleType element) 
{
	if (index < 0 || index > list->size)
	{
		throw std::invalid_argument("Invalid index");
	}

	if (list->size == list->capacity) 
	{
		int newCapacity = list->capacity * 2;
		eleType* newElements = new eleType[newCapacity];

		for (int i = 0; i < list->size; i++)
		{
			newElements[i] = list->elements[i];
		}

		delete[] list->elements;
		list->elements = newElements;
		list->capacity = newCapacity;
	}

	for (int i = list->size; i > index; i--)
	{
		list->elements[i] = list->elements[i - 1];
	}

	list->elements[index] = element;
	(list->size)++;
}


// 删除指定位置的元素
void deleteElement(SequentialList* list, int index) 
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");
	}

	for (int i = index; i < list->size - 1; i++)
	{
		list->elements[i] = list->elements[i + 1];
	}

	list->size--;
}


// 查找元素的位置, 返回第一个匹配元素的索引
int findElement(SequentialList* list, eleType element) 
{
	for (int i = 0; i < list->size; i++)
	{
		if (list->elements[i] == element) 
		{
			return i;
		}
	}

	return -1;
}


// 获取指定位置的元素
eleType getElement(SequentialList* list, int index) 
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");
	}

	return list->elements[index];
}


// 更新指定位置的元素
void updateElement(SequentialList* list, int index, eleType value) 
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");
	}

	list->elements[index] = value;
}


int main() 
{
	SequentialList myList;
	initializeList(&myList, 10);

	for (int i = 0; i < 10; i++)
	{
		insert(&myList, i, i * 10);
	}

	cout << "Size: " << size(&myList) << endl;
	cout << "Is empty: " << isEmpty(&myList) << endl;

	return 0;
}