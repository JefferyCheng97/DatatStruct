#include "stack.h"

using namespace std;

int main()
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl; // 输出 30
    cout << "Stack size: " << stack.getSize() << endl; // 输出 3

    cout << "Popped element: " << stack.pop() << endl; // 输出 30
    cout << "New top element: " << stack.top() << endl; // 输出 20
    cout << "New stack size: " << stack.getSize() << endl; // 输出 2

    return 0;
}