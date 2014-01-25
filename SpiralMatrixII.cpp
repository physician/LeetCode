/*
 Author:     physician
 Date:       Jan 25, 2014
 Update:     Jan 25, 2014
 Problem:    Spiral Matrix II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/spiral-matrix-ii/

 Problem Description:
 Spiral Matrix II: 

 Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

 For example,
 Given n = 3,

 You should return the following matrix:
 [
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
 ]

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ SpiralMatrixII.cpp -o SpiralMatrixII.
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int rowMin = 0;
        int rowMax = n;
        int colMin = 0;
        int colMax = n;
        int i = 1;
        int total = n*n;
        while(i <= total) {
            for(int j = colMin; j < colMax; ++j, ++i)
                matrix[rowMin][j] = i;
            rowMin++;
            if(rowMin == rowMax) break;
            for(int j = rowMin; j < rowMax; ++j, ++i)
                matrix[j][colMax-1] = i;
            colMax--;
            if(colMax == colMin) break;
            for(int j = colMax-1; j >= colMin; --j, ++i)
                matrix[rowMax-1][j] = i;
            rowMax--;
            if (rowMax == rowMin) break;
            for(int j = rowMax-1; j >= rowMin; --j, ++i)
                matrix[j][colMin] = i;
            colMin++;
            if(colMin == colMax) break;
        }
        return matrix;
    }
};


int main() {
    int n = 3;
    Solution sol;
    vector<vector<int> > matrix = sol.generateMatrix(n);
    cout << "n = " << n << endl;
    cout << "The spiral matrix is:" << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < matrix[0].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << "]" << endl;
    }
}
