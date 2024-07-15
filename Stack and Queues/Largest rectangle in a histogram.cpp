#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/

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
    vector<int> nextSmaller(vector<int>& nums2) {

        stack <int> st2;
        vi ns(sz(nums2),sz(nums2));
        int n = sz(nums2);
        vi v = nums2;
        st2.push(n-1);

        for(int i=n-1;i>=0;i--)
        {
            if(!st2.empty())
            {
                while(!st2.empty() && v[i] <= v[st2.top()])
                {
                    st2.pop();
                }
                if(!st2.empty())
                {
                    ns[i] = st2.top();
                }
                st2.push(i);
            }
        }  
        return ns; 
    }

    vector<int> prevSmaller(vector<int> &A) {
        stack <int> st4;
        int n = sz(A);
        vi ps(n,-1);
        vi v = A;
        st4.push(0);

        f(n)
        {
            if(!st4.empty())
            {
                while(!st4.empty() && v[i] <= v[st4.top()])
                {
                    st4.pop();
                }
                if(!st4.empty())
                {
                    ps[i] = st4.top();
                }
                st4.push(i);
            }
        }   
        return ps;
    }   
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = sz(heights);
        vi smallPrev(n,-1);
        vi smallNext(n,-1);
        int mos = 0;

        smallPrev = prevSmaller(heights);
        smallNext = nextSmaller(heights);

        // wrt indexes //

        f(n)
        {
            mos = max(mos , ((smallNext[i] - smallPrev[i] - 1) * heights[i]));
        }
        return mos;
    }
};
// @lc code=end


