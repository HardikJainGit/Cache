#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/aggressive-cows_1082559?leftPanelTabValue=PROBLEM

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
#define inp(a,n) int a[n]; f(n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool condition(vector<int> &barn, int mid, int cows) {
    int lastPos = -1;
    int cow_count = cows;

    f(sz(barn))
    {
        if (lastPos == -1 || barn[i] - lastPos >= mid)
        {
            cow_count--;
            lastPos = barn[i];
        }

        if (cow_count == 0)
        {
            break;
        }
    }

    return cow_count == 0; 
}
int aggressiveCows(vector<int> &stalls, int k) {

    int n = stalls.size(); //size of array
    //sort the stalls[]:
    srt(stalls);

    int lo = 0;
    int hi = 1e9;
    int mid = 0;;

    while (hi-lo>1) 
    {
        mid = (hi + lo) / 2;

        if (condition(stalls, mid, k) == true) 
        {
            lo = mid;
        }
        else 
        {
            hi = mid;
        }
    }
    return lo;
}
