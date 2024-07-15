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

// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int r = sz(mat);
        int c = sz(mat[0]);
        vvi dp(r,vi(c,INT_MAX));
        vvi vis(r,vi(c,0));
        queue <pair<int,int>> q;
        
        f(r)
        {
            fz(j,0,c)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                    dp[i][j] = 0;
                }
            }
        }
        

        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 

        int temp = 0;
	    
	    while(!q.empty()) 
        {

                int row = q.front().ff;
	            int col = q.front().ss; 
                q.pop();

                f(4) 
                {
                    int nrow = row + delrow[i]; 
                    int ncol = col + delcol[i]; 
                    
                    if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && !vis[nrow][ncol] && mat[nrow][ncol]) 
                    {
                        if (dp[nrow][ncol] > dp[row][col] + 1) 
                        {
                            dp[nrow][ncol] = dp[row][col] + 1;
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
              }
	    }

        return dp;
    }
};