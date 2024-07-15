#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // https://www.youtube.com/watch?v=Sx9NNgInc3A

        // dp[i] is whether word starting from index i is found in wordDict

        vector<int> dp(s.length() + 1 , 0);

        // dp[last index] = true
        dp[s.length()] = 1;

        for(int i=s.length();i>=0;i--)  // iterate from back as top down
        {
            for(auto it : wordDict)
            {
                if(dp[i]) // caching dp on indexes to reduce computation
                {
                    break;
                }
                if(it.length() + i <= s.length() && s.substr(i,it.length()) == it)
                {
                    dp[i] = dp[i+it.length()];
                }
            }
        }

        return dp[0];
    }
};