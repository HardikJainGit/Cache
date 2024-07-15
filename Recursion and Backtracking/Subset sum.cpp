#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
  public:
    void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) 
    {
      if (ind == n) 
      {
        ans.push_back(sum);
        return;
      }

    //   pick
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);

    //   not pick
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    // sort(ans.begin(), ans.end());
    return ans;
  }
};