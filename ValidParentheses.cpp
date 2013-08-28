/*
 Author:     physician
 Date:       Aug 28, 2013
 Update:     Aug 28, 2013
 Problem:    Valid Parentheses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_20

 Problem Description:
 Valid Parentheses:

 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

 Notes:
 1. First implementation, stack.
 2. Write simple and succinct code. Simplify logic.
 3. Compile using g++: g++ ValidParentheses.cpp -o ValidParentheses.
*/


# include <iostream>
# include <string>
# include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i = 0;
        while(i < s.size()) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            else if (s[i] == ')') {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    return false;
            }
            else if (s[i] == '}') {
                if (!stk.empty() && stk.top() == '{')
                    stk.pop();
                else
                    return false;
            }
            else if (s[i] == ']') {
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else
                    return false;
            }
            i++;
        }
        return stk.empty(); 
    }
};

int main() {
    Solution sol;
    string s1 = "[{{}}[(())]]";
    string s2 = "[])";
    if(sol.isValid(s1))
        cout << "Parentheses string s1 " << s1 << " is valid." << endl;
    else
        cout << "Parentheses string s1 " << s1 << " is NOT valid." << endl;
    if(sol.isValid(s2))
        cout << "Parentheses string s2 " << s2 << " is valid." << endl;
    else
        cout << "Parentheses string s2 " << s2 << " is NOT valid." << endl;

}
