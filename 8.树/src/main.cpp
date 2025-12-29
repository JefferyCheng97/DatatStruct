#include "../include/tree.h"

int main()
{
    Tree<char> T(9);
    T.setRoot(0);
    T.assignData(0, 'a');
    T.assignData(1, 'b');
    T.assignData(2, 'c');
    T.assignData(3, 'd');
    T.assignData(4, 'e');
    T.assignData(5, 'f');
    T.assignData(6, 'g');
    T.assignData(7, 'h');
    T.assignData(8, 'i');

    T.addChild(0, 1);
    T.addChild(0, 2);
    T.addChild(1, 3);
    T.addChild(2, 5);
    T.addChild(2, 4);
    T.addChild(3, 8);
    T.addChild(3, 7);
    T.addChild(3, 6);
    
    T.print();
}