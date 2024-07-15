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

// https://leetcode.com/problems/next-permutation/

// Find the dip iterating from the back
// let this be ind
// find the greater element iterting from end till ind
// swap that element with arr[ind]
// swap the right array from ind + 1 till end

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    
    int n = nums.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) { //finding dip
            // index i is the break point
            ind = i;
            break; //first dip
        }
    }


    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        rev(nums);
        return;
    }
    
    // debug(nums[ind]);

    // 1 2 3 ind is for 2 i.e 1

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break; 
        }
    }

    // 1 3 2 

    // debug(nums);

    // Step 3: reverse the right half:
    reverse(nums.begin() + ind + 1, nums.end());

    // reversing just the 3 making no difference
    // 1 3 2

     return;
     //return A;
    }
};