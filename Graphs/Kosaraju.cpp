#include<bits/stdc++.h>
using namespace std;

// 	https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
	public:
	
    // For Directed Graph
    // a path from every vertex to every other vertex
    
    void dfs(int v,vector<bool> &visited,stack <int> &topo, vector<vector<int>> &adj) 
	{
        visited[v] = true;

        for (int u : adj[v]) 
        {
            if (!visited[u])
            {
                dfs(u,visited,topo,adj);
            }
        }
        topo.push(v);
    }
	vector<int> topoSort(int V, vector<vector<int>> &adj) 
	{
	    vector<bool> visited(V,false);
        vector<int> topo_v;
        stack<int> topo;
        for (int i = 0; i < V; ++i) 
        {
            if (!visited[i])
            {
                dfs(i, visited, topo, adj);
            }
        }
        while(!topo.empty()) 
        {
            topo_v.push_back(topo.top());
            topo.pop();
        }
        return topo_v;
	}
	
	void dfsT(int node, vector<int> &vis, vector<vector<int>>& adjT) 
	{
        vis[node] = 1;
        for (auto it : adjT[node]) 
        {
            if (!vis[it]) 
            {
                dfsT(it, vis, adjT);
            }
        }
    }
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // iterate the topo sort and find no of CC done for reversed graph !?
        
        vector <int> topo = topoSort(V,adj);
        
        vector<vector<int>> adjT(V); //reverse the graph and unvisit all the nodes stopping to go the next SCC
        
        for (int i = 0; i < V; i++) 
        {
            for (auto it : adj[i]) 
            {
                adjT[it].push_back(i);
            }
        }
        
        int scc = 0;
        vector <int> vis(V,0);

        for(int i=0;i<topo.size();i++)
        {
            if(!vis[topo[i]])
            {
                scc += 1;
                dfsT(topo[i],vis,adjT);
            }
        }
        
        return scc;
    }
};