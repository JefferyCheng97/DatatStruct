#include "linked_list.h"

// 查找值为 value 的元素，返回其节点指针
ListNode* LinkedList::find(eleType value) 
{
	ListNode* curr = head;

	while (curr && curr->data != value) 
	{
		curr = curr->next;
	}

	return curr;
}


// 获取位置 i 的节点指针
ListNode* LinkedList::get(int i)
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid position");
	}

	ListNode* curr = head;

	for (int j = 0; j < i; j++) 
	{
		curr = curr->next;
	}

	return curr;
}