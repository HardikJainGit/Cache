#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = -1;
        int n = nums.size();
        int mid = 0;
        int hi = n;

        if(nums.size()==1)
        {
            return nums[0];
        }
        
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
    
            if (((mid % 2 == 0 and nums[mid] == nums[mid+1]) || (mid%2 == 1 and nums[mid] == nums[mid-1])))
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        
        return nums[hi];
    }
};