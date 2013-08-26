/*
 Author:     physician
 Date:       Aug 26, 2013
 Update:     Aug 26, 2013
 Problem:    Pascal's Triangle II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_119

 Problem Description:
 Pascal's Triangle II: 

 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].

 Note:
 Could you optimize your algorithm to use only O(k) extra space?


 Notes:
 1. First implementation, working backwards, adding one element each time.
 2. Compile using g++: g++ PascalsTriangleII.cpp -o PascalsTriangleII.
*/

# include <iostream>
# include <vector>

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for (int i = 0; i <= rowIndex; i++) {
            result.push_back(1);
            for(int j = result.size()-2; j > 0; j--)
                result[j] = result[j] + result[j-1];
        } 
        return result;
    }
};


int main() {
    int n = 0;
    Solution sol;
    vector<int> result = sol.getRow(n);
    cout << "The " << n << " row of Pascal's triangle is:" << endl;
    cout << "[";
    for (int i = 0; i < result.size()-1; i++) 
        cout << result[i] << ",";
    cout << result[result.size()-1] << "]" << endl;
}
