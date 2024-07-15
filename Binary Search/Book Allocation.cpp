#include<bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/allocate-books/

bool condition(int pages, vector<int> &A, int B)
{
    int student_count = 1;
    int current_sum = 0;

    for (int i = 0; i < A.size(); i++)
    {
        // as each student has to read min one book
        if(A[i]>pages)
        {
            return false;
        }
        
        if (A[i] + current_sum > pages)
        {
            student_count += 1;
            current_sum = A[i];
        }
        else
        {
            current_sum += A[i];
        }
    }

    return student_count <= B;
}

int books(vector<int> &A, int B) {
    
    if (B > A.size()) 
    {
        return -1;
    }

    int sum = 0;

    for (int i = 0; i < A.size(); i++) 
    {
        sum += A[i];
    }

    int lo = -1; 
    int hi = sum;
    int mid = 0;

    while (hi-lo>1) 
    {
        mid = lo + (hi - lo) / 2;

        if (condition(mid, A, B)) 
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