#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/same-tree/

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
    bool f = 0;
    void dfs(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        {
            return;
        }
        if((p && !q) || (!p && q))
        {
            f = 1;
            return;
        }
        if(p->val != q->val)
        {
            f = 1;
            return;
        }
        dfs(p->right,q->right);
        dfs(p->left,q->left);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p,q);
        return !f;
    }
};