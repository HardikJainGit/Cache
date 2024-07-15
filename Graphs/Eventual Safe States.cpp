#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-eventual-safe-states/

// Always pass adj by ref to avoid TLE

class Solution {
public:
    void Kahn(int i , vector<int> &topo, vvi &adj, vector<int> &indegree, vector<int> &vis) 
    {
        queue<int> q;

        if(indegree[i] == 0 && !vis[i])
        {
            q.push(i);
            vis[i] = 1;
        }
    
        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();
            
            topo.push_back(v);
            
            for (int u : adj[v]) 
            {
                indegree[u]--;
                
                if (!vis[u] && !indegree[u]) 
                {
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    
	vector <int> topoSort(int V, vvi &adj) 
	{
	    int v = V;
	    vector<int> indegree(v,0);
        vector<int> vis(v,0);
        vector <int> topo;
    
        for (int i = 0; i < V; ++i)
        {
            for (int el : adj[i])
            {
                indegree[el]++;
            }
        }

        for(int i=0; i<v; i++) 
        {
            if(!vis[i] && indegree[i] == 0) 
            {
                Kahn(i,topo, adj, indegree, vis);
            }
        }
    
        return topo;
	}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vvi graph_T(sz(graph));
        for(int i=0;i<sz(graph);i++)
        {
            for(auto it : graph[i])
            {
                graph_T[it].push_back(i);
            }
        }
        vector<int> ret = topoSort(sz(graph),graph_T);
        // vi v;
        // for(auto it: ret)
        // {
        //     v.push_back(it);
        // }
        srt(ret);
        return ret;
    }
};