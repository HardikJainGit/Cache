#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/repeated-string-match/

class Solution {
public:
    
    // BTS of stl :

    bool check(string &a, string &b)
    {
        int m=a.size();
        int n=b.size();
        int j = -1;
        
        for(int i=0;i<=m-n;i++) //Start from i and check all substrings of length n
        {
            for(j=0;j<n;j++)
            {
                if(a[i+j]!=b[j])
                break; //go to next i
            }
            if(j==n)
            return true;
        }
        return false;
    }


    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string s = a;
        
        while(!check(a,b) && a.length() < b.length())
        {
            a += s;
            count += 1;
        }
        if(check(a,b))
        {
            return count + 1;
        }
        a += s;
        count += 1;
        if(check(a,b))
        {
            return count + 1;
        }
        return -1;
    }
};

// STL

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string s = a;
        
        while(a.length() < b.length())
        {
            a += s;
            count += 1;
        }
        if(a.find(b) != string::npos)
        {
            return count + 1;
        }
        a += s;
        count += 1;
        if(a.find(b) != string::npos)
        {
            return count + 1;
        }
        return -1;
    }
};