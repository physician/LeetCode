/*
 Author:     physician
 Date:       Feb 07, 2015
 Update:     Feb 07, 2015
 Problem:    N-Queens II
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/n-queens-ii/

 Problem Description:
 N-Queens:
 
 Follow up for N-Queens problem.

 Now, instead outputting board configurations, return the total number of distinct solutions.

 Notes:
 1. First implementation, recursion, DFS. Backtracking.
 2. Bit operation solution is the fastest.
 3. Compile using g++: g++ -std=c++0x N-QueensII.cpp -o N-QueensII.
*/


# include <iostream>
# include <vector>
# include <cstring>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        return totalNQueens1(n);
    }

    // bit manipulation
    int totalNQueens1(int n) {
        int result= 0;
        totalNQueensHelper1(n, 0, 0, 0, result);
        return result;
    }

    void totalNQueensHelper1(int n, int col, int ld, int rd, int &result) {
        if (col == (1 << n) - 1) {
            result++;
            return;
        }
        int avail = ~(col | ld | rd);
        for (int i = n-1; i >= 0; --i) {
            int pos = 1 << i;
            if (pos & avail)
                totalNQueensHelper1(n, col|pos, (ld|pos) << 1, (rd|pos) >> 1, result);
        }
    }

    int totalNQueens2(int n) {
        int result = 0;
        int board[n];
        memset(board, -1, n);
        totalNQueensHelper2(n, 0, board, result);
        return result;
    }

    void totalNQueensHelper2(int n, int row, int board[], int &result) {
        if (row == n) {
            result++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValid(row, i, board)) {
                board[row] = i;
                totalNQueensHelper2(n, row+1, board, result);
                board[row] = -1;
            }
        }
    }

    bool isValid(int row, int col, int board[]) {
        for (int i = 0; i < row; ++i) {
            if (board[i] == col || row - i == abs(board[i] - col))
                return false;
        }
        return true;
    }
};

int main() {
    int n = 8;
    Solution sol;
    int result = sol.totalNQueens(n);
    cout << "Number of distinct solution is: " << result << endl;
}
