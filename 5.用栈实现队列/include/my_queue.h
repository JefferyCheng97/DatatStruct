#pragma once
#include "stack.h"

class MyQueue
{
private:
    Stack<int> s1;
    Stack<int> s2;

public:
    MyQueue(){}

    void push(int x)
    {
        s1.push(x);
    }

    // 弹出栈顶元素
    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.pop());
            }
        }

        return s2.pop();
    }
    
    // 获取栈顶元素
    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.pop());
            }
        }

        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};
