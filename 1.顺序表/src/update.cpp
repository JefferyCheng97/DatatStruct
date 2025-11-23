#include "sequential_list.h"

// 更新指定位置的元素
void updateElement(SequentialList* list, int index, eleType value) 
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");
	}

	list->elements[index] = value;
}