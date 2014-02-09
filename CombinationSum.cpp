/*
 Author:     physician
 Date:       Feb 08, 2014
 Update:     Feb 08, 2014
 Problem:    Combination Sum
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/combination-sum/

 Problem Description:
 Combination Sum: 

 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 The same repeated number may be chosen from C unlimited number of times.

 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7, 
 A solution set is: 
 [7] 
 [2, 2, 3] 

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ CombinationSum.cpp -o CombinationSum.
*/

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        combinationSumRe(candidates, target, 0, path, result);
        return result;
    }


    void combinationSumRe(vector<int> &candidates, int target, int begin, vector<int> &path, vector<vector<int> > &result) {
        if (target < 0)
            return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = begin; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            combinationSumRe(candidates, target-candidates[i], i, path, result);
            path.pop_back();
        }
    }
};

int main() {
    int input[] = {2,3,6,7};
    vector<int> candidates(input, input + sizeof(input) / sizeof(int));
    int target = 7;
    Solution sol;
    vector<vector<int> > solVec = sol.combinationSum(candidates, target);
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < solVec[i].size(); ++j)
            cout << solVec[i][j] << " ";
        cout << "]" << endl;
    }
}
