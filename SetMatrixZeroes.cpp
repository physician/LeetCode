/*
 Author:     physician
 Date:       Feb 04, 2013
 Update:     Feb 04, 2013
 Problem:    Set Matrix Zeroes
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/set-matrix-zeroes/

 Problem Description:
 Set Matrix Zeroes: 

 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 Follow up:

 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution?

 Notes:
 1. First implementation, use matrix first row and column as auxiliary storage.
 2. Time complexity O(mn). Space complexity O(1). 
 2. Compile using g++: g++ SetMatrixZeroes.cpp -o SetMatrixZeroes.
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool row = false, col = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0) {
                row = true;
                break;
            }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }
        if (col) {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
        if (row) {
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }
    }
};

void printMatrix(vector<vector<int> > &matrix) {
    cout << "[" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        cout << " [ ";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    } 
    cout << "]" << endl;
}

int main() {
    int row1a[4] = {1, 1, 1, 0};
    int row2a[4] = {1, 1, 1, 1};
    int row3a[4] = {1, 1, 1, 1};
    int row4a[4] = {1, 1, 1, 1};
    int row5a[4] = {1, 1, 1, 1};
    int row6a[4] = {1, 1, 1, 1};
    vector<int> row1v(row1a, row1a + sizeof(row1a)/sizeof(int));
    vector<int> row2v(row2a, row2a + sizeof(row2a)/sizeof(int));
    vector<int> row3v(row3a, row3a + sizeof(row3a)/sizeof(int));
    vector<int> row4v(row4a, row4a + sizeof(row4a)/sizeof(int));
    vector<int> row5v(row5a, row5a + sizeof(row5a)/sizeof(int));
    vector<int> row6v(row6a, row6a + sizeof(row6a)/sizeof(int));
    vector<vector<int> > matrix;
    matrix.push_back(row1v);
    matrix.push_back(row2v);
    matrix.push_back(row3v); 
    matrix.push_back(row4v);
    matrix.push_back(row5v);
    matrix.push_back(row6v);
    Solution sol;
    cout << "Before setting zeroes:" << endl;
    printMatrix(matrix);
    cout << "After setting zeroes:" << endl;
    sol.setZeroes(matrix);
    printMatrix(matrix);
}
