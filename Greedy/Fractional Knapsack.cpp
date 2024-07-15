#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

struct Item{
    int value;
    int weight;
};

class Solution {
  public:
  
    static bool compareSort(Item a, Item b) 
    {
        return ((double)a.value / a.weight) > ((double)b.value / b.weight);
    }    
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        
        sort(arr,arr+n,compareSort);
        double ans= 0.0;
        int cw = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            if(cw+arr[i].weight<=w)
            {
                ans += arr[i].value;    
                cw += arr[i].weight;
            }
            else
            {
                ans += arr[i].value * ((double)(w - cw) / arr[i].weight);
                break;
            }
        }
        
        return ans;
        
    }
};
