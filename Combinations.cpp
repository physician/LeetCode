/*
 Author:     physician
 Date:       Feb 12, 2014
 Update:     Feb 12, 2014
 Problem:    Combinations
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/combinations/

 Problem Description:
 Combinations: 

 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

 For example,
 If n = 4 and k = 2, a solution is:

 [
   [2,4],
   [3,4],
   [2,3],
   [1,2],
   [1,3],
   [1,4],
 ]

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ Combinations.cpp -o Combinations.
*/

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        return combine1(n, k);
    }

private:
    vector<vector<int> > combine1(int n, int k) {
        vector<vector<int> > result;
        vector<int> path;
        combine1Re(n, k, 1, path, result);      
        return result;
    }

    void combine1Re(int n, int k, int begin, vector<int> &path, vector<vector<int> > &result) {
        int m = path.size();
        if (m == k) {
            result.push_back(path);
            return;
        }
        for (int i = begin; i <= n-(k-m)+1; ++i) {
            path.push_back(i);
            combine1Re(n, k, i+1, path, result);
            path.pop_back();
        }
    }
};

int main() {
    int n = 4;
    int k = 2;
    Solution sol;
    vector<vector<int> > solVec = sol.combine(n, k);
    cout << "[" << endl;
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "  [ ";
        for (int j = 0; j < solVec[i].size(); ++j)
            cout << solVec[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "]" << endl;
}
