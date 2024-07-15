#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vi>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void dfs(int i , vi& cur , vvi &ret , int &target , int tot, vi &candidates)
    {                
        if(tot == target)
        {
            ret.pb(cur);
            return;
        }

        if(i >= sz(candidates) || tot > target)
        {
            return;
        }

        // Pick

        cur.pb(candidates[i]);
        dfs(i,cur,ret,target,tot + candidates[i],candidates); // since can take infinite times

        // Dont pick candidates[i], that is pop and remove duplicates

        cur.pop_back();
        while(i + 1 < sz(candidates) && candidates[i] == candidates[i+1])
        {
            i += 1;
        }

        dfs(i+1,cur,ret,target,tot,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vvi ret;
        vi cur;
        sort(candidates.begin(), candidates.end()); // sorting is must to remove duplicaets
        dfs(0,cur,ret,target,0,candidates);
        return ret;
    }
};

// Can be used only once

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vi>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define srt(v) sort(v.begin(), v.end())

// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void dfs(int i , vi& cur , vvi &ret , int &target , int tot, vi &candidates)
    {                
        if(tot == target)
        {
            ret.pb(cur);
            return;
        }

        if(i >= sz(candidates) || tot > target)
        {
            return;
        }

        cur.pb(candidates[i]);
        dfs(i+1,cur,ret,target,tot + candidates[i],candidates); // change here
        
        cur.pop_back();

        while(i + 1 < sz(candidates) && candidates[i] == candidates[i+1])
        {
            i += 1;
        }
        
        dfs(i+1,cur,ret,target,tot,candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        srt(candidates);
        vvi ret;
        vi cur;
        dfs(0,cur,ret,target,0,candidates);
        return ret;
    }
};