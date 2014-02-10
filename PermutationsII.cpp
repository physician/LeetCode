/*
 Author:     physician
 Date:       Feb 10, 2014
 Update:     Feb 10, 2014
 Problem:    Permutations II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/permutations-ii/

 Problem Description:
 Permutations II: 

 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].

 Notes:
 1. First implementation, recursion. DFS. Use unordered_set to avoid duplicates. Time O(n!), space O(n!).
 2. Second implementation, recursion. DFS. Sort to avoid duplicates. Time O(n!), space O(n).
 3. Compile using g++: g++ -std=c++0x PermutationsII.cpp -o PermutationsII.
*/

# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> path;
        vector<int> available(num.size(), 1);
        //dfs(num, path, available, result);
        dfs2(num, path, available, result);
        return result;
    }

private:
    void dfs(vector<int> &num, vector<int> &path, vector<int> &available, vector<vector<int> > &result) {
        if (path.size() == num.size()) {
            result.push_back(path);
            return;
        }
        unordered_set<int> processed;
        for (int i = 0; i < num.size(); ++i) {
            if (available[i] == 1 && processed.find(num[i]) == processed.end()) {
                path.push_back(num[i]);
                available[i] = 0;
                dfs(num, path, available, result);
                path.pop_back();
                available[i] = 1;
                processed.insert(num[i]);
            }
        }
    }

    void dfs2(vector<int> &num, vector<int> &path, vector<int> &available, vector<vector<int> > &result) {
        if (path.size() == num.size()) {
            result.push_back(path);
            return;
        }
        int previousIndex = -1;
        for (int i = 0; i < num.size(); ++i) {
            if (available[i] == 0) continue;
            if (previousIndex != -1 && num[i] == num[previousIndex]) continue;
            path.push_back(num[i]);
            available[i] = 0;
            dfs2(num, path, available, result);
            path.pop_back();
            available[i] = 1;
            previousIndex = i;
        }
    }
};

int main() {
    int input[] = {1,1,2};
    //int input[] = {1,1};
    vector<int> num(input, input + sizeof(input) / sizeof(int));
    Solution sol;
    vector<vector<int> > solVec = sol.permuteUnique(num);
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < solVec[i].size(); ++j)
            cout << solVec[i][j] << " ";
        cout << "]" << endl;
    }
}
