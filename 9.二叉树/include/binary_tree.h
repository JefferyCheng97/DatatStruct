#include <iostream>

template <typename T>

struct TreeNode
{
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree
{
private:
    TreeNode<T>* nodes;
    TreeNode<T>* root;
    size_t nodeSize;

    TreeNode<T>* create(T a[], int size, int nodeId, T nullNode);
    void visit(TreeNode<T>* node);
    void preOrder(TreeNode<T>* node);
    void inOrder(TreeNode<T>* node);
    void postOrder(TreeNode<T>* node);

public:
    Tree();
    Tree(int maxNodes);
    ~Tree();

    TreeNode<T>* getTreeNode(int id);
    void createTree(T a[], int size, T nullNode);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
};

template <typename T>
Tree<T>::Tree()
{
    nodeSize = 10086;
    nodes = new TreeNode<T>[nodeSize];    
}

template <typename T>
Tree<T>::Tree(int maxNodes)
{
    nodeSize = maxNodes;
    nodes = new TreeNode<T>[nodeSize];
}

template <typename T>
Tree<T>::~Tree()
{
    delete[] nodes;
}

template <typename T>
TreeNode<T>* Tree<T>::getTreeNode(int id)
{
    return &nodes[id];
}

template <typename T>
void Tree<T>::visit(TreeNode<T>* node)
{
    std::cout << node->val << " ";
}

template <typename T>
void Tree<T>::preOrder(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        return;
    }

    visit(node);
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void Tree<T>::inOrder(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    inOrder(node->left);
    visit(node);
    inOrder(node->right);
}

template <typename T>
void Tree<T>::postOrder(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    postOrder(node->left);
    postOrder(node->right);
    visit(node);
}

template <typename T>
void Tree<T>::createTree(T a[], int size, T nullNode)
{
    root = create(a, size, 1, nullNode);
}

template <typename T>
TreeNode<T>* Tree<T>::create(T a[], int size, int nodeId, T nullNode)
{
    if (nodeId >= size || a[nodeId] == nullNode)
    {
        return nullptr;
    }

    TreeNode<T>* nowNode = getTreeNode(nodeId);
    nowNode->val = a[nodeId];
    nowNode->left = create(a, size, 2 * nodeId, nullNode);
    nowNode->right = create(a, size, 2 * nodeId + 1, nullNode);

    return nowNode;
}

template <typename T>
void Tree<T>::preOrderTraversal()
{
    preOrder(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::inOrderTraversal()
{
    inOrder(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::postOrderTraversal()
{
    postOrder(root);
    std::cout << std::endl;
}