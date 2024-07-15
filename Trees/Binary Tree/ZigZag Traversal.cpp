#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> bfs(TreeNode* root,bool &dir) 
    {
        if(!root)
        {
            return {};
        }

        queue <TreeNode*> q;
        q.push(root);
        vector<vector<int>> v;
        int level = 0;

        while(!q.empty())
        {
            int k = q.size();
            dir = !dir;
            v.push_back(vector<int>()); 
            
            for(int i = 0 ;i<k;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                if(dir) v[level].push_back(cur -> val);
                else v[level].insert(v[level].begin(), cur -> val);

                if(cur->left)q.push(cur -> left);
                if(cur->right)q.push(cur -> right);
            }

            level += 1;
        }
        return v;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        bool dir = false;
        vector<vector<int>> res;
        res = bfs(root,dir);
        return res;
    }
};

// DFS

class Solution {
public:
    void dfs(TreeNode* node,vector<vector<int>> &r,int level , vector<bool> &dir)
    {
        if(!node)
        {
            return;
        }

        if(level >= r.size())
        {
            r.push_back({});
            dir.push_back(level % 2);
        }

        if (!dir[level])
        {
            r[level].push_back(node->val);
        }
        else
        {
            r[level].insert(r[level].begin(), node->val);
        }
        
        dfs(node->left,r,level+1,dir);
        dfs(node->right,r,level+1,dir);

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<bool> dir;
        vector<vector<int>> res;
        dfs(root,res,0,dir);
        return res;
    }
};