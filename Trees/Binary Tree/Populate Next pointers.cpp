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

// 	https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:

    void bfs(Node* root) 
    {
        if(!root)
        {
            return;
        }

        queue <pair<Node* , int>> q;
        q.push({root , 0});
        int level = 0;

        while(!q.empty())
        {
            int k = q.size();
            
            for(int i = 0 ;i<k;i++)
            {
                Node* cur = q.front().ff;
                level = q.front().ss; 

                q.pop();

                Node* cur_n = NULL;

                if(!q.empty() && q.front().ss == level)
                {
                    cur_n = q.front().ff;
                }
                
                cur -> next = cur_n;

                if(cur->left)q.push({cur -> left , level + 1});
                if(cur->right)q.push({cur -> right , level + 1});
            }
        }
    }

    Node* connect(Node* root) 
    {
        if(!root)
        {
            return root;
        }
        bfs(root);
        return root;
    }
};