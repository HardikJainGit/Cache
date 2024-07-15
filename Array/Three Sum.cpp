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

// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        srt(nums);
        vvi ret;
        f(sz(nums))
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate values for i

            fz(j,i+1,sz(nums)){
            if (j > i+1 && nums[j] == nums[j - 1]) continue; 

            int lo = j + 1;
            int hi = sz(nums) - 1;
            while(hi > lo)
            {
                long long cur = static_cast<long long>(nums[lo]) + nums[hi] + nums[i] + nums[j];
                if(cur == target)
                {
                    ret.pb({nums[i], nums[j], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++; // Skip duplicates for lo
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--; // Skip duplicates for hi

                    lo += 1;
                    hi -= 1;
                }

                if(cur > target)
                {
                    hi -= 1;
                }
                if(cur < target)
                {
                    lo += 1;
                }
            }
            }
        }
        return ret;
    }
};

// Three Sum

// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        srt(nums);
        vvi ret;
        f(sz(nums))
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate values for i
            int lo = i + 1;
            int hi = sz(nums) - 1;

            while(hi > lo)
            {
                int cur = nums[lo] + nums[hi] + nums[i];
                if(cur == 0)
                {
                    ret.pb({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++; // Skip duplicates for lo
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--; // Skip duplicates for hi

                    lo += 1;
                    hi -= 1;
                }

                if(cur > 0)
                {
                    hi -= 1;
                }
                if(cur < 0)
                {
                    lo += 1;
                }
            }
        }
        return ret;
    }
};