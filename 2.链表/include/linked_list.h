#pragma once
#include <iostream>

// 定义元素类型
using eleType = int;

// 定义链接结构体节点, 头插法
struct ListNode
{
    eleType data;
    ListNode *next;
    ListNode(eleType x) : data(x), next(NULL) {}
};

// 定义链表类
class LinkedList
{
private:
    ListNode *head;
    int size;

public:
    LinkedList() : head(NULL), size(0) {}
    ~LinkedList();

    void insert(int i, eleType value);
    void remove(int i);
    ListNode *find(eleType value);
    ListNode *get(int i);
    void update(int i, eleType value);
    void print();
};