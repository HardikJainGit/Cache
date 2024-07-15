#include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
        vector<vector<int>> dp(n+1 , vector<int>(w+1,0));

        // The reason for using weights[i-1] and values[i-1] is to account for the
        // fact that i is starting from 1 in the loop, 
        // whereas the vectors values and weights are 0-indexed. 

        // i is item j is wt dp is total weight
    
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                if (j - weights[i-1] >=0) // pick non pick
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]] + values[i-1]);

                    // unbounded :
                    // dp[i][j] = max(dp[i-1][j], dp[i][j - weight[i-1]] + profit[i-1]);
                } 
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][w];
}