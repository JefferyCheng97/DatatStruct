#pragma once

#include "queue.h"

class MyStack
{
private:
    Queue<int> q1;
    Queue<int> q2;

public:
    MyStack(){}

    void push(int x)
    {
        q1.enqueue(x);
    }

    int pop()
    {
        while (q1.getSize() > 1)
        {
            q2.enqueue(q1.dequeue());
        }

        int topElement = q1.dequeue();
        
        while (!q2.empty())
        {
            q1.enqueue(q2.dequeue());
        }
        
        return topElement;
    }

    int top()
    {
        while (q1.getSize() > 1)
        {
            q2.enqueue(q1.dequeue());
        }

        int topElement = q1.dequeue();
        q2.enqueue(topElement);
        
        while (!q2.empty())
        {
            q1.enqueue(q2.dequeue());
        }
        
        return topElement;
    }

    bool empty()
    {
        return q1.getSize() == 0;
    }
};
