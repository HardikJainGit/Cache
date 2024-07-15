#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int dfs(TreeNode* node,int &d) 
    {
        if (!node) 
        {
            return 0;
        }

        else
        {
            int l = dfs(node->left , d);
            int r = dfs(node->right , d);

            d = max({d , l + r + node->val , node->val , node->val + l , node->val + r});

            return max({l , r ,0}) + node->val;
        }
        
    }
    int maxPathSum(TreeNode* root) 
    {
        int d = INT_MIN;
        dfs(root , d);
        return d;
    }
};