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

// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int mx = 0;
        int cc = 0;

        f(sz(nums))
        {
            if(nums[i])
            {
                cc += 1;
                mx = max(mx, cc);
            }
            else
            {
                cc = 0;
            }
        }

        return mx;
    }
};