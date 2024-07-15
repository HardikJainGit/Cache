#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
         if(!postorder.size() || !inorder.size())
        {
            return NULL;
        }

        TreeNode* root = new TreeNode (postorder.back());

        int idx = find(inorder.begin(), inorder.end(), postorder.back()) - inorder.begin();

        vector<int> leftpostorder(postorder.begin(), postorder.begin() + idx); // idx is shifted to the left by 1
        vector<int> rightpostorder(postorder.begin() + idx, postorder.end() - 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
        vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

        root->left = buildTree(leftInorder,leftpostorder);
        root->right = buildTree(rightInorder,rightpostorder);

        return root;
    }
};

