#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution{
    public:
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
        sort(dep,dep+n);
     
        int ans=1;
        int count=1;
        int i=1;
        int j=0;

        // 2 pointers
        
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j]) //one more platform needed
            {
                count++;
                i++;
            }
            else //one platform can be reduced since a train leaves
            {
                count--;
                j++;
            }

            // at any possible instance get the maximum platforms reqd
            ans=max(ans,count); //updating the value with the current maximum
        }
        return ans;
    }
};