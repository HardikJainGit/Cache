#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vi>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

// 	https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    void findPaths(Node* node, vector<int>& currentPath, vector<vector<int>>& allPaths) 
    {
        if (!node) 
        {
            return;
        }

        currentPath.push_back(node->data);

        // If it's a leaf node, add the current path to allPaths
        if (!node->left && !node->right) 
        {
            allPaths.push_back(currentPath);
        } 
        else 
        {
            // Otherwise, traverse the left and right subtrees
            findPaths(node->left, currentPath, allPaths);
            findPaths(node->right, currentPath, allPaths);
        }

        // Backtrack to explore other paths
        currentPath.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vvi v;
        if(!root)
        {
            return v;
        }
        if (!root->left && !root->right) 
        {
            v.push_back({root->data});
            return v;
        }
        vi r;
        findPaths(root,r,v);
        return v;
    }
};