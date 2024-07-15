#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        // can store the count and then arrange on basis of that 

        int n = nums.size();
        int low = 0, mid = 0, high = n - 1; // 3 pointers

        while (mid <= high) 
        {
            if (nums[mid] == 0) 
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) 
            {
                mid++;
            }
            else 
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};