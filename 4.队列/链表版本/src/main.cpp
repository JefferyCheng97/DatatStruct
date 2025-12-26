#include "queue.h"

using namespace std;

int main()
{
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(4);
    cout << "Front element: " << q.getFront() << endl;

    q.enqueue(5);
    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    cout << "Front element: " << q.getFront() << endl;
    cout << "Queue size: " << q.getSize() << endl;    
    
    return 0;
}