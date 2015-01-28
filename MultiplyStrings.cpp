/*
 Author:     physician
 Date:       Jan 28, 2015
 Update:     Jan 28, 2015
 Problem:    Multiply Strings
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/multiply-strings/

 Problem Description:
 Multiply Strings:

 Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.

 Notes:
 1. First implementation, math.
 2. Compile using g++: g++ MultiplyStrings.cpp -o MultiplyStrings.
*/


# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        string result (m+n, '0');
        for (int i = n-1; i >= 0; --i) {
            int carry = 0;
            for (int j = m-1; j >= 0; --j) {
                int sum = carry + (result[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0');
                result[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            result[i] += carry;
        }
        while (result.size() > 1 && result[0] == '0')
            result.erase(result.begin());
        return result;
    }
};

int main() {
    string num1 = "1234";
    string num2 = "567";
    Solution sol;
    cout << num1 << " x " << num2 << " = " << sol.multiply(num1, num2) << endl;
}
