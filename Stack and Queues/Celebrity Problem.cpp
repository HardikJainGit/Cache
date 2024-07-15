#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack <int> s;
        for (int i = 0; i < n; i++)
        s.push(i);
        
        while (s.size() >= 2) 
        {
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            if (M[A][B]) 
            {
                s.push(B); //A knows B remove A
            }
            else 
            {
                s.push(A); // B is not known remove B
            }
        }
        int C = s.top();
        s.pop();
        
        for (int i = 0; i < n; i++) 
        {
            if (i!=C && (M[C][i] || !M[i][C]))
            {
                return -1;
            }
        }
        
        return C;
    }
};