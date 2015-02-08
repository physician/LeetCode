/*
 Author:     physician
 Date:       Feb 08, 2015
 Update:     Feb 08, 2015
 Problem:    Surrounded Regions
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/surrounded-regions/

 Problem Description:
 Surrounded Regions:
 
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

 A region is captured by flipping all 'O's into 'X's in that surrounded region.

 For example,

  X X X X
  X O O X
  X X O X
  X O X X

 After running your function, the board should be:

  X X X X
  X X X X
  X X X X
  X O X X

 Notes:
 1. First implementation, iteration, BFS/DFS.
 2. Compile using g++: g++ -std=c++0x SurroundedRegions.cpp -o SurroundedRegions.
*/


# include <iostream>
# include <vector>
# include <stack>
# include <queue>
# include <utility>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || i == N-1 || j == 0 || j == M-1) {
                    bfsIterative(board, i, j);
                    //dfsIterative(board, i, j);
                    //dfsRecursive(board, i, j);
                }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = board[i][j] == 'V' ? 'O' : 'X';
    }
    
    // BFS by iteration, using queue
    void bfsIterative(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] != 'O')
            return;
        int N = board.size(), M = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while(!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= N || j < 0 || j >= M)
                continue;
            if (board[i][j] != 'O') // important: check to avoid infinite loop
                continue;
            board[i][j] = 'V';
            q.push(make_pair(i+1, j));
            q.push(make_pair(i-1, j));
            q.push(make_pair(i, j+1));
            q.push(make_pair(i, j-1));
        }
    }

    // DFS by iteration, using stack
    void dfsIterative(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] != 'O')
            return;
        int N = board.size(), M = board[0].size();
        stack<pair<int, int>> stk;
        stk.push(make_pair(row, col));
        while(!stk.empty()) {
            int i = stk.top().first, j = stk.top().second;
            stk.pop();
            if (i < 0 || i >= N || j < 0 || j >= M)
                continue;
            if (board[i][j] != 'O') // important: check to avoid infinite loop
                continue;
            board[i][j] = 'V';
            stk.push(make_pair(i+1, j));
            stk.push(make_pair(i-1, j));
            stk.push(make_pair(i, j+1));
            stk.push(make_pair(i, j-1));
        }
    }

    // DFS by recursion, stack overflow for large board
    void dfsRecursive(vector<vector<char>> &board, int row, int col) {
        int N = board.size(), M = board[0].size();
        if (row < 0 || row >= N || col < 0 || col >= M)
            return;
        if (board[row][col] != 'O')
            return;
        board[row][col] = 'V';
        dfsRecursive(board, row + 1, col);
        dfsRecursive(board, row - 1, col);
        dfsRecursive(board, row, col + 1);
        dfsRecursive(board, row, col - 1);
    }
};

int main() {
    vector<vector<char>> board {{'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}};
    cout << "The board before: " << endl;
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[0].size(); ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
    Solution sol;
    sol.solve(board);
    cout << "The board after: " << endl;
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[0].size(); ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
