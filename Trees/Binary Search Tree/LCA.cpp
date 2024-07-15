#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root || root == p || root == q)
        {
            return root;
        }
        
        TreeNode* l = NULL;
        TreeNode* r = NULL;

        if(p -> val < root -> val && q -> val < root -> val)
        {
            l = lowestCommonAncestor(root -> left , p , q);
        }
        else if(p -> val > root -> val && q -> val > root -> val)
        {
            r = lowestCommonAncestor(root -> right , p ,q);
        }
        else
        {
            return root;
        }

        if(!l)
        {
            return r;
        }

        else if(!r)
        {
            return l;
        }

        else if(l && r)
        {
            return root;
        }

        return NULL;
    
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p -> val < root -> val && q -> val > root -> val || p -> val > root -> val && q -> val < root -> val)
        {
            return root;
        }

        return dfs(root , p , q);
    }
};
