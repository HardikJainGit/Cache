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

class Solution {
public:
    void Kahn(int i , vector<int> &topo, vvi adj, vector<int> &indegree, vector<int> &vis) 
    {
        queue<int> q;

        // if(indegree[i] == 0 && !vis[i])
        // {
        //     q.push(i);
        //     vis[i] = 1;
        // }
    
        q.push(i);

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
    
	vector<int> topoSort(int V, vvi adj) 
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vvi adj(numCourses);
        f(sz(prerequisites))
        {
            adj[prerequisites[i][1]].pb(prerequisites[i][0]);
        }

        vector<int> topo = topoSort(numCourses, adj);
        
        return sz(topo) == numCourses;
    }
};

// Topo sort DFS :

class Solution
{
	public:
	void dfs(int v,vector<bool> &visited,vector <int> &topo, vector<int> adj[]) 
	{
        visited[v] = true;

        for (int u : adj[v]) 
        {
            if (!visited[u])
            {
                dfs(u,visited,topo,adj);
            }
        }
        topo.push_back(v);
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V,false);
        vector<int> topo_v;
        vector<int> topo;
        for (int i = 0; i < V; ++i) 
        {
            if (!visited[i])
            {
                dfs(i, visited, topo, adj);
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
	}
};

// DFS

bool isCyclicDFS(vvi adj, vector<int> &vis, vector<int> &vis_dfs, int Node) 
{
    vis[Node] = 1;
    vis_dfs[Node] = 1;

    for(int x : adj[Node]) 
    {
        if(!vis[x]) 
        {
            if(isCyclicDFS(adj, vis, vis_dfs, x)) 
            {
                return true;
            }
        } 
        else if(vis_dfs[x]) 
        {
            return true; //vis true and dfs vis also true
        }
    }

    vis_dfs[Node] = 0; //while returning back mark dfs vis false
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vvi adj(numCourses);
        int v = numCourses;
        
        f(sz(prerequisites))
        {
            adj[prerequisites[i][0]].pb(prerequisites[i][1]);
        }

        vi vis(v,0);
        vi dfs_v(v,0);

        for(int i=0; i<v; i++) 
        {
            if(!vis[i]) 
            {
                int ans = isCyclicDFS(adj, vis, dfs_v, i);

                if(ans) 
                {
                    return false;
                }
            }
        }
        return true;
    }
};
