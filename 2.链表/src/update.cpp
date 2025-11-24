#include "linked_list.h"

// 更新位置 i 的元素值为 value
void LinkedList::update(int i, eleType value)
{
    get(i)->data = value;
}
