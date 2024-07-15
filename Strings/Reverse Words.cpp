#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) 
    {
        reverse(s.begin(),s.end());

        int n=s.size();
        int left=0;
        int right=0;
        int i=0;

        while(i<n)
        {
            while(i<n && s[i]==' ')
            i++; //skip spaces

            if(i==n)
            break; 

            // start appending to right

            while(i<n && s[i]!=' ')
            {
                s[right++]=s[i++];
            }

            reverse(s.begin()+left,s.begin()+right);

            // Add separator between words

            s[right++]=' ';

            // Update left

            left=right;
        }

        s.resize(right-1);
        return s;
    }
};