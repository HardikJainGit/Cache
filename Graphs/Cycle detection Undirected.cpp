#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0

class Solution {
  public:
    bool isCyclicBFS(int src , int V, vector<int> adj[]) 
    {
        int n = V; 
        int s = src; 
        
        queue<int> q;
        vector<bool> vis(n,false);
        vector<int> p(n,-1);
        
        q.push(s);
        vis[s] = true;
        p[s] = -1;
        
        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) 
            {
                if(vis[u] && p[v]!=u)
                {
                    return true;
                }
                if (!vis[u]) 
                {
                    vis[u] = true;
                    q.push(u);
                    p[u] = v;
                }
            }
        }
        
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> vis(V,false);
        bool cycle = false;

        for(int i = 0;i<V;i++) 
        {
	        if(!vis[i]) 
	        {
	            bool cycle = isCyclicBFS(i,V,adj);
	            if(cycle)
	            {
	                return true;
	            }
	        }
	    }

        return cycle;
    }
};

// DFS 

class Solution {
  public:
    bool isCyclicDFS(vector<int> adj[], vector<bool> &vis, int Node, int parent,bool &cycle) 
    {
        vis[Node] = true;
        
        for(auto i : adj[Node]) 
        {
            if(!vis[i]) 
            {
                if(isCyclicDFS(adj, vis, i, Node,cycle))
                {
                    return true;
                }
            } 
            else if(i != parent)  
            {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> vis(V,false);
        bool cycle = false;

        for(int i = 0;i<V;i++) 
        {
	        if(!vis[i]) 
	        {
	            
	            if(isCyclicDFS(adj,vis,i,-1,cycle))
	            {
	                return true;
	            }
	        }
	    }

        return false;
    }
};
