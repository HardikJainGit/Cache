#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/min-stack/

class MinStack {
public:

    stack < pair<int,int>> st;

    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        if(st.empty())
        {
            pair<int,int> p;
            p.first=val;
            p.second=val;
            st.push(p);
        } 
        else
        {
            pair<int,int> p;
            p.first=val;
            p.second=min(val,st.top().second); 
            st.push(p);
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};