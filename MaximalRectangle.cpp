/*
 Author:     physician
 Date:       Feb 10, 2015
 Update:     Feb 10, 2015
 Problem:    Maximal Rectangle
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/maximal-rectangle/

 Problem Description:
 Maximal Rectangle:

 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

 Notes:
 1. First implementation, stack.
 2. Algorithm: Similar idea as in Largest Rectangle in Histogram.
    Analysis refer to:
    http://www.cnblogs.com/lichen782/p/leetcode_maximal_rectangle.html
 3. Compile using g++: g++ -std=c++0x MaximalRectangle.cpp -o MaximalRectangle.
*/


# include <iostream>
# include <vector>
# include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int maxRec = 0;
        vector<int> height(matrix[0].size() + 1, 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j)
                height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
            maxRec = max(maxRec, largestRectangleArea(height));
        }
        return maxRec;
    }

    int largestRectangleArea(vector<int> height) {
        stack<int> stk;
        int maxArea = 0;
        int i = 0;
        while (i < height.size()) {
            if (stk.empty() || height[i] >= height[stk.top()])
                stk.push(i++);
            else {
                int index = stk.top();
                stk.pop();
                maxArea = max(maxArea, height[index] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return maxArea;
    }
};

int main() {
    vector<vector<char>> matrix {{'0','0','1','0'},
                                 {'0','0','0','1'},
                                 {'0','1','1','1'},
                                 {'0','0','1','1'}};
    Solution sol;
    cout << "The matrix is:" << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j)
            cout << matrix[i][j];
        cout << endl;
    }
    cout << "The area of largest rectangle containing all ones is: " << sol.maximalRectangle(matrix) << endl;
}
