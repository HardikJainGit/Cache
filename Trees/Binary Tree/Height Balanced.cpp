#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/balanced-binary-tree/

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
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);

        if(abs(l-r) > 1) f = 1;

        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return true;
        }

        dfs(root);
        
        return !f;

    }
};