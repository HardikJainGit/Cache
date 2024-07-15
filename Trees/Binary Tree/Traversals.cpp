#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/binary-tree-inorder-traversal/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// In Order LNR

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current || !s.empty()) 
        {
            //L
            while (current) 
            {
                s.push(current);
                current = current->left;
            }

            //N
            current = s.top();
            s.pop();
            v.push_back(current->val);

            //R
            current = current->right;
        }

        return v;
    }
};

// Pre order :

// https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current || !s.empty()) 
        {
            //NLR
            while(current)
            {
                v.push_back(current->val);
                s.push(current);
                current = current -> left;
            }

            current = s.top();
            s.pop();

            current = current -> right;     
        }
        return v;
    }
};