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

// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

const int MOD = 1e5;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        if (start == end) return 0;
        vector<int> vis(MOD, 0);
        vector<int> d(MOD, INT_MAX);
        d[start] = 0;
        vis[start] = 1;
        int n = MOD; // number of nodes
        int s = start; // source vertex
        
        queue<int> q;
        
        q.push(s);
        vis[s] = 1;

        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();
            
            if(v == end)
            {
                return d[end];
            }
            
            for (int it : arr) 
            {
                int next = (v * it) % MOD;
                
                if (!vis[next]) 
                {
                    vis[next] = 1;
                    d[next] = d[v] + 1;
                    q.push(next);
                }
            }
        }
        return -1;  
    }
};