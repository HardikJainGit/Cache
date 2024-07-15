#include<bits/stdc++.h>
using namespace std;

// 	https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution{
    public:
    
    void dfs(Node* root, int &f)
    {
        if (!root)
        {
            return;
        }
        
        if (root->left && root->right)
        {
            if (root->data != root->left->data + root->right->data)
            {
                f = 0;
            }
        }
        else if (root->left)
        {
            if (root->data != root->left->data)
            {
                f = 0;
            }
        }
        else if (root->right)
        {
            if (root->data != root->right->data)
            {
                f = 0;
            }
        }
        
        dfs(root->left, f);
        dfs(root->right, f);
    }
    
    int isSumProperty(Node *root)
    {
        if (!root)
        {
            return 1;
        }
        int f = 1;
        dfs(root, f);
        return f;
    }
};