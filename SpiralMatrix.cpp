/*
 Author:     physician
 Date:       Jan 24, 2014
 Update:     Jan 24, 2014
 Problem:    Spiral Matrix
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/spiral-matrix/

 Problem Description:
 Spiral Matrix: 

 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

 For example,
 Given the following matrix:

 [
  [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ SpiralMatrix.cpp -o SpiralMatrix.
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty())
            return result;
        int rowMin = 0;
        int rowMax = matrix.size();
        int colMin = 0;
        int colMax = matrix[0].size();
        int i = 0;
        int total = rowMax*colMax;
        while(i < total) {
            for(int j = colMin; j < colMax; ++j, ++i)
                result.push_back(matrix[rowMin][j]);
            rowMin++;
            if(rowMin == rowMax) break;
            for(int j = rowMin; j < rowMax; ++j, ++i)
                result.push_back(matrix[j][colMax-1]);
            colMax--;
            if(colMax == colMin) break;
            for(int j = colMax-1; j >= colMin; --j, ++i)
                result.push_back(matrix[rowMax-1][j]);
            rowMax--;
            if (rowMax == rowMin) break;
            for(int j = rowMax-1; j >= rowMin; --j, ++i)
                result.push_back(matrix[j][colMin]);
            colMin++;
            if(colMin == colMax) break;
        }
        return result;
    }
};


int main() {
    vector<vector<int> > matrix;
    vector<int> row0, row1, row2;
    row0.push_back(1);
    row0.push_back(2);
    row0.push_back(3);
    row1.push_back(4);
    row1.push_back(5);
    row1.push_back(6);
    row2.push_back(7);
    row2.push_back(8);
    row2.push_back(9);
    matrix.push_back(row0);
    matrix.push_back(row1);
    matrix.push_back(row2);
    cout << "The matrix is:" << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < matrix[0].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << "]" << endl;
    }
    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);
    cout << "The spiral order is:" << endl;
    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}
