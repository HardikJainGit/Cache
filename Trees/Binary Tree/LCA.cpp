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

// 	https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // Either compare paths to p and q from root or :

        if(!root || root == p || root == q)
        {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root -> left , p , q);
        TreeNode* r = lowestCommonAncestor(root -> right , p ,q);

        if(!l)
        {
            return r;
        }

        else if(!r)
        {
            return l;
        }

        else if(l && r)
        {
            return root;
        }

        return NULL;
    }
};

// Get the paths from root to nodes and compare them

class Solution {
public:
    void findPaths(TreeNode* node, vector<TreeNode*>& currentPath, vector<TreeNode*>& f_path,TreeNode* target) 
    {
        if (!node) 
        {
            return;
        }

        currentPath.push_back(node);

        if (node == target) 
        {
            f_path = currentPath;
        } 
        else 
        {
            findPaths(node->left, currentPath, f_path,target);
            findPaths(node->right, currentPath, f_path,target);
        }

        currentPath.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> v;
        vector<TreeNode*> v2;
        vector<TreeNode*> c;

        findPaths(root,c,v,p);
        findPaths(root,c,v2,q);

        TreeNode* r = root;

        f(min(sz(v),sz(v2)))
        {
            if(v[i] == v2[i])
            {
                r = v[i];
            }
        }
        return r;
    }
};