#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557

bool condition(vector<int> &boards , int k,int time)
{
    int painter_count = 1;
    int current = 0;
    for(int i=0;i<boards.size();i++)
    {
        if(boards[i]>time)
        {
            return false;
        }
        if(current+boards[i] > time)
        {
            painter_count+=1;
            current = boards[i];
        }
        else
        {
            current+=boards[i];
        }
    }
    return painter_count <= k; //false means time should be increased
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int sum = 0;
    for(int  i =0 ; i<n;i++)
    {
        sum+=boards[i];
    }
    int lo = -1; 
    int hi = 1e9;
    int mid = 0;

    while (hi-lo>1) 
    {
        mid = lo + (hi - lo) / 2;

        if (condition( boards, k,mid)) 
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