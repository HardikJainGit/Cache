#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/validate-binary-search-tree/

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
    int f = 1;
    void dfs(TreeNode* root, long long min_l, long long max_r)
    {
        if(!root) return;

        // Top Down //

        if(root->val >= max_r || root -> val <= min_l)
        {
            f = 0;
        }

        dfs(root->right, root->val,max_r);
        dfs(root->left, min_l,root->val);
    }
    bool isValidBST(TreeNode* root) {
        long long mx = LLONG_MAX;
        long long mi = LLONG_MIN;
        dfs(root,mi,mx);
        return f;
    }
};