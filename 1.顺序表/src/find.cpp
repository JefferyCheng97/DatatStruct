#include "sequential_list.h"

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