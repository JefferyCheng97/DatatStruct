#include "linked_list.h"

// 打印链表元素
void LinkedList::print()
{
    ListNode *curr = head;

    while (curr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
}