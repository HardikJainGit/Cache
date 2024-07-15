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

// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = sz(height);
        vi left(n,0);
        vi right(n,0);

        int lmx = INT_MIN;
        int rmx = INT_MIN;

        f(n)
        {
            lmx = max(lmx,height[i]);
            left[i] = lmx;
        }
        
        // debug(left);

        for(int i=n-1;i>=0;i--)
        {
            rmx = max(rmx,height[i]);
            right[i] = rmx;
        }

        // debug(right);

        int water = 0;

        f(n)
        {
            water += min (left[i],right[i]) - height[i];
        }

        return water;
    }
};