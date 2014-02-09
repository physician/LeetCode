/*
 Author:     physician
 Date:       Feb 08, 2014
 Update:     Feb 08, 2014
 Problem:    Combination Sum II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/combination-sum-ii/

 Problem Description:
 Combination Sum II: 

 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 Each number in C may only be used once in the combination.

 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 A solution set is: 
 [1, 7] 
 [1, 2, 5] 
 [2, 6] 
 [1, 1, 6] 

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ CombinationSumII.cpp -o CombinationSumII.
*/

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        vector<int> path;
        combinationSum2Re(num, target, 0, path, result);
        return result;
    }


    void combinationSum2Re(vector<int> &num, int target, int begin, vector<int> &path, vector<vector<int> > &result) {
        if (target < 0)
            return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = begin; i < num.size(); ++i) {
            path.push_back(num[i]);
            combinationSum2Re(num, target-num[i], i+1, path, result);
            path.pop_back();
            while(num[i+1] == num[i]) i++;
        }
    }
};

int main() {
    int input[] = {10,1,2,7,6,1,5};
    vector<int> num(input, input + sizeof(input) / sizeof(int));
    int target = 8;
    Solution sol;
    vector<vector<int> > solVec = sol.combinationSum2(num, target);
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < solVec[i].size(); ++j)
            cout << solVec[i][j] << " ";
        cout << "]" << endl;
    }
}
