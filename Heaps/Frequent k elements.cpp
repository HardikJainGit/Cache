#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int,int> m;
        priority_queue <pair<int,int>> q;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] += 1;
        }

        for (auto it : m)
        {
            q.push({it.second, it.first});
        }

        vector<int> v;
        
        while(v.size() < k)
        {
            auto it = q.top();
            q.pop();
            v.push_back(it.second);
        }
        
        return v;
    }
};