// https://leetcode.com/problems/longest-common-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

#define py cout << "YES\n";
#define pn cout << "NO\n";
#define vi vector <int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; fz(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n1 = text1.length();
        int n2 = text2.length();
        vvi dp(n1+1,vi(n2+1,0));

        // dp[n1][n2] is zero since no common subsequence
        // subsequence is not contagious segment

        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else
                {
                    // since we are interested in subsequence, pieces are ok
                    dp[i][j] = max(dp[i+1][j] , dp[i][j+1]); // which is a better choice 
                }
            }
        }

        return dp[0][0];
    }
};

// Longest Palindromic Subsequence :

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vvi dp(n1+1, vi(n2+1, 0));

        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // To print the LCS

        int i = 0, j = 0;

        string lcs = "";

        // take 2 pointers, if text matches, update lcs else increment accordingly

        while (i < n1 && j < n2) 
        {
            if (text1[i] == text2[j]) 
            {
                lcs += text1[i];
                ++i;
                ++j;
            } 
            else if (dp[i + 1][j] > dp[i][j + 1]) 
            {
                ++i;
            } 
            else 
            {
                ++j;
            }
        }

        pr("Longest Common Subsequence: " + lcs);
        return dp[0][0];
    }

    int longestPalindromeSubseq(string s) {
        string ret = s;
        reverse(s.begin(), s.end());
        return longestCommonSubsequence(s, ret);
    }
};

