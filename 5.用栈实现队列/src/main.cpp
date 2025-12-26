#include "my_queue.h"

int main()
{
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    int first = queue.pop(); // 返回 1
    int second = queue.peek(); // 返回 2
    bool isEmpty = queue.empty(); // 返回 false

    return 0;
}