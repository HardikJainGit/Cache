#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
        if(!arr.size())
        {
            return false;
        }

        vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1,false));
        
        for(int i=0;i<arr.size();i++)
        {
            dp[i][0] = true; // 0 sum for all elements is possible; dont pick
        }
        
        if(arr[0]<=sum)
        {
            dp[0][arr[0]] = true; // arr[0] is possible with one element
        }
        
        for(int i=1;i<arr.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=arr[i])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]]; // pick non pick
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[arr.size()-1][sum]; // no of elements (pool) & sum desired
    }

    bool isSubsetSum_r(vector<int>arr,int no , int sum)
    {
        if(!arr.size())
        {
            return false;
        }

        if(no<0)
        {
            return false;
        }

        if(sum == 0)
        {
            return true;
        }

        if(sum>=arr[no])
        {
            return isSubsetSum_r(arr,no-1,sum) || isSubsetSum_r(arr,no-1,sum-arr[no]);
        }
        else
        {
            return isSubsetSum_r(arr,no-1,sum);
        }
    }

    bool isSubsetSum_r_memo(vector<int>arr,int no , int sum)
    {
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));

        if(sum == 0)
        {
            return true;
        }
        
        if(no<0 || sum<0)
        {
            return false;
        }

        if(dp[no][sum] != -1)
        {
            return dp[no][sum];
        }

        if(sum == 0)
        {
            return true;
        }

        if(sum>=arr[no])
        {
            return dp[no][sum] = isSubsetSum_r_memo(arr,no-1,sum) || isSubsetSum_r_memo(arr,no-1,sum-arr[no]);
        }
        else
        {
            return dp[no][sum] = isSubsetSum_r_memo(arr,no-1,sum);
        }
    }

    bool isSubsetSum_space_opt(vector<int>arr, int sum)
    {
        if(!arr.size())
        {
            return false;
        }

        // vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1,false));

        vector<bool> cur(sum + 1);
        vector<bool> next(sum + 1);

        // for(int i=0;i<arr.size();i++)
        // {
        //     dp[i][0] = true;
        // }

        cur[0] = true;
        next[0] = true;
        
        // if(arr[0]<=sum)
        // {
        //     dp[0][arr[0]] = true;
        // }

        if(arr[0]<=sum)
        {
            cur[arr[0]] = true;
        }
        
        for(int i=1;i<arr.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=arr[i])
                    // dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
                    next[j] = cur[j] || cur[j-arr[i]];
                else
                    // dp[i][j] = dp[i-1][j];
                    next[j] = cur[j];
            }
            cur = next;
        }
        
        return next[sum];
    }
    

    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum%2)
        {
            return false;
        }
        else
        {
            return isSubsetSum_space_opt(nums,sum/2);
        }
    }
};

// Number of subsets with sum k

#include <vector>
using namespace std;

// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM

// For repeated elements accepted : 

const int MOD = 1'000'000'007;

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) {
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case: there's one way to make sum 0 (by selecting no elements)
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Base case: if the first element is within the sum, it can form a subset
    for (int i = 1; i <= k; i++) {
        if (i % arr[0] == 0) {
            dp[0][i] = 1; // base 0 indexing meaning sum of i can be formed with the first element used multiple times
        }
    }

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i]) {
                dp[i][j] = (dp[i][j] + dp[i][j - arr[i]]) % MOD;
                // dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]]; i used in place of i-1 since multiple can be used
            }
        }
    }

    return dp[n - 1][k];
}
