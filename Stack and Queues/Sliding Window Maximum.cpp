#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sliding-window-maximum/description/

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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque <int> q;
        vi output;
        int l = 0;

        f(sz(nums))
        {
            // decreasing deque

            while(!q.empty() && nums[q.front()] < nums[i])
            {
                q.pop_front();
            }

            q.push_front(i);

            if(l>q.back())
            {
                q.pop_back();
            }

            if(i>=k-1 && !q.empty())
            {
                output.pb(nums[q.back()]); // Push the highest element in the queue
                l+=1;
            }
        }
        return output;
    }
};