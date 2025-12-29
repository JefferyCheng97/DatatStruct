#include "../include/binary_tree.h"

int main()
{
    const char nullNode = '-';
    char a[] = { 
        nullNode, 'a', 'b', 'c', 'd', 
        nullNode, 'e', 'f', 'g', 'h',
        nullNode, nullNode, nullNode, nullNode, 'i'
    };

    Tree<char> T(15);
    T.createTree(a, 15, nullNode);
    T.preOrderTraversal();
    T.inOrderTraversal();
    T.postOrderTraversal();

    return 0;
}