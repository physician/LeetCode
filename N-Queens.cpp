/*
 Author:     physician
 Date:       Feb 07, 2015
 Update:     Feb 07, 2015
 Problem:    N-Queens
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/n-queens/

 Problem Description:
 N-Queens:
 
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

 Given an integer n, return all distinct solutions to the n-queens puzzle.

 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

 For example,
 There exist two distinct solutions to the 4-queens puzzle:

 [
  [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],
 
  ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
 ]

 Notes:
 1. First implementation, recursion, DFS. Backtracking.
 2. Bit operation solution is the fastest.
 3. Compile using g++: g++ -std=c++0x N-Queens.cpp -o N-Queens.
*/


# include <iostream>
# include <vector>
# include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        return solveNQueens1(n);
    }

    // bit manipulation
    vector<vector<string> > solveNQueens1(int n) {
        vector<vector<string> > result;
        vector<string> board (n, string(n, '.'));
        solveNQueensHelper1(n, 0, 0, 0, 0, board, result);
        return result;
    }

    void solveNQueensHelper1(int n, int row, int col, int ld, int rd, vector<string> &board, vector<vector<string> > &result) {
        if (col == (1 << n) - 1) {
            result.push_back(board);
            return;
        }
        int avail = ~(col | ld | rd);
        for (int i = n-1; i >= 0; --i) {
            int pos = 1 << i;
            if (pos & avail) {
                board[row][i] = 'Q';
                solveNQueensHelper1(n, row+1, col|pos, (ld|pos) << 1, (rd|pos) >> 1, board, result);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string> > solveNQueens2(int n) {
        vector<vector<string> > result;
        vector<string> board (n, string(n, '.'));
        int boardLoc[n];
        memset(boardLoc, -1, n);
        solveNQueensHelper2(n, 0, boardLoc, board, result);
        return result;
    }

    void solveNQueensHelper2(int n, int row, int boardLoc[], vector<string> &board, vector<vector<string> > &result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValid(row, i, boardLoc)) {
                board[row][i] = 'Q';
                boardLoc[row] = i;
                solveNQueensHelper2(n, row+1, boardLoc, board, result);
                board[row][i] = '.';
                boardLoc[row] = -1;
            }
        }
    }

    bool isValid(int row, int col, int boardLoc[]) {
        for (int i = 0; i < row; ++i)
            if (boardLoc[i] == col || row - i == abs(boardLoc[i] - col))
                return false;
        return true;
    }
};

int main() {
    int n = 8;
    Solution sol;
    vector<vector<string> > result = sol.solveNQueens(n);
    cout << "The distinct solutions for n = " << n << ":"<< endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < n; ++j)
            cout << result[i][j] << endl;
        cout << endl;
    }
    cout << "Number of distinct solution is: " << result.size() << endl;
}
