#include "sequential_list.h"

// 在指定位置插入元素
void insertElement(SequentialList* list, int index, eleType element) 
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