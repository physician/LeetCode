/*
 Author:     physician
 Date:       Aug 19, 2014
 Update:     Aug 19, 2014
 Problem:    Gray Code
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/gray-code/

 Problem Description:
 Gray Code:

 The gray code is a binary numeral system where two successive values differ in only one bit.

 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

 00 - 0
 01 - 1
 11 - 3
 10 - 2
 
 Note:
 For a given n, a gray code sequence is not uniquely defined.

 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

 Notes:
 1. First implementation, recursion.
 2. Second implementation, iteration.
 3. Third implementation, XOR.
    http://www.matrix67.com/blog/archives/266
    ith Gray Code = i XOR (i >> 1)
 4. Compile using g++: g++ GrayCode.cpp -o GrayCode.
*/


# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        return grayCode1(n);
    }

    vector<int> grayCode1(int n) {
        vector<int> code(1, 0);
        if (n == 0)
            return code;
        if (n == 1) {
            code.push_back(1);
            return code;
        }
        code = grayCode(n-1);
        for (int i = code.size()-1; i >= 0; --i)
            code.push_back(code[i] + (1 << (n-1)));
        return code;
    }

    vector<int> grayCode2(int n) {
        vector<int> code(1, 0);
        if (n == 0)
            return code;
        code.push_back(1);
        for (int i = 1; i < n; ++i) {
            vector<int> newCode;
            newCode.insert(newCode.begin(), code.begin(), code.end());
            for (int j = code.size()-1; j >= 0; --j) 
                newCode.push_back(code[j] + (1 << i));
            code = newCode;
        }
        return code;
    }

    vector<int> grayCode3(int n) {
        vector<int> code(1 << n, 0);
        for (int i = 0; i < 1 << n; ++i)
            code[i] = (i >> 1) ^ i;
        return code;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<int> code1 = sol.grayCode1(n);
    cout << "The Gray Code for n = " << n << ", recursion:" << endl;
    for(int i = 0; i < (1 << n); ++i)
        cout << code1[i] << " ";
    cout << endl;
    vector<int> code2 = sol.grayCode2(n);
    cout << "The Gray Code for n = " << n << ", iteration:" << endl;
    for(int i = 0; i < (1 << n); ++i)
        cout << code2[i] << " ";
    cout << endl;
    vector<int> code3 = sol.grayCode3(n);
    cout << "The Gray Code for n = " << n << ", XOR:" << endl;
    for(int i = 0; i < (1 << n); ++i)
        cout << code3[i] << " ";
    cout << endl;
}
