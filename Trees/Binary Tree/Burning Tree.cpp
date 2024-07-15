#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    void dfsf(Node* root, int target, Node* &fnd)
    {
        if (!root)
        {
            return;
        }
        if (root->data == target)
        {
            fnd = root;
        }
        dfsf(root->left, target, fnd);
        dfsf(root->right, target, fnd);
    }

    Node* search_target(Node* root, int val)
    {
        if (!root)
        {
            return NULL;
        }
        Node* fnd = NULL;
        dfsf(root, val, fnd);
        return fnd;
    }

    void dfs_m(Node* root , Node* prev,map<Node*,Node*> &m)
    {
        if(!root)
        {
            return;
        }
        
        m[root] = prev;
        
        dfs_m(root -> left , root , m);
        dfs_m(root -> right , root , m);
    }
    int height(Node* root , map<Node*,Node*>&par ,  unordered_map<Node*, int>&vis)
    {
        // visited is necessary otherwise calls won't end
        
        if(!root)
        {
            return 0;
        }
        
        vis[root]=1;
        
        int lh= -1;
        int rh= -1;
        int ph= -1;
        
        if(!vis[root->left])
        lh= height(root->left, par, vis);
          
        if(!vis[root->right])
        rh= height(root->right, par, vis);
        
        if(!vis[par[root]])
        ph= height(par[root] , par, vis);
        
        return  max({rh , lh , ph}) +1;
    }
    int minTime(Node* root, int target) 
    {
        map<Node* , Node*> m; // Parent Mapping
        Node* fire = search_target(root , target);
        // if(fire) cout << fire->data;
        Node* prev = NULL;
        dfs_m(root , prev, m);
        if (fire == NULL) 
        {
            return -1; 
        }
        unordered_map<Node*, int> vis;
        return height(fire , m , vis) - 1;
    }
};

