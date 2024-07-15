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

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	
    struct DSU
    {
        int n;
        vi p;
        DSU(int n)
        {
            p.assign(n + 1,0);
            fz(i,1,n+1)
                p[i] = i;
        }
        int par(int i)
        {
            if (p[i] == i)
                return i;
            return p[i] = par(p[i]);
        }
        void un(int u,int v)
        {
            u = par(u),v = par(v);
            if(u==v) return;
            p[v] = u;
        }
    };  
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        set<vector<int>> s; // w u v
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                s.insert({adj[i][j][1],adj[i][j][0],i});
            }
        }
        
        DSU dsu(V);
        int n = 0;
        int sum = 0;
        
        while(n!=V-1)
        {
            auto it = s.begin();
            int w = (*it)[0];
            int u = (*it)[1];
            int v = (*it)[2];
            s.erase(it);
            
            if(dsu.par(u) != dsu.par(v))
            {
                sum += w;
                dsu.un(u,v);
                n += 1;
            }
            
        }
        
        return sum;
    }
};