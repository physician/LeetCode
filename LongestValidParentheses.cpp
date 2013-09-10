/*
 Author:     physician
 Date:       Sep 10, 2013
 Update:     Sep 10, 2013
 Problem:    Longest Valid Parentheses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_32

 Problem Description:
 Longest Valid Parentheses:

 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 For "(()", the longest valid parentheses substring is "()", which has length = 2.

 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

 Notes:
 1. First implementation, stack. Stack stores the boundaries of valid parentheses in the string.
 2. Compile using g++: g++ LongestValidParentheses.cpp -o LongestValidParentheses.
*/


# include <iostream>
# include <string>
# include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxLen = 0;
        int i = 0;
        stk.push(-1);
        while(i < s.size()) {
            if (s[i] == '(')
                stk.push(i);
            else {
                if (!stk.empty() && s[stk.top()] == '(')
                    stk.pop();
                else
                    stk.push(i);
            }
            ++i;
        }
        int rightEnd = s.size();
        int leftEnd;
        while (!stk.empty()) {
            leftEnd = stk.top();
            maxLen = max(maxLen, rightEnd - leftEnd - 1);
            stk.pop();
            rightEnd = leftEnd;
        }
        return maxLen; 
    }
};

int main() {
    Solution sol;
    string s1 = "(()";
    string s2 = ")()())";
    string s3 = "()(()";
    cout << "The longest valid parentheses for s1 '" << s1 << "' is: " << sol.longestValidParentheses(s1) << endl;
    cout << "The longest valid parentheses for s2 '" << s2 << "' is: " << sol.longestValidParentheses(s2) << endl;
    cout << "The longest valid parentheses for s3 '" << s3 << "' is: " << sol.longestValidParentheses(s3) << endl;
}
