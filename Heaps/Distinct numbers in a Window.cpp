#include<bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> dNums(vector<int> &A, int B) 
{
    vector <int> v;
    unordered_map <int,int> m;
    for(int i = 0 ; i < B ; i++)
    {
        m[A[i]] += 1;
    }
    v.push_back(m.size());
    for(int i = B ; i < A.size() ; i++)
    {
        if(m[A[i - B]] == 1)
        {
            m.erase(A[i - B]);
        }
        else
        {
            m[A[i - B]] -= 1;
        }
        m[A[i]] += 1;
        v.push_back(m.size());
    }
    return v;
}
