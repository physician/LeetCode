/*
 Author:     physician
 Date:       Aug 28, 2013
 Update:     Aug 28, 2013
 Problem:    Search a 2D Matrix
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_74

 Problem Description:
 Search a 2D Matrix: 

 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 1. Integers in each row are sorted from left to right.
 2. The first integer of each row is greater than the last integer of the previous row.

 For example,

 Consider the following matrix:

 [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
 ]

 Given target = 3, return true.

 Notes:
 1. First implementation, recursion, binary search. Treat matrix as 1D sorted array and do index transformation.
 2. Compile using g++: g++ Searcha2DMatrix.cpp -o Searcha2DMatrix
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int arraysize = matrix.size() * matrix[0].size();
        return searchMatrixArray(matrix, target, 0, arraysize); 
    }

private:
    bool searchMatrixArray(vector<vector<int> > &matrix, int target, int start, int end) {
        if (end <= start)
            return false;
        int rowSize = matrix[0].size();
        if (end - start == 1) {
            int rowIndex = start / rowSize;
            int colIndex = start % rowSize;
            if (matrix[rowIndex][colIndex] == target)
                return true;
            else
                return false;
        }
        int mid = (start + end)/2;
        int rowIndex = mid / rowSize;
        int colIndex = mid % rowSize;
        if (matrix[rowIndex][colIndex] == target)
            return true;
        else if (matrix[rowIndex][colIndex] < target)
            return searchMatrixArray(matrix, target, mid + 1, end);
        else
            return searchMatrixArray(matrix, target, start, mid);
    }
};

int main() {
    int target = 3;
    int row1a[4] = {1, 3, 5, 7};
    int row2a[4] = {10, 11, 16, 20};
    int row3a[4] = {23, 30, 34, 50};
    vector<int> row1v(row1a, row1a + sizeof(row1a)/sizeof(int));
    vector<int> row2v(row2a, row2a + sizeof(row2a)/sizeof(int));
    vector<int> row3v(row3a, row3a + sizeof(row3a)/sizeof(int));
    vector<vector<int> > matrix;
    matrix.push_back(row1v);
    matrix.push_back(row2v);
    matrix.push_back(row3v); 
    Solution sol;
    cout << "[" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        cout << " [";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    } 
    cout << "]" << endl;
    if(sol.searchMatrix(matrix, target))
        cout << target << " is in the matrix." << endl;
    else
        cout << target << " is NOT in the matrix." << endl;
}
