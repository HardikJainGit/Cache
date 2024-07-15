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

// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = sz(nums);
        int sum = 0;
        int mx = INT_MIN;

        f(n)
        {
            sum += nums[i];
            if(sum > mx)
            {
                mx = max(mx, sum);
            }

            // Main part of the algorithm

            if(sum < 0)
            {
                sum = 0;
            }
        }

        return mx;
    }
};