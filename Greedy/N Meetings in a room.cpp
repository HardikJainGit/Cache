#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

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
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Solution
{
    // static is required //
    static bool sortBySecond(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
    }
    public:

    int maxMeetings(int start[], int end[], int n)
    {
        vi s;
        vi e;
        
        f(n)
        {
            s.pb(start[i]);
            e.pb(end[i]);
        }
        // debug(s);
        
        vp meets;
        
        f(n)
        {
            meets.push_back(make_pair(s[i], e[i]));
        }

        sort(meets.begin(),meets.end(),sortBySecond);

        vi flag(n,0);

        int count = 1; // first meeting must be scheduled
        int gg = meets[0].ss;

        f(n)
        {
            if(meets[i].ff > gg) // start time > end time
            {
                gg = meets[i].ss; // update the end time
                count += 1;
            }
        }

        return count;
    }
};