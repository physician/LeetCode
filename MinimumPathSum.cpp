/*
 Author:     physician
 Date:       Jan 22, 2014
 Update:     Jan 22, 2014
 Problem:    Minimum Path Sum
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/minimum-path-sum/

 Problem Description:
 Minimum Path Sum:
 
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time.

 Notes:
 1. First implementation, DP. Space complexity O(m*n).
 2. 2D vector initialization syntax. Use conditional operator for simplicity.
 3. Compile using g++: g++ MinimumPathSum.cpp -o MinimumPathSum.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minSum [m][n];
        minSum[m-1][n-1] = grid[m-1][n-1];
        for(int i = m-2; i >= 0; --i)
            minSum[i][n-1] = minSum[i+1][n-1] + grid[i][n-1];
        for(int j = n-2; j >= 0; --j)
            minSum[m-1][j] = minSum[m-1][j+1] + grid[m-1][j];
        for(int i = m-2; i >= 0; --i) 
            for(int j = n-2; j >= 0; --j)
                minSum[i][j] = (minSum[i+1][j] >= minSum[i][j+1] ? minSum[i][j+1] : minSum[i+1][j]) + grid[i][j];
        return minSum[0][0];       
    }
};

int main() {
    int m = 3;
    int n = 3;
    vector<vector<int> > grid(m, vector<int>(n, 0));
    grid[0][1] = 1;
    grid[0][2] = 1;
    grid[2][0] = 1;
    grid[2][1] = 1;
    Solution sol;
    cout << "The minimum sum along the path is: " << sol.minPathSum(grid) << endl;
}
