#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/?envType=study-plan-v2&envId=leetcode-75

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

    bool boundary(int r, int c, vector<vector<char>>& maze)
    {
        return (maze[r][c] == '.' && (r == 0 || r == sz(maze) - 1 || c == sz(maze[0]) - 1 || c == 0));
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int n = maze.size(); //n*m
	    int m = maze[0].size(); 

        int sr = entrance[0];
        int sc = entrance[1];

	    vvi vis(n, vi(m, 0)); 

	    queue<pi> q; 
        q.push({sr,sc});
        vis[sr][sc] = 1;

	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
        int cc = 0;
	    
	    while(!q.empty()) 
        {
	        int size = sz(q);

            while(size--)
            {

                int row = q.front().ff;
                int col = q.front().ss; 
                q.pop();

                if(boundary(row,col,maze) && !(row == sr && col == sc))
                {
                    return cc;
                }

                f(4)
                {
                    int nrow = row + delrow[i]; 
                    int ncol = col + delcol[i]; 
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && maze[nrow][ncol] == '.') 
                    {
                        // maze[nrow][ncol] = color;
                        vis[nrow][ncol] = 1; 
                        q.push({nrow, ncol});  
                    }
                }
            }
            cc += 1;
	    }
        return -1;
    }
};
