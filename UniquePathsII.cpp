/*
 Author:     physician
 Date:       Jan 19, 2014
 Update:     Jan 19, 2014
 Problem:    Unique Paths II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/unique-paths-ii/

 Problem Description:
 Unique Paths II:

 Follow up for "Unique Paths":

 Now consider if some obstacles are added to the grids. How many unique paths would there be?

 An obstacle and empty space is marked as 1 and 0 respectively in the grid.

 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.

 [
   [0,0,0],
   [0,1,0],
   [0,0,0]
 ]
 The total number of unique paths is 2.

 Note: m and n will be at most 100.

 Notes:
 1. First implementation, DP.
 2. 2D vector initialization syntax. Use conditional operator for simplicity.
 3. Compile using g++: g++ UniquePathsII.cpp -o UniquePathsII.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int A[m][n];
        if (obstacleGrid[m-1][n-1] == 1)
            return 0;
        else
            A[m-1][n-1] = 1;
        for(int i = m-2; i >= 0; --i)
            A[i][n-1] = obstacleGrid[i][n-1] == 1 ? 0 : A[i+1][n-1];
        for(int j = n-2; j >= 0; --j)
            A[m-1][j] = obstacleGrid[m-1][j] == 1 ? 0 : A[m-1][j+1];
        for(int i = m-2; i >= 0; --i)
            for(int j = n-2; j >= 0; --j)
                A[i][j] = obstacleGrid[i][j] == 1 ? 0 : A[i+1][j] + A[i][j+1];
        return A[0][0];
    }
};

int main() {
	int m = 3;
    int n = 3;
    vector<vector<int> > obstacleGrid(m, vector<int>(n, 0));
    obstacleGrid[1][1] = 1;
    Solution sol;
    cout << "There are " << sol.uniquePathsWithObstacles(obstacleGrid) << " unique paths for the given obstacles." << endl;
}
