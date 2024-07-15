#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    double median(vector<int>& a, vector<int>& b) 
    {
        int n1 = a.size(), n2 = b.size();
        if (n1 > n2) return median(b, a);

        int n = n1 + n2; 
        int left = (n1 + n2 + 1) / 2; 
        
        int lo = -1, hi = n1+1;
        while (lo < hi) 
        {
            int mid1 = (lo + hi) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1) r1 = a[mid1];
            if (mid2 < n2) r2 = b[mid2];
            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) 
            {
                if (n % 2 == 1) return max(l1, l2);
                else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            else if (l1 > r2) 
                hi = mid1;
            else 
                lo = mid1;
        }
        return 0; 
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        return median(nums1,nums2);
    }
};