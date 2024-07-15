#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(!preorder.size() || !inorder.size())
        {
            return NULL;
        }

        TreeNode* root = new TreeNode (preorder[0]);

        int idx = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + idx); // excludes idx + 1 includes +1
        vector<int> rightPreorder(preorder.begin() + 1 + idx, preorder.end());
        vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
        vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};