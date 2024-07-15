#include <iostream>
#include <vector>
#include <unordered_map>
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int, int>>
#define pi pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define in(x) int x; cin >> x;
#define f(b) for (int i = 0; i < b; i++)
#define fz(i, a, b) for (int i = a; i < b; i++)
#define inp(a, n) int a[n]; fz(i, 0, n) cin >> a[i];
#define inpv(a, n) vector<int> a; fz(i, 0, n) { int x; cin >> x; a.pb(x); }
#define endl '\n'
#define sz(x) ((int)(x).size())

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        // contiguous
        unordered_map<int, int> pr;

        int c_sum = 0;
        int cc = 0;
        
        pr[0] = 1;
        
        for (int it : nums) 
        {
            c_sum += it;
             
            // 2 sum logic

            // such that difference is k so that that subarray sums up to k
            
            if (pr.find(c_sum - k) != pr.end()) 
            {
                cc += pr[c_sum - k];
            }
            
            pr[c_sum]+= 1;
        }
        
        return cc;
    }
};