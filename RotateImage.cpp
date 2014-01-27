/*
 Author:     physician
 Date:       Jan 27, 2014
 Update:     Jan 27, 2014
 Problem:    Rotate Image
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/rotate-image/

 Problem Description:
 Rotate Image:
 
 You are given an n x n 2D matrix representing an image.

 Rotate the image by 90 degrees (clockwise).

 Follow up:
 Could you do this in-place?

 Notes:
 1. First implementation, two steps. Transpose then reflect.
    [1 2 3]        [1 4 7]        [7 4 1]
    [4 5 6]  --->  [2 5 8]  --->  [8 5 2]
    [7 8 9]        [3 6 9]        [9 6 3]
 2. Compile using g++: g++ RotateImage.cpp -o RotateImage.
*/


# include <iostream>
# include <vector>
# include <algorithm> // std::swap

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n/2; ++j)
                swap(matrix[i][j], matrix[i][n-1-j]);
    }
};

int main() {
    int n = 3;
    int A[3] = {1,2,3};
    int B[3] = {4,5,6};
    int C[3] = {7,8,9};
    vector<int> row1(A, A + sizeof(A)/sizeof(int));
    vector<int> row2(B, B + sizeof(B)/sizeof(int));
    vector<int> row3(C, C + sizeof(C)/sizeof(int));
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    cout << "The original matrix is:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "[ ";
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << "]" << endl;
    }
    Solution sol;
    sol.rotate(matrix);
    cout << "The matrix after rotation clockwise by 90 degrees is:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "[ ";
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << "]" << endl;
    }
}
