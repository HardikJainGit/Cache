#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change/
// https://leetcode.com/problems/coin-change-ii/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int w = amount;
        int n = coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(w+1,0));

        // no coins reqd for 0 amount

        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
            // dp[i][0] = 1 if no of ways asked
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                if (j - coins[i-1] >=0)
                {
                    dp[i][j] = min(dp[i][j - coins[i-1]] + 1, dp[i-1][j]); // unbounded knapsack 
                    
                    // if ways asked :
                    // dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                } 
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][w];
    }
};