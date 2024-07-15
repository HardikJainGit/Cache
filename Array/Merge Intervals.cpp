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
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
          
        srt(intervals);

        vvi ans;

        if(sz(intervals)==1)
        {
            return intervals;
        }

        // (1,3) (2,4)

        f(sz(intervals))
        {
            if(ans.empty())
            {
                ans.pb({intervals[0][0] , intervals[0][1]});
            }
            if(ans.back()[1] >= intervals[i][0])
            {
                auto it = ans.back();
                ans.pop_back();
                ans.pb({it[0] , max(it[1] , intervals[i][1])});
            }
            else
            {
                ans.pb({intervals[i][0] , intervals[i][1]});
            }
        }

        return ans;
    }
};