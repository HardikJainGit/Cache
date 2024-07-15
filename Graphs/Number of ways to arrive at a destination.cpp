#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

#define vi vector<int>
#define vvi vector<vector<int>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    int dijkstras(int s, vector<long long>& d, vector<vector<vector<int>>>& adj, vi &dp) 
    {
        int n = d.size();
        vector<bool> vis(n, false);

        d[s] = 0;
        dp[s] = 1;

        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q; 

        q.push({0, s}); // dist , node
        
        while (!q.empty())
        {
            int v = q.top().second;
            long long d_v = q.top().first;
            q.pop();
                        
            if (d_v != d[v])
                continue;

            for (const auto& edge : adj[v]) 
            {
                int to = edge[0];
                int len = edge[1];
                if (d[v] + len < d[to]) 
                {
                    d[to] = d[v] + len;
                    dp[to] = dp[v];
                    q.push({d[to], to});
                }
                else if (d[v] + len == d[to]) 
                {
                    dp[to] = (dp[to] + dp[v]) % MOD;
                }
            }
        }
        return dp[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<vector<vector<int>>> adj(n);

        for (const auto& edge : roads) 
        {
            int u = edge[0]; 
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> d(n, LLONG_MAX);
        vector<int> dp(n, 0);
        return dijkstras(0, d, adj, dp);
    }
};