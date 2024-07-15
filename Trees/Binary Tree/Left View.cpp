//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void dfs(Node* node , vector <int> &v,int level,map<int,int> &vis)
{
    if(!node)
    {
        return;
    }
    if(!vis[level])
    {
        vis[level] = 1;
        v.push_back(node->data);
    }
    
    // if(node->left)
    {
        dfs(node->left , v,level+1,vis);
    }
    // else
    {
        dfs(node->right,v,level+1,vis);
    }
}
vector<int> leftView(Node *root)
{
   if(!root)
   {
       return{};
   }
   vector<int> v;
//   v.push_back(root->data);
   map<int,int> vis;
   dfs(root,v,0,vis);
   return v;
}

// BFS Level order

vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root)
        {
            return {};
        }

        queue <Node*> q;
        q.push(root);
        vector<vector<int>> v;
        int level = 0;

        while(!q.empty())
        {
            int k = q.size();

            v.push_back(vector<int>()); 
            
            for(int i = 0 ;i<k;i++)
            {
                Node* cur = q.front();
                q.pop();
                
                v[level].push_back(cur -> data);

                if(cur->left)q.push(cur -> left);
                if(cur->right)q.push(cur -> right);
            }

            level += 1;
        }
        
        return v;
    }
vector<int> leftView(Node *root)
{
   vector <vector<int>> r;
   r = levelOrder(root);
   vector <int> v;
   
   for(auto it : r)
   {    
       v.push_back(it[0]);
   }
   
   return v;
}

