#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {

        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow]; //x1
        fast = nums[nums[fast]]; //x2
        
        while (slow != fast)
        {
            slow = nums[slow]; //x1
            fast = nums[nums[fast]]; //x2
        }
        
        fast = nums[0]; // or slow at start whatever

        while (slow != fast) {
            //both x1
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};