/*
 Author:     physician
 Date:       Feb 05, 2015
 Update:     Feb 05, 2015
 Problem:    Sudoku Solver
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/sudoku-solver/

 Problem Description:
 Valid Sudoku:
 
 Write a program to solve a Sudoku puzzle by filling the empty cells.

 Empty cells are indicated by the character '.'.

 You may assume that there will be only one unique solution.

 A sudoku puzzle...

 ...and its solution numbers marked in red.

 Notes:
 1. First implementation, recursion, DFS. Backtracking.
 2. Compile using g++: g++ -std=c++0x SudokuSolver.cpp -o SudokuSolver.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuHelper(board, 0, 0); 
    }

    bool isValidSudoku(vector<vector<char> > &board, int row, int col, int val) {
        char c = val + '0';
        for (int k = 0; k < 9; ++k)
            if (board[row][k] == c || board[k][col] == c || board[row/3*3+k/3][col/3*3+k%3] == c)
                return false;
        return true;
    }

    bool solveSudokuHelper(vector<vector<char> > &board, int row, int col) {
        if (row == 9)
            return true;
        if (col == 9)
            return solveSudokuHelper(board, row+1, 0);
        if (board[row][col] != '.')
            return solveSudokuHelper(board, row, col+1);
        for (int k = 1; k <= 9; k++)
            if (isValidSudoku(board, row, col, k)) {
                board[row][col] = k + '0';
                if (solveSudokuHelper(board, row, col+1))
                    return true;
                board[row][col] = '.';  // important!
            }
        return false;
    }
};

int main() {
    vector<vector<char> > board {{'5','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}};
    cout << "The Sudoku board is: " << endl;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
    Solution sol;
    sol.solveSudoku(board);
    cout << "The Sudoku solution is: " << endl;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
