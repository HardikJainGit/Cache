#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/recover-binary-search-tree/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void dfs_inorder(TreeNode* root , TreeNode* &prev , TreeNode* &f , TreeNode* &s)
    {
        if(!root)
        {
            return;
        }
        
        dfs_inorder(root -> left , prev , f , s);

        if(prev && root -> val < prev -> val)
        {
            if(!f)
            {
                f = prev;
            }
            s = root;
        }

        prev = root;
        
        dfs_inorder(root->right, prev, f, s);
    }
    void recoverTree(TreeNode* root) 
    {
        if(!root)
        {
            return;
        }

        TreeNode* f = NULL;
        TreeNode* s = NULL;
        TreeNode* prev = NULL;

        dfs_inorder(root , prev , f ,s);

        swap(f -> val , s -> val);
        
    }
};