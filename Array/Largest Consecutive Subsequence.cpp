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

// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = INT_MIN;

        if(!sz(nums))
        {
            return 0;
        }

        //map <int,int> vis;
        unordered_set<int> st;
        //put all the array elements into set:
        f(sz(nums)){
            st.insert(nums[i]);
        }

        f(sz(nums))
        {
            // create a new entry
            if(st.find(nums[i]-1)==st.end()) //first number
            {
                int count = 1;
                int starting = nums[i];
                while(st.find(starting+1)!=st.end())
                {
                    count+=1;
                    starting+=1;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};

