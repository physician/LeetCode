/*
 Author:     physician
 Date:       Feb 10, 2014
 Update:     Feb 10, 2014
 Problem:    Subsets
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/subsets/

 Problem Description:
 Subsets: 

 Given a set of distinct integers, S, return all possible subsets.

 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,3], a solution is:

 [
   [3],
   [1],
   [2],
   [1,2,3],
   [1,3],
   [2,3],
   [1,2],
   []
 ]

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ Subsets.cpp -o Subsets.
*/

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        return subsets1(S);
    }

private:
    vector<vector<int> > subsets1(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;
        for (int k = 0; k <= S.size(); ++k)
            subsets1Re(S, k, path, result);
        return result;
    }

    void subsets1Re(vector<int> &S, int k, vector<int> &path, vector<vector<int> > &result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int j = 0; j < S.size(); ++j) {
            if (find(path.begin(), path.end(), S[j]) == path.end()) {
                if (path.size() > 0 && S[j] <= path[path.size()-1])
                    continue;
                path.push_back(S[j]);
                subsets1Re(S, k, path, result);
                path.pop_back();
            }
        }
    }
};

int main() {
    int input[] = {1,2,3};
    vector<int> S(input, input + sizeof(input)/sizeof(int));
    Solution sol;
    vector<vector<int> > solVec = sol.subsets(S);
    cout << "[" << endl;
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "  [ ";
        for (int j = 0; j < solVec[i].size(); ++j)
            cout << solVec[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "]" << endl;
}
