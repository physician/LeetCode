/*
 Author:     physician
 Date:       Jan 23, 2014
 Update:     Jan 23, 2014
 Problem:    Triangle
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/triangle/

 Problem Description:
 Triangle:
 
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

 For example, given the following triangle
 [
      [2],
     [3,4],
    [6,5,7],
   [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 
 Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

 Notes:
 1. First implementation, DP. Space complexity O(n). Bottom up.
 2. Compile using g++: g++ Triangle.cpp -o Triangle.
*/


# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        int minSum[n];
        for(int i = 0; i < n; ++i)
            minSum[i] = triangle[n-1][i];
        for(int i = n - 2; i >= 0; --i)
            for(int j = 0; j <= i; ++j)
                minSum[j] = triangle[i][j] + min(minSum[j], minSum[j+1]);
        return minSum[0];
    }
};

int main() {
    vector<vector<int> > triangle;
    vector<int> row0, row1, row2, row3;
    row0.push_back(2);
    row1.push_back(3);
    row1.push_back(4);
    row2.push_back(6);
    row2.push_back(5);
    row2.push_back(7);
    row3.push_back(4);
    row3.push_back(1);
    row3.push_back(8);
    row3.push_back(3);
    triangle.push_back(row0);
    triangle.push_back(row1);
    triangle.push_back(row2);
    triangle.push_back(row3);
    Solution sol;
    int n = triangle.size();
    for(int i = 0; i < triangle.size(); ++i){
        for(int j = n - i; j > 0; --j)
            cout << " ";
        cout << "[ ";
        for(int j = 0; j < triangle[i].size(); ++j)
            cout << triangle[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "The minimum path sum from the top to bottom is: " << sol.minimumTotal(triangle) << endl;
}
