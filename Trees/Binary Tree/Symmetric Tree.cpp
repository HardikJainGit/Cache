#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/symmetric-tree/

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
    void dfs(TreeNode* p , TreeNode* q , int &f)
    {
        if(p && !q)
        {
            f = 1;
            return;
        }
        if(!p && q)
        {
            f = 1;
            return;
        }
        if(!p && !q)
        {
            return;
        }

        if(p->val != q->val)
        {
            f = 1;
        }

        dfs(p->left , q->right , f);
        dfs(p->right , q->left , f);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int f = 0;
        dfs(p,q,f);
        if(f)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool isSymmetric(TreeNode* root) 
    {
        return isSameTree(root->right , root->left);
    }
};