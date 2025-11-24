#include "linked_list.h"

// 在位置 i 插入值为 value 的元素
void LinkedList::insert(int i, eleType value) 
{
	if (i < 0 || i > size)
	{
		throw std::out_of_range("Invalid position");
	}

	ListNode* newNode = new ListNode(value);

	if (i == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		ListNode* curr = head;

		for (int j = 0; j < i - 1; j++)
		{
			curr = curr->next;
		}

		newNode->next = curr->next;
		curr->next = newNode;
	}

	++size;
}
