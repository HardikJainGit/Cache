#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/snakes-and-ladders/?envType=study-plan-v2&envId=top-interview-150

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
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();
        unordered_map<int, int> m;

        rev(board); // reversing the rows then odd rows

        // 1 2 3 4 5 6
        // 7 8 9 10 11 12
        // ...
        

        f(n)
        {
            if(i % 2) rev(board[i]);
            fz(j,0,n)
            m[i * n + j + 1] = board[i][j];
        }

        vector<int> vis(n*n + 1, 0);

        vis[1] = 1;
     
        queue<int> q;
        int s = 1;
        int ret = 0;
        
        q.push(s);

        while (!q.empty()) 
        {
            int s = sz(q);
            while(s--)
            {
                int v = q.front();
                q.pop();
                if(v == n*n)
                {
                    return ret;
                }
                fz(i,1,7)
                {
                    if(v+i > n*n) break;
                    if(m[v + i] == -1 && !vis[v+i]) 
                    {
                        q.push(v+i);
                        vis[v+i] = 1;
                    }

                    else if(m[v+i] != -1 && !vis[m[v+i]])
                    {
                        q.push(m[v+i]);
                        vis[m[v+i]] = 1;
                    }
                }
            }
            ret += 1;
        }

        return -1;
    }
};