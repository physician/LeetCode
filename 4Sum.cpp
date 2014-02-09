/*
 Author:     physician
 Date:       Feb 08, 2014
 Update:     Feb 08, 2014
 Problem:    4Sum
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/4sum/

 Problem Description:
 4Sum: 

 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 The solution set must not contain duplicate quadruplets.
 For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

 A solution set is:
 (-1,  0, 0, 1)
 (-2, -1, 1, 2)
 (-2,  0, 0, 2)

 Notes:
 1. First implementation, use two pointers. Time O(n^3), space O(1).
 2. Compile using g++: g++ -std=c++0x 4Sum.cpp -o 4Sum.
*/

# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        int N = num.size();
        if (N < 4)
            return result;
        sort(num.begin(), num.end());
        for(int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                int remain = target - num[i] - num[j];
                int l = j+1;
                int r = N-1;
                while(l < r) {
                    if(num[l] + num[r] < remain) l++;
                    else if(num[l] + num[r] > remain) r--;
                    else {
                        vector<int> quad;
                        quad.push_back(num[i]);
                        quad.push_back(num[j]);
                        quad.push_back(num[l]);
                        quad.push_back(num[r]);
                        result.push_back(quad);
                        l++;
                        r--;
                        while(l < r && num[l] == num[l-1]) l++; // avoid duplicates in l
                        while(l < r && num[r] == num[r+1]) r--; // avoid duplicates in r
                    }
                }
                while(j+1 < N && num[j+1] == num[j]) j++; // avoid duplicates in j
            }
            while(i+1 < N && num[i+1] == num[i]) i++; // avoid duplicates in i
        }
        return result;
    }
};

int main() {
    int input[] = {1, 0, -1, 0, -2, 2};
    vector<int> num(input, input + sizeof(input) / sizeof(int));
    int target = 0;
    Solution sol;
    vector<vector<int> > solVec = sol.fourSum(num, target);
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "( ";
        for (int j = 0; j < solVec[i].size(); ++j)
            cout << solVec[i][j] << " ";
        cout << ")" << endl;
    }
}
