#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src, vector<int>& parent) 
   {
        vector<int> distance(n, 1e8);
        distance[src] = 0;

    // Relax edges |V| - 1 times as worst case it takes n-1 iterations to traverse the graph
    //(Straight line graph)
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
    
                // Check if it is reachable by checking it is not 1e8
                if (distance[u]!=1e8 && distance[u] + w < distance[v]) 
                {
                    distance[v] = distance[u] + w;
                    parent[v] = u; //keep track of parent to get the actual shortest path
                }
            }
        }
        
        for (int j = 0; j < m; j++) 
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
    
            if (distance[u]!=1e8 && distance[u] + w < distance[v]) 
            {
                return {};
            }
        }   
        return distance;
    }
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) 
    {
        vector<int> parent(V,-1);
        vector<int> ret = shortestPath(edges,V,edges.size(),S,parent);
        if(!ret.size())
        {
            return {-1};
        }
        else
        {
            return ret;
        }
    }
};