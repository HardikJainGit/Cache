#include<bits/stdc++.h>
using namespace std;


#define py cout << "YES\n";
#define pn cout << "NO\n";
#define int long long
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


int32_t main() 
{
    vi v = {2,1,5,6,2,3};
    int n = 6;
    stack <int> st;

    // next greater :

    vi ng(n,-1);
    st.push(v[n-1]);

    for(int i=n-1;i>=0;i--)
    {
        if(!st.empty())
        {
            // compare
            while(!st.empty() && v[i] >= st.top())
            {
                st.pop();
            }
            // assign
            if(!st.empty())
            {
                ng[i] = st.top();
            }
            // unconditional push
            st.push(v[i]);
        }
    }   
    // debug(ng);
    
    stack <int> st2;

    // next smaller :

    vi ns(n,-1);
    st2.push(v[n-1]);

    for(int i=n-1;i>=0;i--)
    {
        if(!st2.empty())
        {
            while(!st2.empty() && v[i] <= st2.top())
            {
                st2.pop();
            }
            if(!st2.empty())
            {
                ns[i] = st2.top();
            }
            st2.push(v[i]);
        }
    }   
    // debug(ns);

    stack <int> st3;

    // prev greater :

    vi pg(n,-1);
    st3.push(v[0]);

    f(n)
    {
        if(!st3.empty())
        {
            while(!st3.empty() && v[i] >= st3.top())
            {
                st3.pop();
            }
            if(!st3.empty())
            {
                pg[i] = st3.top();
            }
            st3.push(v[i]);
        }
    }   
    // debug(pg);

    stack <int> st4;

    // prev smaller :

    vi ps(n,-1);
    st4.push(v[0]);

    f(n)
    {
        if(!st4.empty())
        {
            while(!st4.empty() && v[i] <= st4.top())
            {
                st4.pop();
            }
            if(!st4.empty())
            {
                ps[i] = st4.top();
            }
            st4.push(v[i]);
        }
    }   
    // debug(ps);
}