/*
 Author:     physician
 Date:       Feb 10, 2014
 Update:     Feb 11, 2014
 Problem:    Subsets II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/subsets-ii/

 Problem Description:
 Subsets II: 

 Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,2], a solution is:

 [
   [2],
   [1],
   [1,2,2],
   [2,2],
   [1,2],
   []
 ]

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ SubsetsII.cpp -o SubsetsII.
*/

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        return subsetsWithDup2(S);
    }

private:
    vector<vector<int> > subsetsWithDup1(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;
        vector<int> available(S.size(), 1);
        for (int k = 0; k <= S.size(); ++k)
            subsetsWithDup1Re(S, k, path, available, result);
        return result;
    }

    void subsetsWithDup1Re(vector<int> &S, int k, vector<int> &path, vector<int> &available, vector<vector<int> > &result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int j = 0; j < S.size(); ++j) {
            if (available[j] == 1) {
                if (path.size() > 0 && S[j] < path[path.size()-1])
                    continue;
                path.push_back(S[j]);
                available[j] = 0;
                subsetsWithDup1Re(S, k, path, available, result);
                path.pop_back();
                available[j] = 1;
                while(j < S.size() && S[j+1] == S[j])  // avoid duplicates
                    j++;
            }
        }
    }

    vector<vector<int> > subsetsWithDup2(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;
        subsetsWithDup2Re(S, 0, path, result);
        return result;
    }

    void subsetsWithDup2Re(vector<int> &S, int k, vector<int> &path, vector<vector<int> > &result) {
        result.push_back(path);
        for (int j = k; j < S.size(); ++j) {
            path.push_back(S[j]);
            subsetsWithDup2Re(S, j+1, path, result);
            path.pop_back();
            while(j < S.size() && S[j+1] == S[j])  // avoid duplicates
                j++;
        }
    }

};

int main() {
    int input[] = {1,2,2};
    vector<int> S(input, input + sizeof(input)/sizeof(int));
    Solution sol;
    vector<vector<int> > solVec = sol.subsetsWithDup(S);
    cout << "[" << endl;
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "  [ ";
        for (int j = 0; j < solVec[i].size(); ++j)
            cout << solVec[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "]" << endl;
}
