/*
 Author:     physician
 Date:       Aug 30, 2013
 Update:     Aug 30, 2013
 Problem:    Add Binary
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_67

 Problem Description:
 Add Binary:

 Given two binary strings, return their sum (also a binary string).

 For example,
 a = "11"
 b = "1"
 Return "100".

 Notes:
 1. First implementation, natural solution.
 2. Compile using g++: g++ AddBinary.cpp -o AddBinary.
*/


# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            if (a[i] == '0' && b[j] == '0') {
                c.push_back(char(carry + int('0')));
                carry = 0;
            }
            else if (a[i] == '1' && b[j] == '1') {
                c.push_back(char(carry + int('0')));
                carry = 1;
            }
            else {
                if (carry == 0) {
                    c.push_back('1');
                    carry = 0;
                }
                if (carry == 1) {
                    c.push_back('0');
                    carry = 1;
                }
            }
        --i;
        --j;
        }
        while (i >= 0) {
            if (carry == 1) {
                if (a[i] == '0') {
                    c.push_back('1');
                    carry = 0;
                }
                else
                    c.push_back('0');
            }
            else
                c.push_back(a[i]);
            --i;
        }
        while (j >= 0) {
            if (carry == 1) {
                if (b[j] == '0') {
                    c.push_back('1');
                    carry = 0;
                }
                else
                    c.push_back('0');
            }
            else
                c.push_back(b[j]);
            --j;
        }
        if (carry == 1)
            c.push_back('1');
        reverse(c.begin(), c.end());
        return c;
    }
};

int main() {
    Solution sol;
    string s1 = "1";
    string s2 = "111";
    cout << "The sum of " << s1 << " and " << s2 << " is: " << sol.addBinary(s1, s2) << endl;
}
