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

// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

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
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = sz(stones);
        DSU dsu(n);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = i + 1; j < stones.size(); j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    dsu.un(i, j);
                }
            }
        }
        int cc = 0;
        vi vis(n,0);
        for (int i = 0; i < stones.size(); i++)
        {
            int p = dsu.par(i);
            if (!vis[p])
            {
                cc += 1;
                vis[p] = 1;
            }
        }

        return stones.size() - cc;
    }
};