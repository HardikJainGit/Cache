#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/rod-cutting-problem_800284

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
	vector<int> weight(n,0);

    // if nothing is given then weights array is generated like this

	for(int i=0;i<n;i++)
	{
		weight[i] = i + 1;
	}

	for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if (j - weight[i-1] >=0)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j - weight[i-1]] + price[i-1]);
                } 
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][n];
}
