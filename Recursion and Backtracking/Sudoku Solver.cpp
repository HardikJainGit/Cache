#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    bool isSafe(int row, int col, vector< vector<int> > Sudoku, int val) {
        for(int i=0; i<9; i++) {
            // Row check
            if(Sudoku[row][i] == val) {
                return false;
            }

            // Column Check
            if(Sudoku[i][col] == val) {
                return false;
            }

            // 3x3 Matrix Check
            if(Sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
                return false;
            }
        }

        return true;
    }

    bool solve(vector< vector<int> > &Sudoku) {
        for(int row=0; row<9; row++) {
            for(int col=0; col<9; col++) {
                
                // Empty Cell
                if(Sudoku[row][col] == 0) {

                    for(int val=1; val<=9; val++) {
                        if(isSafe(row, col, Sudoku, val)) {
                            Sudoku[row][col] = val;

                            bool nextSol = solve(Sudoku);
                            if(nextSol) {
                                return true;
                            } else {
                                Sudoku[row][col] = 0; //Backtracking remove if not fitting in
                            }

                        }
                    }

                    return false;
                }

            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>> &board) 
    {
        vector<vector<int>> intBoard(9, vector<int>(9, 0));
        
        // Convert char board to int board
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    intBoard[i][j] = board[i][j] - '0';
                } else {
                    intBoard[i][j] = 0;
                }
            }
        }

        // Solve the Sudoku
        solve(intBoard);

        // Convert int board back to char board
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(intBoard[i][j] != 0) {
                    board[i][j] = intBoard[i][j] + '0';
                } else {
                    board[i][j] = '.';
                }
            }
        }
    }
};