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

struct DSU
{
    int n;
    vi p;
    DSU(int n)
    {
        p.assign(n + 1,0);
        fz(i,1,n)
        p[i] = i;
    }
    int ultpar(int i)
    {
        if (p[i] == i)
        return i;
        return p[i] = ultpar(p[i]);
    }
    void dsu_union(int u,int v)
    {
        u = ultpar(u),v = ultpar(v);
        if(u==v) return;
        p[v] = u;
    }
};

class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& adj) 
	{
        vis[node] = 1;
        for (auto it : adj[node]) 
        {
            if (!vis[it]) 
            {
                dfs(it, vis, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        DSU dsu(n);
        int t_edg = sz(connections);
        vvi adj(n);

        for(auto it : connections)
        {
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
            dsu.dsu_union(it[0],it[1]);
        }

        int cc = 0;
        vi vis(n,0);

        f(n)
        {
            int p = dsu.ultpar(i);
            if(!vis[p])
            {
                cc += 1;
                vis[p] = 1;
            }
        }

        // f(n)
        // {
        //     if(!vis[i])
        //     {
        //         cc += 1;
        //         dfs(i,vis,adj);
        //     }
        // }

        return (t_edg >= n-1) ? (cc - 1) : -1;
    }
};