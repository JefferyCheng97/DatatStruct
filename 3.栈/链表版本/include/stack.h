#pragma once
#include <iostream>

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node *head;
    int size;

public:
    Stack() : head(nullptr), size(0) {}
    ~Stack();

    void push(T element);
    T pop();
    T top() const;
    int getSize() const;
};

// 析构函数
template <typename T>
Stack<T>::~Stack()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// 入栈操作, 头插法
template <typename T>
void Stack<T>::push(T element)
{
    Node *newNode = new Node(element);
    newNode->next = head;
    head = newNode;
    ++size;
}

// 出栈操作
template <typename T>
T Stack<T>::pop()
{
    if (head == nullptr)
    {
        throw std::underflow_error("Stack is empty");
    }

    T result = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    --size;

    return result;
}

// 获取栈顶元素
template <typename T>
T Stack<T>::top() const
{
    if (head == nullptr)
    {
        throw std::underflow_error("Stack is empty");
    }

    return head->data;
}

// 获取栈的大小
template <typename T>
int Stack<T>::getSize() const
{
    return size;
}