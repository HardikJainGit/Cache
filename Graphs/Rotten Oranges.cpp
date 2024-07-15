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

// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        
        int n = grid.size(); //n*m
	    int m = grid[0].size(); 

	    vvi vis(n, vector<int>(m, 0)); 
	    vvi dist(n, vector<int>(m, 0)); 

	    int fresh = 0;
	    queue<pi> q; 

	    f(n)
        {
	        fz(j,0,m)
            {
	            if(grid[i][j] == 2) 
                {
	                q.push({i,j}); // multi source BFS
	                vis[i][j] = 1; 
	            }
	            else if(grid[i][j] == 1)
                {
                    fresh += 1;
	                vis[i][j] = 0; 
	            }
	        }
	    }

        if(fresh == 0)
        {
            return 0;
        }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 

        int count = -1;
	    
	    while(!q.empty()) 
        {
	        int size = sz(q);

           fz(k,0,size)
           {
                int row = q.front().ff;
	            int col = q.front().ss; 
                q.pop();

                f(4) 
                {
                    int nrow = row + delrow[i]; 
                    int ncol = col + delcol[i]; 
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) 
                    {
                        vis[nrow][ncol] = 1; 
                        fresh -= 1;
                        q.push({nrow, ncol});  
                    }
                }
            }
                
            count += 1;

	    }

        if(fresh > 0)
        {
            return -1;
        }

	    return count; 
    }   
};