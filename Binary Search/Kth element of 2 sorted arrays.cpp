#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution{
    
    public:
    
    int kthElement(int a[], int b[], int n1, int n2, int k){
        
        if(n1 > n2) return kthElement(b, a, n2, n1, k);
        int s = max(0, k - n2) - 1, e = min(k, n1) + 1;
        int left = k;
        while(s < e){
        
            int mid1 = (s + e) / 2;
            int l1 = -1e9, l2 = -1e9;
            int r1 = 1e9, r2 = 1e9;
            int mid2 = left - mid1;
            
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
            
            if(l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            
            // Eliminate right half
            else if(l1 > r2) e = mid1;
            
            // Eliminate left half
            else s = mid1;
            
        }
        
        return 0;
        
    }
};