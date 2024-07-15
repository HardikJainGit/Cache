#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subsets/

class Solution {
public:
    void dfs(int i, vector<int>& subz, vector<int>& nums, int n, vector<vector<int>>& ret) 
    {
        if(i == n)
        {
            ret.push_back(subz);
            return;
        }

        // include nums[i]

        subz.push_back(nums[i]);
        dfs(i + 1 , subz , nums , n , ret);

        // dont include nums[i]

        subz.pop_back();
        dfs(i + 1 , subz , nums , n , ret);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        vector<int> subz;
        dfs(0, subz, nums, nums.size(), ret);
        return ret;
    }
};

// if nums has duplicates :

class Solution {
public:
    void dfs(int i, vector<int>& subz, vector<int>& nums, int n, vector<vector<int>>& ret) 
    {
        if(i == n)
        {
            ret.push_back(subz);
            return;
        }

        // include

        subz.push_back(nums[i]);
        dfs(i + 1 , subz , nums , n , ret);

        // exclude nums[i] & its duplicates

        subz.pop_back();

        // remove duplicates if they exist for nums[i]

        while(i + 1 < n && nums[i] == nums[i+1])
        {
            i += 1;
        }
        
        dfs(i + 1 , subz , nums , n , ret);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());  
        vector<int> subz;
        dfs(0, subz, nums, nums.size(), ret);
        return ret;
    }
};
