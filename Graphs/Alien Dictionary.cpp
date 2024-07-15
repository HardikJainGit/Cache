#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary

class Solution{
    public:
    int firstNonMatchingChar(string& str1,string& str2) 
    {
        int len = min(str1.length(), str2.length());
        for (int i = 0; i < len; ++i) {
            if (str1[i] != str2[i]) {
                return i;
            }
        }
        return len;
    }
    void Kahn(int i , vector<int> &topo, vector<vector<int>> adj, vector<int> &indegree, vector<int> &vis) 
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
    
	vector<int> topoSort(int V, vector<vector<int>> adj) 
	{
	    int v = V;
	    vector<int> indegree(v,0);
        vector<int> vis(v,0);
        vector<int> topo;
    
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
   
    string findOrder(string dict[], int N, int K) 
    {
        vector<vector<int>> adj(K);
        
        for(int i=0;i<N-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int ix = firstNonMatchingChar(s1,s2);
            if(ix != min(s1.length(), s2.length()))
            adj[s1[ix]-'a'].push_back(s2[ix]-'a');
        }
    
        vector<int> topo = topoSort(K, adj);
    
        string s = "";
        
        for(int i=0;i<topo.size();i++)
        {
            s += (char)(topo[i] + 'a');
        }
    
        return s;
    }
};