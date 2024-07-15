#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int mx = INT_MIN;

        for(int i=0; i < prices.size(); i++)
        {
            mi = min(mi, prices[i]);
            mx = max(prices[i]-mi, mx);
        }

        return mx;
    }
};