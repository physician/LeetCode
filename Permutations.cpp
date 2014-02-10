/*
 Author:     physician
 Date:       Feb 09, 2014
 Update:     Feb 09, 2014
 Problem:    Permutations
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/permutations/

 Problem Description:
 Permutations: 

 Given a collection of numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 Notes:
 1. First implementation, recursion. DFS. Time O(n!), space O(n).
 2. Compile using g++: g++ Permutations.cpp -o Permutations.
*/

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> path;
        dfs(num, path, result);
        return result;
    }

private:
    void dfs(vector<int> &num, vector<int> &path, vector<vector<int> > &result) {
        if (path.size() == num.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (find(path.begin(), path.end(), num[i]) == path.end()) {
                path.push_back(num[i]);
                dfs(num, path, result);
                path.pop_back();
            }
        }
    }
};

int main() {
    int input[] = {1,2,3};
    vector<int> num(input, input + sizeof(input) / sizeof(int));
    Solution sol;
    vector<vector<int> > solVec = sol.permute(num);
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < solVec[i].size(); ++j)
            cout << solVec[i][j] << " ";
        cout << "]" << endl;
    }
}
