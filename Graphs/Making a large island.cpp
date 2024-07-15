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

// https://leetcode.com/problems/making-a-large-island/description/

struct DSU
{
    int n;
    vi p, size;
    DSU(int n)
    {
        p.assign(n, 0);
        size.resize(n, 1);
        f(n)
        {
            p[i] = i;
            size[i] = 1;    
        }
    }
    int par(int i)
    {
        if (p[i] == i)
            return i;
        return p[i] = par(p[i]);
    }
    void un(int u, int v)
    {
        u = par(u), v = par(v);
        if (u == v) return;
        if (size[u] < size[v]) swap(u, v);
        p[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        if (grid.empty())
        {
            return 0;
        }
        
        int r = sz(grid);
        int c = sz(grid[0]);
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
                
        DSU dsu(r * c);

        f(r) 
        {
            fz(j, 0, c) 
            {
                if (grid[i][j] == 1) 
                {
                    fz(k, 0, 4) 
                    {
                        int nr = i + delRow[k], nc = j + delCol[k];
                        if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == 1) 
                        {
                            dsu.un(i * c + j, nr * c + nc);
                        }
                    }
                }
            }
        }

        unordered_set<int> uniqueIslands;

        fz(i, 0, r) 
        {
            fz(j, 0, c) 
            {
                if (grid[i][j] == 1)
                {
                    uniqueIslands.insert(dsu.par(i * c + j));
                }
            }
        }

        int isl = 0;

        for (int root : uniqueIslands) 
        {
            isl = max(isl, dsu.size[root]);
        }

        int mx = isl; // largest island before 'swap' in case no swaps happen

        f(r) 
        {
            fz(j, 0, c) 
            {
                set<int> mos;
                
                // Consider all zeroes for getting maximal profit swap

                if (grid[i][j] == 0) 
                {
                    fz(k, 0, 4) 
                    {
                        int nr = i + delRow[k], nc = j + delCol[k];
                        if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == 1) 
                        {
                            mos.insert(dsu.par(nr * c + nc)); // store parents in set to avoid duplicates`
                        }
                    }
                    int hwa = 1; // Include the cell being flipped
                    for (int it : mos)
                    {
                        hwa += dsu.size[it];
                    }
                    mx = max(mx, hwa);
                }
            }
        }

        return mx;
    }
};
