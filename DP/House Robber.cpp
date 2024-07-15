#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector <int> dp(nums.size(),0);
        int n=nums.size();

        if (n == 0) 
        {
            return 0;
        } 
        else if (n == 1) 
        {
            return nums[0];
        }
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
    
        for (int i = 2; i < nums.size(); i++) 
        {
           dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }

        return dp[nums.size()-1];
    }
};