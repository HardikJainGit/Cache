#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    MedianFinder() 
    {

    }

    priority_queue<int> mx; // Max heap
    priority_queue<int, vector<int>, greater<int>> mi; 

    void addNum(int num) 
    {
        if (mx.empty() || num <= mx.top()) 
        {
            mx.push(num);
        } 
        else 
        {
            mi.push(num); // If a number is greater than mx.top then it goes to mi
        }
        
        // Remove the largest element from mx add to mi since all elements in mi >= mx

        if (mx.size() > mi.size() + 1) 
        {
            mi.push(mx.top());
            mx.pop();
        } 

        else if (mi.size() > mx.size()) 
        {
            mx.push(mi.top());
            mi.pop();
        }
    }

    double findMedian() 
    {
        if (mx.size() == mi.size()) 
        {
            return (mx.top() + mi.top()) / 2.0;
        } 
        else 
        {
            if(mx.size() > mi.size())
            {
                return mx.top();
            }
            else
            {
                return mi.top();
            }
        }
    }
};
