#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/edit-distance/

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
    
    // https://www.youtube.com/watch?v=XYi2-LPrwm4

    int minDistance(string word1, string word2) 
    {
        vvi dp(word2.length() + 1 , vi(word1.length() + 1, 0));

        int n2 = word2.length();
        int n1 = word1.length();

        f(n2+1)
        {
            fz(j,0,n1+1)
            {
                if(j == n1)
                {
                    dp[i][j] = n2 - i; // word 1 is empty
                }
                if(i == n2)
                {
                    dp[i][j] = n1 - j; // word 2 is empty dp[n2][0] = n1 as j is 0 so we are at starting of string 1
                }
            }
        }

        for(int i=n2-1;i>=0;i--)
        {
            for(int j=n1-1;j>=0;j--)
            {
                if(word2[i] == word1[j])
                {
                    dp[i][j] = dp[i+1][j+1]; // already equal
                }
                else 
                {
                    dp[i][j] = 1 + min({dp[i][j+1] , dp[i+1][j] , dp[i+1][j+1]}); // do one operation and do 
                                        // insert     // delete     // replace
                }
            }
        }

        return dp[0][0];
    }
};