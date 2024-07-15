#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vi>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

// https://www.interviewbit.com/problems/subarray-with-given-xor/

class Solution{
public:
    int xork(vector<int> &A, int B) {
    int n=sz(A);
    
    int ans = 0;
    
    int x=0;
    
    map<int,int> m;
    
    fz(i,0,sz(A))
    {
        x^=A[i];
        if (x == B) 
        {
            ans++;
        }
        if(m.find(x^B)!=m.end())
        {
            ans+=m[x^B];
        }
        m[x]+=1;
    } 

    return ans;
}
};