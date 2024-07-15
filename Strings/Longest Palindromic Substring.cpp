#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {

        // this should be contiguous it is a substring not a subsequence !
        string res = "";
        int resLen = 0;

        int n = s.length();

        int l = 0;
        int r = 0;

        int lf = 0;
        int rf = 0;

        for(int i=0;i<n;i++)
        {
            l = i; //take center as i and expand outwards
            r = i;
            while(r<n && l>=0 && s[l] == s[r])
            {
                if(r-l+1 > resLen)
                {
                    resLen = r-l+1;
                    rf = r;
                    lf = l;
                }
                l -= 1;
                r += 1;
            }

            // even length
            l = i; 
            r = i + 1;
            while(r<n && l>=0 && s[l] == s[r])
            {
                if(r-l+1 > resLen)
                {
                    resLen = r-l+1;
                    rf = r;
                    lf = l;
                }
                l -= 1;
                r += 1;
            }
        }
        return s.substr(lf,resLen);
    }
};