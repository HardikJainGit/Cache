#include <bits/stdc++.h>
using namespace std;

#define vi vector<string>
#define vvi vector<vector<string>>
#define vvvi vector<vector<vi>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool is_p(string s) 
    {
        string rev = s;
        reverse(s.begin(),s.end());
        return s == rev;
    }
    void dfs(int i , vi& cur , vvi &ret , string &s)
    {                
        if(i >= s.length())
        {
            ret.pb(cur);
            return;
        }
        
        fz(j,i,s.length())
        {
            if(is_p(s.substr(i,j-i+1)))
            {
                cur.pb(s.substr(i,j-i+1));
                dfs(j+1,cur,ret,s);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vvi ret;
        vi cur;
        dfs(0,cur,ret,s);
        return ret;
    }
};