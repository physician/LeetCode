/*
 Author:     physician
 Date:       Jan 25, 2014
 Update:     Jan 25, 2014
 Problem:    Longest Common Prefix
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/longest-common-prefix/

 Problem Description:
 Longest Common Prefix:

 Write a function to find the longest common prefix string amongst an array of strings.

 Notes:
 1. First implementation, natural solution.
 2. Compile using g++: g++ LongestCommonPrefix.cpp -o LongestCommonPrefix.
*/


# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        int k = 0;
        bool same = true;
        while(same) {
            for(int i = 1; i < strs.size(); ++i) {
                if(strs[i][k] != strs[0][k]) {
                    same = false;
                    break;
                }
            }
            if(same)
                ++k;
            else
                return strs[0].substr(0, k);
        }
    }
};

int main() {
    vector<string> strs;
    strs.push_back("str");
    strs.push_back("string");
    strs.push_back("street");
    strs.push_back("strong");
    vector<string> emptyStrs;
    vector<string> singleStr;
    singleStr.push_back("empty");
    Solution sol;
    cout << "The longest common prefix is: " << sol.longestCommonPrefix(strs) << endl;
}
