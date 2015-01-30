/*
 Author:     physician
 Date:       Jan 29, 2015
 Update:     Jan 29, 2015
 Problem:    Evaluate Reverse Polish Notation
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

 Problem Description:
 Evaluate Reverse Polish Notation:

 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

 Valid operators are +, -, *, /. Each operand may be an integer or another expression.

 Some examples:
   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

 Notes:
 1. First implementation, stack.
 2. Compile using g++: g++ -std=c++0x EvaluateReversePolishNotation.cpp -o EvaluateReversePolishNotation.
*/


# include <iostream>
# include <string>
# include <vector>
# include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty())
            return 0;
        stack<int> stk;
        for (string token : tokens)
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if (token == "+")
                    stk.push(a + b);
                else if (token == "-")
                    stk.push(a - b);
                else if (token == "*")
                    stk.push(a * b);
                else if (token == "/")
                    stk.push(a / b);
            } else
                stk.push(stoi(token));
        return stk.top();
    }
};

int main() {
    //vector<string> tokens {"2", "1", "+", "3", "*"};
    vector<string> tokens {"4", "13", "5", "/", "+"};
    cout << "Input RPN is: " << endl;
    cout << "[ ";
    for(string c : tokens)
        cout << c << " ";
    cout << "]" << endl;
    Solution sol;
    cout << "Result = " << sol.evalRPN(tokens) << endl;
}
