#include "my_stack.h"

int main()
{
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl; // Should print 30
    std::cout << "Popped element: " << stack.pop() << std::endl; // Should print 30
    std::cout << "Top element after pop: " << stack.top() << std::endl; // Should print 20

    return 0;
}