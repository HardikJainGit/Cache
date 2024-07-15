#include<bits/stdc++.h>
using namespace std;

// 	https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:

    void left(Node* node , vector <int> &v)
    {
        if(!node || (!node->right && !node->left))
        {
            return;
        }
        
        v.push_back(node->data);
        
        if(node->left)left(node->left,v);
        else left(node->right,v);
    }
    
    void right(Node* node , vector <int> &v)
    {
        if(!node || (!node->right && !node->left))
        {
            return;
        }
        
        // v.insert(v.begin(), node->data);

        if(node->right)right(node->right,v);
        else right(node->left,v);
        
        v.push_back(node->data);
    }
    
    void dfs_forleaves(Node* root, vector<int> &ans) 
    {
        if(!root)
        {
            return;
        }
            
        if(!root->left && !root->right) 
        {
            ans.push_back(root->data);
        }
        
        dfs_forleaves(root->left, ans);
        dfs_forleaves(root->right, ans);
        
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        if(!root)
            return ans;
            
        ans.push_back(root->data);
        
        if(!root->right && !root->left)
        {
            return ans;
        }
            
        left(root->left, ans);
        
        dfs_forleaves(root,ans);
        
        // vector<int> rightv;
        right(root->right, ans);

        // ans.insert(ans.end(), rightv.begin(), rightv.end());
        

        return ans;
        
        
    }
};