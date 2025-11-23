#include "sequential_list.h"

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
int getSize(SequentialList* list) 
{
	return list->size;
}

// 判断顺序表是否为空
bool isEmpty(SequentialList* list) 
{
	return list->size == 0;
}


