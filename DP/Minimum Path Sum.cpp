#include<bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define vvi vector<vector<int>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> dp(r,vi(c,0));

        // dp[i][j] is current sum at cell i,j

        dp[0][0] = grid[0][0];

        fz(i,0,r)
        {
            fz(j,0,c)
            {
                if(!i && !j)
                {
                    continue;
                }

                if (i == 0) 
                dp[0][j] = grid[0][j] + dp[0][j - 1];

                else if (j == 0) 
                dp[i][0] = grid[i][0] + dp[i - 1][0];

                else 
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[r-1][c-1];
    }
};