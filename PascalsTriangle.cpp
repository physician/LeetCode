/*
 Author:     physician
 Date:       Aug 26, 2013
 Update:     Aug 26, 2013
 Problem:    Pascal's Triangle
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_118

 Problem Description:
 Pascal's Triangle: 

 Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return

 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
 ]


 Notes:
 1. First implementation, natural solution.
 2. Compile using g++: g++ PascalsTriangle.cpp -o PascalsTriangle.
*/

# include <iostream>
# include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows <= 0)
            return result;
        vector<int> row1;
        row1.push_back(1);
        result.push_back(row1);
        if (numRows == 1)
            return result;
        int i = 1;
        while(i < numRows) {
            vector<int> row;
            row.push_back(result[i-1][0]);
            int j = 0;
            while(j+1 < result[i-1].size()) {
                row.push_back(result[i-1][j] + result[i-1][j+1]);
                j++;
            }
            row.push_back(result[i-1][j]);
            result.push_back(row);
            i++;
        }
        return result;
    }
};


int main() {
    int n = 5;
    Solution sol;
    vector<vector<int> > result = sol.generate(n);
    cout << "The first " << n << " row of Pascal's triangle is:" << endl;
    cout << "[" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int k = 0; k < n-i-1; k++)
        cout << " ";
        cout << "  [" << result[i][0];
        for (int j = 1; j < result[i].size(); j++) {
            cout << "," << result[i][j];
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}
