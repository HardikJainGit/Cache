#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) 
        {
            if (ch == '(' || ch == '[' || ch == '{') 
            {
                st.push(ch);
            } 
            else 
            {
                if (st.empty()) 
                {
                    return false; // More closing than opening parentheses
                }

                char top = st.top();
                st.pop(); // popping for closing ones

                if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) 
                {
                    return false; // Mismatched opening and closing parentheses
                }
            }
        }
        return st.empty(); // for edge case like "["
    }
};
