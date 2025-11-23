#include "sequential_list.h"

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