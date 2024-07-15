#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int n = V; // number of nodes
        int s = 0; // source vertex
        
        queue<int> q;
        vector<bool> used(n);
        vector<int> d(n), p(n);
        
        vector<int> v_bfs;
        
        q.push(s);
        used[s] = true;
        p[s] = -1;
        
        while (!q.empty()) 
        {
            int v = q.front();
            v_bfs.push_back(v);
            q.pop();
            for (int u : adj[v]) 
            {
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }
        
        return v_bfs;
        
    }
};