#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    int l_count = -1;
    void dfs(TreeNode* node,vector<vector<int>> &r,int level)
    {
        if(!node)
        {
            return;
        }

        // Better than pre-initialising :

        // if(level >= r.size())
        // {
        //     r.push_back({});
        // }

        l_count = max(l_count, level);

        r[level].push_back(node->val);

        dfs(node->left,r,level+1);
        dfs(node->right,r,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res(20000);
        dfs(root,res,0);
        res.resize(l_count+1);
        return res;
    }
};