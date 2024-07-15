#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/smallest-number-subset1220/0

class Solution{   
public:
    long long findSmallest(long long arr[], int n) {
         long long cur = 0;
         for(long long i=0;i<n;i++)
         {
             if(arr[i] > cur + 1) // Exploit the gap cur + 1 cannot be represented as a subset sum
             {
                return cur + 1;
             }
             cur += arr[i];
         }
         return cur + 1;
    }
};