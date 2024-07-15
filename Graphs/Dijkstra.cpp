#include<bits/stdc++.h>
using namespace std;

// 	https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

const int INF = INT_MAX;

class Solution
{
public:
    void dijkstra(int s, vector<int>& d, vector<vector<int>> adj[]) 
    {
        int n = d.size();
        d.assign(n, INF);
        vector<bool> vis(n, false);

        d[s] = 0;
        
        // get the minimum dist non visited node :
        // O(m + n^2)
        
        // for (int i = 0; i < n; i++) 
        // {
        //     int v = -1;
        //     for (int j = 0; j < n; j++) 
        //     {
        //         if (!vis[j] && (v == -1 || d[j] < d[v]))
        //             v = j;
        //     }
        
        // PQ method O(VlogV + E)
        
        // using pii = pair<int, int>;
        // priority_queue<pii, vector<pii>, greater<pii>> q; // min Heap

        // q.push({0,s}); // dist , node
        
        // while(!q.empty())
        // {
        //     int v = q.top().second;
        //     int d_v = q.top().first;
        //     q.pop();
            
        //     // Check to reduce iterations
            
        //     if (d_v != d[v]) // remove duplicate iterations since this isn't a set
        //     continue;
        
        //We simply don't delete the old pair from the queue. 
        //As a result a vertex can appear multiple times with
        //different distance in the queue at the same time. 
        //Among these pairs we are only interested in the pairs
        //where the first element is equal to the corresponding
        //value in d[], all the other pairs are old. 
        //Therefore we need to make a small modification: 
        //at the beginning of each iteration, after extracting 
        //the next pair, we check if it is an important pair or
        //if it is already an old and handled pair. 
        //This check is important, otherwise the complexity can increase
            
            // vis[v] = true;
            
        // Both set and queue give sorted things and 
        // we set distance as first to get shortest first
            
        set<pair<int, int>> q;
        q.insert({0, s});
        while (!q.empty()) 
        {
            // int v = q.begin()->second or :
            int v = (*q.begin()).second;
            q.erase(q.begin());

            for (int j = 0; j < adj[v].size(); j++) 
            {
                int to = adj[v][j][0];
                int len = adj[v][j][1];
                if (d[v] + len < d[to]) 
                {
                    d[to] = d[v] + len;
                    q.insert({d[to], to});
                    // p[to] = v;
                }
            }
        }
    }

    vector<int> restore_path(int s, int t, const vector<int>& p) 
    {
        vector<int> path;

        for (int v = t; v != s; v = p[v])
            path.push_back(v);
            
        path.push_back(s);

        reverse(path.begin(), path.end());
        return path;
    }

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> d(V);
        dijkstra(S, d, adj);
        return d;
    }
};