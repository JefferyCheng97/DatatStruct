#pragma once

#include <iostream>

template <typename T>
struct ListNode
{
    T data;
    ListNode* next;

    ListNode(T d): data(d), next(nullptr) {}
};


template <typename T>
struct TreeNode
{
    T data;
    ListNode<TreeNode<T>*>* childrenHead;
    TreeNode(): childrenHead(nullptr) {}

    void addChild(TreeNode<T>* node)
    {
        ListNode<TreeNode<T>*>* childNode = new ListNode<TreeNode<T>*>(node);

        if (childrenHead == nullptr)
        {
            childrenHead = childNode;
        }
        else
        {
            childNode->next = childrenHead;
            childrenHead = childNode;
        }
    }
};


template <typename T>
class Tree
{
private:
    TreeNode<T>* nodes;
    TreeNode<T>* root;

public:
    Tree();
    Tree(int maxNodes);
    ~Tree();

    TreeNode<T>* getTreeNode(int id);
    void setRoot(int rootId);
    void addChild(int parentId, int sonId);
    void assignData(int nodeId, T data);
    void print(TreeNode<T>* node = nullptr);
};


template <typename T>
Tree<T>::Tree()
{
    nodes = new TreeNode<T>[10086];
}

template <typename T>
Tree<T>::Tree(int maxNodes)
{
    nodes = new TreeNode<T>[maxNodes];
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
void Tree<T>::setRoot(int id)
{
    root = getTreeNode(id);
}

template <typename T>
void Tree<T>::addChild(int parentId, int sonId)
{
    TreeNode<T>* parentNode = getTreeNode(parentId);
    TreeNode<T>* sonNode = getTreeNode(sonId);
    parentNode->addChild(sonNode);
}

template <typename T>
void Tree<T>::assignData(int id, T data)
{
    getTreeNode(id)->data = data;
}

template <typename T>
void Tree<T>::print(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        node = root;
    }

    std::cout << node->data << " ";

    ListNode<TreeNode<T>*>* child = node->childrenHead;

    while (child != nullptr)
    {
        print(child->data);
        child = child->next;
    }
}
