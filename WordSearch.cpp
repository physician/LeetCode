/*
 Author:     physician
 Date:       Feb 15, 2014
 Update:     Feb 15, 2014
 Problem:    Word Search
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/word-search/

 Problem Description:
 Word Search: 

 Given a 2D board and a word, find if the word exists in the grid.

 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

 For example,
 Given board =

 [
   ["ABCE"],
   ["SFCS"],
   ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ WordSearch.cpp -o WordSearch.
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
            return false;
        return exist2(board, word);
    }

private:
    bool exist1(vector<vector<char> > &board, string word) {
        int M = board.size(), N = board[0].size();
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool> > visited(M, vector<bool>(N, false));
                    visited[i][j] = true;
                    if (exist1Re(board, visited, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
    bool exist1Re(vector<vector<char> > &board, vector<vector<bool> > &visited, string &word, int i, int j, int k) {
        if (k+1 >= word.size())
            return true;
        if (i-1 >= 0 && !visited[i-1][j] && board[i-1][j] == word[k+1]) {
            visited[i-1][j] = true;
            if (exist1Re(board, visited, word, i-1, j, k+1))
                return true;
            visited[i-1][j] = false;
        }
        if (i+1 < board.size() && !visited[i+1][j] && board[i+1][j] == word[k+1]) {
            visited[i+1][j] = true;
            if (exist1Re(board, visited, word, i+1, j, k+1))
                return true;
            visited[i+1][j] = false;
        }
        if (j-1 >= 0 && !visited[i][j-1] && board[i][j-1] == word[k+1]) {
            visited[i][j-1] = true;
            if (exist1Re(board, visited, word, i, j-1, k+1))
                return true;
            visited[i][j-1] = false;
        }
        if (j+1 < board[i].size() && !visited[i][j+1] && board[i][j+1] == word[k+1]) {
            visited[i][j+1] = true;
            if (exist1Re(board, visited, word, i, j+1, k+1))
                return true;
            visited[i][j+1] = false;
        }
        return false;
    }

    bool exist2(vector<vector<char> > &board, string word) {
        int M = board.size(), N = board[0].size();
        vector<vector<bool> > visited(M, vector<bool>(N, false));
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                if (board[i][j] == word[0] && exist2Re(board, visited, word, i, j, 0))
                    return true;
        return false;
    }
    bool exist2Re(vector<vector<char> > &board, vector<vector<bool> > &visited, string &word, int i, int j, int k) {
        k++;
        if (k == word.size())
            return true;
        visited[i][j] = true;
        if (i-1 >= 0 && !visited[i-1][j] && board[i-1][j] == word[k])
            if (exist2Re(board, visited, word, i-1, j, k))
                return true;
        if (i+1 < board.size() && !visited[i+1][j] && board[i+1][j] == word[k])
            if (exist2Re(board, visited, word, i+1, j, k))
                return true;
        if (j-1 >= 0 && !visited[i][j-1] && board[i][j-1] == word[k])
            if (exist2Re(board, visited, word, i, j-1, k))
                return true;
        if (j+1 < board[i].size() && !visited[i][j+1] && board[i][j+1] == word[k])
            if (exist2Re(board, visited, word, i, j+1, k))
                return true;
        visited[i][j] = false;
        return false;
    }
};


int main() {
    char r1[] = "ABCE";
    //char r2[] = "SFCS";
    char r2[] = "SFES";
    char r3[] = "ADEE";
    vector<char> row1(r1, r1 + sizeof(r1)/sizeof(char));
    vector<char> row2(r2, r2 + sizeof(r2)/sizeof(char));
    vector<char> row3(r3, r3 + sizeof(r3)/sizeof(char));
    vector<vector<char> > board;
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    cout << "The board is:" << endl;
    for (int i = 0; i < board.size(); ++i) {
        cout << "[\"";
        for (int j = 0; j < board[0].size(); ++j)
            cout << board[i][j];
        cout << "\"]" << endl;
    }
    //string word = "ABCCED";
    //string word = "SEE";
    //string word = "ABCB";
    string word = "ABCESEEEFS";
    Solution sol;
    if (sol.exist(board, word))
        cout << "There is the word " << "\"" << word << "\" on the board." << endl;
    else
        cout << "There is no word " << "\"" << word << "\" on the board." << endl;
}
