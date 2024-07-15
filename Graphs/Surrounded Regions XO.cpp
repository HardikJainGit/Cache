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

// https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:
    void floodFill(vector<vector<char>>& image, int i, int j)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] != 'O')
        {
            return;
        }

        image[i][j] = 'T';
        
        floodFill(image,i-1,j);
        floodFill(image,i+1,j);
        floodFill(image,i,j-1);
        floodFill(image,i,j+1);
    }
    
    void solve(vector<vector<char>>& board) 
    {
        int r = sz(board);
        int c = sz(board[0]);

        f(r)
        {
            if(board[i][0] == 'O')
            {
                floodFill(board,i,0);
            }
            if(board[i][c-1] == 'O')
            {
                floodFill(board,i,c-1);
            }
        }
        f(c)
        {
            if(board[0][i] == 'O')
            {
                floodFill(board,0,i);
            }
            if(board[r-1][i] == 'O')
            {
                floodFill(board,r-1,i);
            }
        }

        f(r)
        {
            fz(j,0,c)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        f(r)
        {
            fz(j,0,c)
            {
                if(board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }

    }
};