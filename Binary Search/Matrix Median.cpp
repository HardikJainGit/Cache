#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix

class Solution{   
public:

    bool condition(vector<vector<int>> matrix,int mid)
    {   
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++)
        {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return cnt > (n * m) / 2;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int r = matrix.size();
        int c = matrix[0].size();      
        
        int lo = -1;
        int hi = 1e9;
        int mid = 0;
        
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
    
            if (condition(matrix,mid)) 
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }   

        return hi;
    }
};