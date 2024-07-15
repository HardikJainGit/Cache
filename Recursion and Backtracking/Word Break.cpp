#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-break-ii/

class Solution {
public: 
    void dfs(int i, string s, vector<string> &wordDict, vector<string> &res,vector <string> &cur)
    {
        if (i == s.length())
        {
            string ret = "";
            for (auto it : cur) 
            {
                ret += it;
                ret += " ";
            }   
            ret.pop_back();
            res.push_back(ret);
            return;
        }
        for (int j = i; j < s.length(); j++)
        {
            string w = s.substr(i, j - i + 1);
            if (find(wordDict.begin(), wordDict.end(), w) != wordDict.end())
            {
                cur.push_back(w);
                dfs(j + 1, s, wordDict, res,cur);
                cur.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector <string> res;
        vector <string> cur;
        dfs(0,s,wordDict,res,cur);
        return res;
    }
};