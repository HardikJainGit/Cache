#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void dfs(int v,vector<bool> &visited,vector<int> &v_dfs, vector<int> adj[]) {
        visited[v] = true;
        v_dfs.push_back(v);

        for (int u : adj[v]) 
        {
            if (!visited[u])
            {
                dfs(u,visited,v_dfs,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V,false);
        vector<int> v_dfs;
        dfs(0,visited,v_dfs,adj);
        return v_dfs;
    }
};