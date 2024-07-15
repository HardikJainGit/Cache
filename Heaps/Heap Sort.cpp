#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-an-array/

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
    void maxHeapify(vector<int>& nums, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if(l<n && nums[l] > nums[largest])
            largest = l;
        if(r<n && nums[r] > nums[largest])
            largest = r;
        
        if(largest != i)
        {
            swap(nums[largest], nums[i]);
            maxHeapify(nums,n,largest);
        }
    }
    
    void buildHeap(vector<int>& nums, int n)
    {
        // n/2 to n-1 leaves
        // 0 to n/2 - 1 other nodes

        for(int i=n/2 - 1;i>=0;i--)
            maxHeapify(nums,n,i);
    }
    
    void heapSort(vector<int>& nums, int n)
    {
        buildHeap(nums,n);

        // debug(nums);

        // keep swapping first and last
        // keep reducing size that we pass to buildHeap
        
        for(int i=n-1;i>=1;i--)
        {
            swap(nums[0],nums[i]);
            maxHeapify(nums,i,0);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) 
    {
        heapSort(nums,nums.size());
        
        return nums;
    }
};