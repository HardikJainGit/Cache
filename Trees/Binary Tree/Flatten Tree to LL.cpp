#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) 
    {
        if(!root)
        {
            return;
        }

        TreeNode* temp_r = NULL;
        TreeNode* temp_l = NULL;

        flatten(root -> right);
        flatten(root -> left);
        
        temp_l = root -> left;
        temp_r = root -> right;

        root -> right = temp_l;
        root -> left = NULL;

        if(!temp_l)
            temp_l = root;

        while(temp_l -> right)
        {
            temp_l = temp_l -> right;
        }

        temp_l -> right = temp_r;

    }
};