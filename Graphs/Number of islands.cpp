#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/number-of-islands/

// DFS DSU

#define vi vector <int>
#define vvi vector<vector<int>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())

class Solution {
public:
    struct DSU
    {
        int n;
        vi p;
        DSU(int n)
        {
            p.assign(n + 1,0);
            fz(i,1,n+1)
                p[i] = i;
        }
        int par(int i)
        {
            if (p[i] == i)
                return i;
            return p[i] = par(p[i]);
        }
        void un(int u,int v)
        {
            u = par(u),v = par(v);
            if(u==v) return;
            p[v] = u;
        }
    };  

    void dfs(int nr , int nc ,vector<vector<char>> &grid , vvi &vis,DSU &dsu)
    {
        int r = sz(grid);
        int c = sz(grid[0]);

        if (nr < 0 || nc < 0 || nr >= r || nc >= c || vis[nr][nc] || grid[nr][nc] == '0')
        {
            return;
        }

        vis[nr][nc] = 1;
        int i = nr; int j = nc;
        
        if (i + 1 < r && grid[i + 1][j] == '1') dsu.un(i * c + j, (i + 1) * c + j);
        if (j + 1 < c && grid[i][j + 1] == '1') dsu.un(i * c + j, i * c + (j + 1));
        if (i - 1 >= 0 && grid[i - 1][j] == '1') dsu.un(i * c + j, (i - 1) * c + j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dsu.un(i * c + j, i * c + (j - 1));

        dfs(i+1,j,grid,vis, dsu);
        dfs(i,j+1,grid,vis, dsu);
        dfs(i-1,j,grid,vis, dsu);
        dfs(i,j-1,grid,vis, dsu);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
        {
            return 0;
        }

        int r = sz(grid);
        int c = sz(grid[0]);
        DSU dsu(r * c + c + 1);

        vvi vis(r,vi(c,0));

        f(r)
        {
            fz(j,0,c)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    // isl += 1; //
                    dfs(i,j,grid,vis,dsu);
                }
            }
        }

        unordered_set<int> uniqueIslands;
        
        fz(i, 0, r) 
        {
            fz(j, 0, c) 
            {
                if (grid[i][j] == '1')
                {
                    uniqueIslands.insert(dsu.par(i * c + j));
                }
            }
        }

        return uniqueIslands.size();

        // return isl;
    }
};

// BFS DSU

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

struct DSU
{
    int n;
    vi p;
    DSU(int n)
    {
        p.assign(n + 1,0);
        fz(i,1,n+1)
            p[i] = i;
    }
    int par(int i)
    {
        if (p[i] == i)
            return i;
        return p[i] = par(p[i]);
    }
    void un(int u,int v)
    {
        u = par(u),v = par(v);
        if(u==v) return;
        p[v] = u;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
        {
            return 0;
        }

        int r = sz(grid);
        int c = sz(grid[0]);
        vi vis(r * c + 1,0);

        DSU dsu(r * c);
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        f(r) 
        {
            fz(j, 0, c) 
            {
                if (grid[i][j] == '1') 
                {
                    fz(k, 0, 4) 
                    {
                        int nr = i + delRow[k], nc = j + delCol[k];
                        if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == '1') 
                        {
                            dsu.un(i * c + j, nr * c + nc);
                        }
                    }
                }
            }
            
        }

        int isl = 0;

        unordered_set<int> uniqueIslands;

        // Use set if don't want to be bothered by unifying zeroes

        fz(i, 0, r) 
        {
            fz(j, 0, c) 
            {
                if (grid[i][j] == '1')
                {
                    uniqueIslands.insert(dsu.par(i * c + j));
                }
            }
        }

        return uniqueIslands.size();
    }
};

// DFS


class Solution {
public:

    void dfs(int nr , int nc ,vector<vector<char>> &grid , vvi &vis)
    {
        int r = sz(grid);
        int c = sz(grid[0]);

        if (nr < 0 || nc < 0 || nr >= r || nc >= c || vis[nr][nc] || grid[nr][nc] == '0')
        {
            return;
        }

        vis[nr][nc] = 1;

        int i = nr; int j = nc;

        dfs(i+1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j-1,grid,vis);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
        {
            return 0;
        }

        int r = sz(grid);
        int c = sz(grid[0]);

        int isl = 0;
        vvi vis(r,vi(c,0));

        f(r)
        {
            fz(j,0,c)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    isl += 1;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return isl;
    }
};

