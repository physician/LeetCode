/*
 Author:     physician
 Date:       Feb 04, 2015
 Update:     Feb 04, 2015
 Problem:    Valid Sudoku
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/valid-sudoku/

 Problem Description:
 Valid Sudoku:
 
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

 A partially filled sudoku which is valid.

 Note:
 A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

 Notes:
 1. First implementation, hash table.
 2. Compile using g++: g++ -std=c++0x ValidSudoku.cpp -o ValidSudoku.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() != 9 || board[0].size() != 9)
            return false;
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if (num <= 0 || num > 10)
                    return false;
                if (row[i][num-1] || col[j][num-1] || box[i/3*3+j/3][num-1])
                    return false;
                else
                    row[i][num-1] = col[j][num-1] = box[i/3*3+j/3][num-1] = num; 
            }
        return true;
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
    if (sol.isValidSudoku(board))
        cout << "It is a valid Sudoku." << endl;
    else
        cout << "It is NOT a valid Sudoku." << endl;
}
