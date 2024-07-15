#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char, int>> st;
        
        for (char c : s) 
        {
            if (!st.empty() && st.top().first == c) 
            {
                st.top().second++;
            } 
            else 
            {
                st.push({c, 1});
            }

            if (st.top().second == k) 
            {
                st.pop();
            }
        }

        string result = "";

        while (!st.empty()) 
        {
            auto it = st.top();
            st.pop();
            result.append(it.second, it.first); // STL !
        }

        reverse(result.begin(), result.end());

        return result;
    }
};