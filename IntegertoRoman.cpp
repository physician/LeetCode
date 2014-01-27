/*
 Author:     physician
 Date:       Jan 27, 2014
 Update:     Jan 27, 2014
 Problem:    Integer to Roman
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/integer-to-roman/

 Problem Description:
 Integer to Roman:

 Given an integer, convert it to a roman numeral.

 Input is guaranteed to be within the range from 1 to 3999.

 Notes:
 1. First implementation, unordered_map.
 2. Compile using g++: g++ -std=c++0x IntegertoRoman.cpp -o IntegertoRoman.
*/


# include <iostream>
# include <string>
# include <cmath>
# include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string romanNum;
        unordered_map<int, string> roman = {
            {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, 
            {100, "C"}, {500, "D"}, {1000, "M"}
        };
        for(int i = 3; i >= 0; --i) {
            int n = num/pow(10, i);
            num = num - n * pow(10, i);
            if (n >= 1 && n <= 3) {
                for(int j = 1; j <= n; ++j)
                    romanNum += roman[pow(10, i)];
            }
            else if (n == 4) {
                romanNum += roman[pow(10, i)];
                romanNum += roman[5*pow(10, i)];
            }
            else if (n == 5) {
                romanNum += roman[5*pow(10, i)];
            }
            else if (n >= 6 && n <= 8) {
                romanNum += roman[5*pow(10, i)];
                for(int j = 1; j <= n-5; ++j)
                    romanNum += roman[pow(10, i)];
            }
            else if (n == 9) {
                romanNum += roman[pow(10, i)];
                romanNum += roman[pow(10, i+1)];
            }
        }
        return romanNum;
    }
};

int main() {
    int num = 3548;
    Solution sol;
    cout << "The Roman for " << num << " is " << sol.intToRoman(num) << endl;
}
