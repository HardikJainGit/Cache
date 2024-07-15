#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int maxLen = 0;
        unordered_map<int, int> m;
        int sum = 0;
    
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];

            // if sum is zero check if its the ans
            
            if (sum == 0) 
            {
                maxLen = max(maxLen,i + 1);
            } 

            // check if sum already present ans is i - m[sum]
            
            else if (m.find(sum) != m.end()) 
            {
                maxLen = max(maxLen, i - m[sum]);
            } 
            
            else
            {
                // update the entry for the current sum if nothing matches

                m[sum]=i;
            }       
        }
        
        if(sum==0)
        {
            return A.size();
        }

    return maxLen;
    }
};