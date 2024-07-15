    
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// In this modified dijkstra take pr in the check pr + len < d[to] and not d[v] as d[v]
// may come from some cheaper longer methods. A subtle point to ponder !

// [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vi d(n,INT_MAX);
        vvvi adj(n);

        for(auto it : flights)
        {
            adj[it[0]].pb({it[1],it[2]});
        }
        
        int s = src;

        d[s] = 0;
        
        priority_queue<pair<int,pi>,vector<pair<int,pi>> , greater<pair<int,pi>> > q;
        q.push({0,{s,0}}); // stops node d[v]

        while (!q.empty()) 
        {
            int v = q.top().ss.ff; // node
            int l = q.top().ff; // stops
            int pr = q.top().ss.ss; // d[v]

            q.pop();

            if (l > k) continue;

            for(auto it : adj[v])
            {
                int to = it[0];
                int len = it[1];
                
                if (pr + len < d[to]) 
                {
                    d[to] = pr + len;
                    q.push({l + 1 , {to,d[to]}});
                }
            }
        }
        return (d[dst] == INT_MAX) ? -1 : d[dst];
    }
};