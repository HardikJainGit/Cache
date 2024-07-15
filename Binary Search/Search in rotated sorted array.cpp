#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        //Finding Pivot :

        int lo = -1;
        int n = nums.size();
        int hi = nums.size();
        int mid = 0;
        
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
    
            if (nums[mid]>=nums[0]) //MAIN LINE OF CODE
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }

        int pivot = nums[hi];

        if(hi==n)
        {
            pivot=nums[0];
            hi=0;
        }
        ////
        cout<<pivot;
        
        int lo2 = hi;
        int hi2 = n-1;
        int mid2 = 0;
        
        while (hi2 - lo2 > 1)
        {
            mid2 = (hi2 + lo2) / 2;
    
            if (nums[mid2]>target)
            {
                hi2 = mid2;
            }
            else
            {
                lo2 = mid2;
            }
        }

        if(nums[lo2]==target)
        {
            return lo2;
        }
        else if(nums[hi2]==target)
        {
            return hi2;
        }

        int lo3 = 0;
        int hi3 = hi-1;
        int mid3 = 0;
        cout<<hi3;
        
        while (hi3 - lo3 > 1)
        {
            mid3 = (hi3 + lo3) / 2;

            if (nums[mid3]>target)
            {
                hi3 = mid3;
            }
            else
            {
                lo3 = mid3;
            }
        }

        cout<<" lo3 "<<lo3<< " "<<hi3;

        if(nums[lo3]==target)
        {
            return lo3;
        }
        else if(hi3>=0 && hi3<n && nums[hi3]==target)
        {
            return hi3;
        }

        return -1;
    }
};

// Leverage that atleast one subpart is sorted

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int mid = 0;

        while (hi-lo>1) {

            mid = lo + (hi - lo) / 2;

            if (nums[lo] <= nums[mid])  //[lo,mid] is sorted
            {
                if (target >= nums[lo] && target <= nums[mid]) 
                {
                    hi = mid;
                } 
                else 
                {
                    lo = mid;
                }
            } 
            else 
            {
                //[lo,mid] is not sorted -> [mid,hi] is sorted
                if (target >= nums[mid] && target <= nums[hi]) 
                {
                    lo = mid;
                } 
                else 
                {
                    hi = mid;
                }
            }
        }

        if(nums[hi] == target)
        {
            return hi;
        }
        else if(nums[lo] == target)
        {
            return lo;
        }

        return -1;
    }
};
