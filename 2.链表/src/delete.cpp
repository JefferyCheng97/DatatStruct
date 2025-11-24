#include "linked_list.h"

// 删除位置 i 的元素
void LinkedList::remove(int i) 
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid position");
	}

	if (i == 0)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
	else 
	{
		ListNode* curr = head;

		for (int j = 0; j < i - 1; j++)
		{
			curr = curr->next;
		}

		ListNode* temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}

	--size;
}

LinkedList::~LinkedList()
{
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}