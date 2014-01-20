/*
 Author:     physician
 Date:       Jan 19, 2014
 Update:     Jan 19, 2014
 Problem:    Unique Paths
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/unique-paths/

 Problem Description:
 Unique Paths:

 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 How many possible unique paths are there?

 Note: m and n will be at most 100.

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ UniquePaths.cpp -o UniquePaths.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int A[m][n];
        for(int i = 0; i < m; ++i)
            A[i][n-1] = 1;
        for(int j = 0; j < n; ++j)
            A[m-1][j] = 1;
        for(int i = m-2; i >= 0; --i)
            for(int j = n-2; j >= 0; --j)
                A[i][j] = A[i+1][j] + A[i][j+1];
        return A[0][0]; 
    }
};

int main() {
	int m = 2;
    int n = 3;
    Solution sol;
    cout << "There are " << sol.uniquePaths(m, n) << " unique paths for " << m << " x " << n << " grid." << endl;
}
