#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr){}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    ~Queue();

    void enqueue(T value);
    T dequeue();
    T getFront() const;
    int getSize() const;
};

template <typename T>
Queue<T>::~Queue()
{
    while (front)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::enqueue(T element)
{
    if (rear == nullptr)
    {
        rear = new Node(element);
        front = rear;
    }
    else
    {
        rear->next = new Node(element);
        rear = rear->next;
    }

    size++;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (front == nullptr)
    {
        throw std::underflow_error("Queue is empty");
    }
    
    T element  = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    size--;

    if (size == 0)
    {
        rear = nullptr;
    }

    return element;
}

template <typename T>
T Queue<T>::getFront() const
{
    if (front == nullptr)
    {
        throw std::underflow_error("Queue is empty");
    }
    
    return front->data;
}

template <typename T>
int Queue<T>::getSize() const
{
    return size;
}