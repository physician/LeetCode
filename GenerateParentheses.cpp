/*
 Author:     physician
 Date:       Jan 06, 2015
 Update:     Jan 06, 2015
 Problem:    Generate Parentheses
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/generate-parentheses/

 Problem Description:
 Generate Parentheses: 

 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 "((()))", "(()())", "(())()", "()(())", "()()()"

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ GenerateParentheses.cpp -o GenerateParentheses.
*/

# include <iostream>
# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        generateParenthesisRe(n, n, "", results);
        return results;
    }

private:
    void generateParenthesisRe(int left, int right, string parentheses, vector<string> &results) {
        if (left == 0 && right == 0)
            results.push_back(parentheses);
        if (left > 0) 
            generateParenthesisRe(left-1, right, parentheses + "(", results);
        if (left < right)
            generateParenthesisRe(left, right-1, parentheses + ")", results);
    }

    /*
    void generateParenthesisRe(int left, int right, string parentheses, vector<string> &results) {
        if (left == 0 && right == 0) {
            results.push_back(parentheses);
            return;
        }
        if (left <= right && left >= 0) {
            generateParenthesisRe(left-1, right, parentheses + "(", results);
            generateParenthesisRe(left, right-1, parentheses + ")", results);
        }
    } */
};


int main() {
    Solution sol;
    int n = 3;
    vector<string> solVec = sol.generateParenthesis(n);
    for (int i = 0; i < solVec.size()-1; ++i)
        cout << solVec[i] << ", ";
    cout << solVec.back() << endl;
}
