#include<bits/stdc++.h>
using namespace std;

// 	https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    void f(Node* root, int level,int x,map<int,pair<int,int>> &mp){
        
        if(!root)
        return;
    
        // Just replace the BFS traversal by the recursive DFS traversal
        // because dfs is random so this check is required
       if(level>=mp[x].second) //equality as we want later one in level order
       mp[x]={root->data,level};

       // For top view :
    //    if(mp.find(x) == mp.end() || mp[x].second > level) // current level is less
    //     {
    //         mp[x] = {root->data, level};
    //     }
    
        f(root->left,level+1,x-1,mp);
        f(root->right,level+1,x+1,mp);
    
    }
    vector <int> bottomView(Node *root) {
        map<int,pair<int,int>> mp; // val , level 
        f(root,0,0,mp);
        vector<int> v;
        
        for(auto pair : mp)
        {
            v.push_back(pair.second.first);
        }
        
        return v;
        
    }
};

// BFS
#include <bits/stdc++.h>
using namespace std;

#define py cout << "YES\n";
#define pn cout << "NO\n";
#define vi vector <int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; fz(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue <pair<Node*,int>> q;
        map<int,int> m; // x nodes
        q.push({root,0}); // Node x

        while(!q.empty())
        {          
            Node* cur = q.front().ff;
            int x = q.front().ss;
            q.pop();

            m[x] = (cur->data);
            
            if(cur->left)q.push({cur -> left , x-1});
            if(cur->right)q.push({cur -> right,x+1});
        }

        // debug(m);

        vi btv;

        for(auto& pair : m)
        {
            btv.pb(pair.ss);
        }

        // debug(btv);
        return btv;
    }
};