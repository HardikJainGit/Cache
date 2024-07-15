#include <bits/stdc++.h>
using namespace std;

// O(N)

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph

class Solution {
  public:
    void Kahn(int i, vector<int> &topo, vector<vector<pair<int, int>>> &adj, vector<int> &indegree, vector<int> &vis) 
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
            
            for (auto &u : adj[v]) 
            {
                indegree[u.first]--;
                
                if (!vis[u.first] && indegree[u.first] == 0) 
                {
                    vis[u.first] = 1;
                    q.push(u.first);
                }
            }
        }
    }
    
	vector<int> topoSort(int V, vector<vector<pair<int, int>>> &adj) 
	{
	    vector<int> indegree(V, 0);
        vector<int> vis(V, 0);
        vector<int> topo;
    
        for (int i = 0; i < V; ++i)
        {
            for (auto &el : adj[i])
            {
                indegree[el.first]++;
            }
        }

        for(int i = 0; i < V; i++) 
        {
            if(!vis[i] && indegree[i] == 0) 
            {
                Kahn(i, topo, adj, indegree, vis);
            }
        }
    
        return topo;
	}

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(N);
        for (auto &edge : edges) 
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        int src = 0;
        vector<int> topo = topoSort(N, adj);
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;

        // O(M+N) linear better for DAG better than Dijkstra

        for(int el : topo)
        {
            if(dist[el] != INT_MAX) // start from source node ignore all nodes above source in topo sort
            {
                for(auto &it : adj[el])
                {
                    int v = it.first;
                    int d = it.second;
                    if(dist[el] + d < dist[v])
                    {
                        dist[v] = dist[el] + d;
                    }
                }
            }
        }

        for (int i = 0; i < dist.size(); ++i)
        {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};