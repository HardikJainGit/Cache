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
#define inp(a,n) int a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; fz(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())

// https://leetcode.com/problems/n-queens/

class Solution {
public:
    map<int, bool> rowCheck;
    map<int, bool> upperCheck;
    map<int, bool> lowerCheck;

    void addSolution(vector< vector<int> > board, vector< vector<int> > &sol) 
    {
        vi v;
        for(auto it : board)
        {
            for(auto el : it)
            {
                v.pb(el);
            }
        }
        sol.pb(v);
    }
    
    bool isSafeBrute(int row, int col, vector< vector<int> > board, int n) {
        // Checking for same row
        for(int j=col; j>=0; j--) { //checking from columns till j as nothing after that
            if(board[row][j] == 1) { //filling left to right
                return false;
            }
        }

        // Checking for left upper diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        
        // Checking for left lower diagonal
        for(int i=row, j=col; i<n && j>=0; i++, j--) {
            if(board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }
    bool isSafe(int row, int col, int n) {
        return !(rowCheck[row] == true || lowerCheck[row+col] == true || upperCheck[n+row-col] == true);
    }

    //can also use n-1+col-row

    void solve(int col, vector< vector<int> > &solution, vector< vector<int> > &board, int n) {
        // Base Case
        if(col == n) {
            addSolution(board, solution);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafeBrute(row, col, board, n)) {
                // Setting Queen
                board[row][col] = 1;

                // Mapping Queen
                rowCheck[row] = true;
                lowerCheck[row+col] = true;
                upperCheck[n+row-col] = true;

                // Recursive Call
                solve(col+1, solution, board, n);

                // Backtracking
                board[row][col] = 0;
                rowCheck[row] = false;
                lowerCheck[row+col] = false;
                upperCheck[n+row-col] = false; //remove queen and its mapping also
            }
        }
    }

    vector< vector<int> > nQueens(int n) {
        vector< vector<int> > solution;
        vector< vector<int> > board(n, vector<int> (n,0));

        solve(0, solution, board, n);
        return solution;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result;
        vector<vector<int>> queens = nQueens(n);

        for(auto it : queens)
        {
            vector<string> res;
            for(int j=0;j<n;j++)
            {
                string s = "";
                for(int i=0;i<n;i++)
                {
                    if(it[i+j*n] == 1)
                    {
                        s += 'Q';
                    }
                    else if (it[i+j*n] == 0)
                    {
                        s += '.';
                    }
                }
                res.push_back(s);
            }
            result.push_back(res);
        }
        return result;
    }
};