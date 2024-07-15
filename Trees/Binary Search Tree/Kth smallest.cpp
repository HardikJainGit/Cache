#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int count = 0;
    void dfs(TreeNode* root , int k , TreeNode* &kth)
    {
        if(!root)
        {
            return;
        }
        dfs(root -> left , k , kth);
        count +=1;
        if(count == k)
        {
            kth = root;
            return;
        }
        dfs(root -> right , k , kth);

    }
    int kthSmallest(TreeNode* root, int k) 
    {
        if(!root)
        {
            return -1;
        }
        TreeNode* kth = NULL;
        dfs(root , k , kth);
        return kth -> val;
    }
};

// Kth largest

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    int count = 0;
    int n = 0;
    // void dfs_n(Node* root)
    // {
    //     if(!root)
    //     {
    //         return;
    //     }
    //     n += 1;
    //     dfs_n(root -> right);
    //     dfs_n(root -> left);
    // }
    void dfs(Node* root , int k , Node* &kth)
    {
        if(!root)
        {
            return;
        }
        dfs(root -> right , k , kth);
        count +=1;
        if(count == k)
        {
            kth = root;
            return;
        }
        dfs(root -> left , k , kth);

    }
    int kthLargest(Node *root, int K)
    {
        if(!root)
        {
            return -1;
        }
        Node* kth = NULL;
        // dfs_n(root);
        dfs(root , K , kth);
        return kth -> data;
    }
};