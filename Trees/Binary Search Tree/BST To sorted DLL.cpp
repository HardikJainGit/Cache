#include<bits/stdc++.h>
using namespace std;

// 	https://www.naukri.com/code360/problems/bst-to-sorted-dll_1263694

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int>* bstToSortedDLL(TreeNode<int> *root, TreeNode<int> *&tail)
{
    if (!root)
    {
        return NULL;
    }

    TreeNode<int>* l_head = bstToSortedDLL(root->left, tail);

    if (tail)
    {
        tail->right = root;
        root->left = tail;
    }

    tail = root;

    // Pass the current tail to r_head to cater connection of r_head to tail
    
    TreeNode<int>* r_head = bstToSortedDLL(root->right, tail);

    return l_head ? l_head : root;
}

TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int>* tail = NULL;
    return bstToSortedDLL(root, tail);
}
