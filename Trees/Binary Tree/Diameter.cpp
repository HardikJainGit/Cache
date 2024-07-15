#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/diameter-of-binary-tree/

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
    int dia = 0;
    int dfs(TreeNode* node) 
    {
        if(!node)
        {
            return 0;
        }
        int l = dfs(node->left);
        int r = dfs(node->right);

        dia = max(dia, l+r);

        return max(l,r) + 1; // height
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root->right && !root->left)
        {
            return 0;
        }
        dfs(root);
        return dia;
    }
};