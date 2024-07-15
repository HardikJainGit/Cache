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

// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    
    // https://www.youtube.com/watch?v=cjWnW0hdF1Y

    int lengthOfLIS(vector<int>& nums) 
    {
        if(!nums.size())
        {
            return 0;
        }

        // dp[i] is LIS that ends at ith index

        vector <int> dp (nums.size() , 1); // each character is a LIS
        

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j]) // compare i with all before it 
                {
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin() , dp.end());

    }
};

// no of LIS

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(!nums.size())
        {
            return 0;
        }

        // dp[i] is LIS that ends at ith index
        // all dp[i]s are 1 initially

        vector <int> dp (nums.size() , 1);
        vector <int> count (nums.size() , 1);

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    if (dp[i] < dp[j] + 1) 
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // Reset count[i] because we found a longer LIS
                    }
                    else if (dp[i] == dp[j] + 1) 
                    {
                        count[i] += count[j]; // Increment count[i] because we found another LIS of the same length
                    }
                }
            }
        }

        int oc = *max_element(dp.begin() , dp.end());
        int c = 0;

        for(int i=0;i<dp.size();i++)
        {
            if(dp[i] == oc)
            {
                c += count[i];
            }
        }

        return c;
    }
};

// Maximum sum increasing subsequence 

// https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    if(!n)
        {
            return 0;
        }

        // dp[i] is LIS that ends at ith index

        vector <int> dp (n);
        
        for(int i=0;i<n;i++)
        {
            dp[i] = arr[i]; // base case
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i] > arr[j])
                {
                    dp[i] = max(dp[i] , dp[j] + arr[i]);
                }
            }
        }

        return *max_element(dp.begin() , dp.end());
	}  
};