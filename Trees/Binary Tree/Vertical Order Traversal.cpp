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

// 	https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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

    void dfs(map<int,map<int,multiset<int>>> &m , TreeNode* cur,int x , int lvl)
    {
        if(!cur)
        {
            return;
        }
        m[x][lvl].insert(cur->val);
        dfs(m,cur->left,x-1,lvl+1);
        dfs(m,cur->right,x+1,lvl+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,map<int,multiset<int>>> m; // vertical level nodes

        dfs(m,root,0,0);

        vvi ret;

        for(auto& pair : m)
        {
            ret.push_back(vector<int>()); // need a vector for each x
            for(auto& pair2 : pair.ss)
            {
                for(auto& val : pair2.ss)
                {
                    ret.back().push_back(val);
                }
            }
        }

        return ret;
    }
};

// BFS :

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue <pair<TreeNode*,pi>> q;
        map<int,map<int,multiset<int>>> m; // vertical level nodes
        q.push({root,{0,0}}); // Node , vertical(x) , level

        while(!q.empty())
        {          
            TreeNode* cur = q.front().ff;
            int x = q.front().ss.ff;
            int lvl = q.front().ss.ss;
            q.pop();

            m[x][lvl].insert(cur->val);
            
            if(cur->left)q.push({cur -> left , {x-1 , lvl+1}});
            if(cur->right)q.push({cur -> right,{x+1,lvl+1}});
        }

        vvi ret;

        for(auto& pair : m)
        {
            ret.push_back(vector<int>()); // need a vector for each x
            for(auto& pair2 : pair.ss)
            {
                for(auto& val : pair2.ss)
                {
                    ret.back().push_back(val);
                }
            }
        }

        return ret;
    }
};